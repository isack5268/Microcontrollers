#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#define rele_pin 4
#define pyro_pin 12

char ssid[] = "ssid";        
char pass[] = "pass";   
//const float longitude = 37.61;
//const float latitude = 55.75;
unsigned int timer;

void setup() {
  Serial.begin(115200);
  pinMode(rele_pin, OUTPUT);
  pinMode(pyro_pin, INPUT);
  digitalWrite(rele_pin, LOW);

 WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  
  Serial.println("WiFi Connected"); 

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_FS
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
  Serial.println(WiFi.localIP());
}

void loop() {
  ArduinoOTA.handle();
  
  if(digitalRead(pyro_pin) == 1){
    Serial.println("1");
    timer = millis();
    digitalWrite(rele_pin, HIGH);
  }

  if(millis() == timer + 60000){
    Serial.println("2");
    timer = 0;
    digitalWrite(rele_pin, LOW);
  }

  //delay(1000);
}
