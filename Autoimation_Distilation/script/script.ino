#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <microDS18B20.h>
#include <index.h>

uint8_t s1_addr[] = {0x28, 0x5D, 0x1E, 0x87, 0x0, 0x0, 0x0, 0xFB};
uint8_t s2_addr[] = {0x28, 0xF3, 0xCB, 0x86, 0x0, 0x0, 0x0, 0xB7};

MicroDS18B20<12, s1_addr> sensor1; //{0x28, 0x5D, 0x1E, 0x87, 0x0, 0x0, 0x0, 0xFB}
MicroDS18B20<12, s2_addr> sensor2; //{0x28, 0xF3, 0xCB, 0x86, 0x0, 0x0, 0x0, 0xB7}

WiFiClient client;
const char* ssid = "Pancake";
const char* pass = "Isack5268"; 

ESP8266WebServer server(80);

bool term_wait = true, alert = false;
int term_delay, lastUpdate;
float term1, term2, melody_cuba = 98, melody_para = 77, error = 0.55;

const int speakerPin = 16; // Пин для динамика

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");  
  }
  Serial.println("WiFi Connected"); 
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    server.send(200, "text/html", webpage); 
  });

  server.on("/getTime", []() {
    String timeString = "Время работы: " + String(int(millis() / 1000 / 60)) + " мин";
    server.send(200, "text/plain", timeString);
  });

  server.on("/getTerm1", []() {
    String term1String = "T в кубе: " + String(term2) + "°С";
    server.send(200, "text/plain", term1String);
  });

  server.on("/getTerm2", []() {
    String term2String = "T сверху: " + String(term1) + "°С";
    server.send(200, "text/plain", term2String);
  });

  server.on("/setSignalization", []() {
    melody_cuba = server.arg("value").toFloat();
    server.send(200, "text/plain", "Значение сигнализации получено");
  });

  server.on("/setSignalizationPara", []() {
    melody_para = server.arg("value").toFloat();
    server.send(200, "text/plain", "Значение погрешности получено");
  });

  server.on("/setError", []() {
    error = server.arg("value").toFloat();
    server.send(200, "text/plain", "Значение погрешности получено");
  });

  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("HTTP server started");

  ArduinoOTA.setPassword("admin");
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else {  // U_FS
      type = "filesystem";
    }

    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();

  pinMode(speakerPin, OUTPUT);
}

void loop() {
  ArduinoOTA.handle();
  server.handleClient();

  if (term_wait)
    Term_Check();

  if(millis() - lastUpdate >= 3600000){
    lastUpdate = millis();
    tone(speakerPin, 100, 3000);
  }

  if (!alert && term2 > 65){
    tone(speakerPin, 1, 5000);
    alert = true;
  }

  if (term_delay + 1000 <= millis()){
    term1 = sensor1.getTemp() + error;
    term2 = sensor2.getTemp() + error;
    if (term2 >= melody_cuba)
      tone(speakerPin, 1, 1000);
    if (term1 >= melody_para)
      tone(speakerPin, 1, 1000);
    term_wait = true;
  }
}

void Term_Check(){
  sensor1.requestTemp();
  sensor2.requestTemp();
  term_delay = millis();
  term_wait = false;
} // сбор данных с датчиков температуры

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}