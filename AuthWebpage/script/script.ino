#include <AuthWebpage.h>

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // Инициализация EEPROM
  EEPROM.begin(512);

  // Загрузка сохраненных настроек сети Wi-Fi
  loadConfig();

  if (ssid.isEmpty() || password.isEmpty()) {
    // Если настроек нет, запускаем точку доступа
    digitalWrite(ledPin, LOW);
    startAP();
  } else {
    // Если настройки есть, пробуем подключиться к сети
    connectToWiFi();
  }
}

void loop() {
  server.handleClient();
}