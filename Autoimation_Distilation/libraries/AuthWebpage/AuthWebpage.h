const char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang='ru'>
<head>
  <meta http-equiv="Content-type" content="text/html; charset=utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
  <title>Настройка Wi-Fi</title>
  <style>
    html {
      font-family: Helvetica;
      display: inline-block;
      margin: 0px auto;
      text-align: center;
    }

    body {
      margin-top: 50px;
      background: #2f2f2f;
    }

    h1 {
      color: #ffffff;
      margin: 50px auto 30px;
    }

    .settings-block {
      background-color: #333333;
      padding: 20px;
      border-radius: 10px;
      box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
      margin-bottom: 20px;
      width: 600px;
      height: 300px;
      margin: 0 auto;
    }

    .settings-block h1 {
      margin-top: 0;
    }

    .input-container {
      display: flex;
      justify-content: center;
      align-items: center;
      margin-bottom: 20px;
    }

    .input-container input {
      padding: 10px;
      font-size: 20px;
      width: 300px;
      border: 1px solid #cccccc;
      border-radius: 4px;
      margin-right: 10px;
    }

    .button {
      display: inline-block;
      width: 200px;
      background-color: #4CAF50;
      border: none;
      color: white;
      padding: 13px 0;
      text-decoration: none;
      font-size: 25px;
      margin: 20px 0;
      cursor: pointer;
      border-radius: 4px;
    }

    .button:active {
      background-color: #3e8e41;
    }

    @media (max-width: 480px) {
      .input-container {
        flex-direction: column;
      }
      .input-container input {
        margin-bottom: 10px;
      }
      .button {
        width: 100%;
      }
    }
  </style>
</head>

<body>
  <div class="settings-block">
    <h1>Настройка Wi-Fi</h1>
    <div class="input-container">
      <input type="text" id="ssid" placeholder="SSID" required>
    </div>
    <div class="input-container">
      <input type="password" id="password" placeholder="Пароль" required>
    </div>
    <button class="button" onclick="saveSettings()">Сохранить</button>
  </div>

  <script>
    function saveSettings() {
      var ssidValue = document.getElementById('ssid').value;
      var passwordValue = document.getElementById('password').value;

      if (ssidValue !== '' && passwordValue !== '') {
        var xhr = new XMLHttpRequest();
        xhr.open('POST', '/save', true);
        xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
        xhr.send('ssid=' + encodeURIComponent(ssidValue) + '&password=' + encodeURIComponent(passwordValue));
        document.location.href = '/restart';
      } else {
        alert('Пожалуйста, введите имя и пароль сети Wi-Fi.');
      }
    }
  </script>
</body>

</html>
)=====";

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>

// Создаем объект веб-сервера
ESP8266WebServer server(80);

String ssid;
String password;

// Функция для чтения строки из EEPROM
String readStringFromEEPROM(int addr) {
  int len = EEPROM.read(addr);
  char data[len];
  for (int i = 0; i < len; i++) {
    data[i] = EEPROM.read(addr + 1 + i);
  }
  data[len] = '\0';
  return String(data);
}

// Функция для записи строки в EEPROM
void writeStringToEEPROM(int addr, String str) {
  EEPROM.write(addr, str.length());
  for (int i = 0; i < str.length(); i++) {
    EEPROM.write(addr + 1 + i, str[i]);
  }
}

// Функция для загрузки сохраненных настроек сети Wi-Fi
void loadConfig() {
  int addr = 0;
  ssid = readStringFromEEPROM(addr);
  addr += ssid.length() + 1;
  password = readStringFromEEPROM(addr);
}

// Функция для сохранения настроек сети Wi-Fi в EEPROM
void saveConfig() {
  int addr = 0;
  writeStringToEEPROM(addr, ssid);
  addr += ssid.length() + 1;
  writeStringToEEPROM(addr, password);
  EEPROM.commit();
}

// Функция для запуска точки доступа
void startAP() {
  WiFi.softAPConfig(IPAddress(192, 168, 1, 1), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));
  WiFi.softAP("Distilation", "12345678");

  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", webpage); 
  });

  server.on("/save", HTTP_POST, []() {
    ssid = server.arg("ssid");
    password = server.arg("password");
    saveConfig();
    server.send(200, "text/plain", "Настройки сохранены. Перезагрузка...");
    delay(1000);
    ESP.restart();
  });

  server.begin();
}

// Функция для подключения к сети Wi-Fi
void connectToWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());

  int attempt = 0;
  while (WiFi.status() != WL_CONNECTED && attempt < 10) {
    delay(1000);
    Serial.println("Попытка подключения к сети...");
    attempt++;
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Не удалось подключиться к сети. Сброс настроек...");
    ssid = "";
    password = "";
    EEPROM.begin(512);
    EEPROM.write(0, 0); // Очистка EEPROM
    EEPROM.commit();
    delay(1000);
    ESP.restart();
  } else {
    Serial.println("Подключено к сети");
    Serial.println("IP-адрес: ");
    Serial.println(WiFi.localIP());
  }
}