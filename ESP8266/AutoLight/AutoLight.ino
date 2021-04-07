#include <ArduinoJson.h>
#include <ESP8266WiFi.h>

#define rele_pin 4
#define pyro_pin 12

TimeLord lord;
char ssid[] = "none";        
char pass[] = "none";   
const float longitude = 37.61;
const float latitude = 55.75;
unsigned int timer;

void setup() {
  Serial.begin(115200);
  //pinMode(rele_pin, OUTPUT);
  //pinMode(pyro_pin, INPUT);
  //digitalWrite(rele_pin, LOW);
  lord.TimeZone(-5 * 60);
  lord.Position(26.9, -81.8);
  lord.GMT(nowTime);

 WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  
  Serial.println("WiFi Connected"); 
}

void loop() {
  
  /*if(lord.SunSet(nowTime)){
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
  }*/

  delay(1000);
}
