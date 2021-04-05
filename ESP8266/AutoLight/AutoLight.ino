#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
//#include <WiFiClient.h>

#define rele_pin 4
#define pyro_pin 12

//char ssid[] = "";        
//char pass[] = "REPLACE_WITH_YOUR_PASSWORD";   
 
//WiFiClient client;
 
//const char server[] = "api.openweathermap.org";
//String nameOfCity = "Moscow,RU"; 
//String apiKey = "480b9abf344424c67d6ff71e32034609"; 

unsigned int timer;

void setup() {
  Serial.begin(115200);
  pinMode(rele_pin, OUTPUT);
  pinMode(pyro_pin, INPUT);
  digitalWrite(rele_pin, LOW);

  /*WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("WiFi Connected");
  */
}

void loop() {
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
}
