#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <NTPClient.h>


#define rele_pin 4
#define pyro_pin 12

WiFiClient client;

const char* ssid = "ssid";        
const char* pass = "pass";   

const char *host = "http://api.sunrise-sunset.org/json?lat=55.75&lng=37.61";

const unsigned int utcOffsetInSeconds = 10800;
String sunset, sunrise;
unsigned int timer;
bool starting = false;  // если сейчас день выставить fasle, иначе true

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup() {
  Serial.begin(115200);
  pinMode(rele_pin, OUTPUT);
  pinMode(pyro_pin, INPUT);
  digitalWrite(rele_pin, LOW);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");  
  }
  
  Serial.println("WiFi Connected"); 
  timeClient.begin();

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
  timeClient.update();
  Parse();
  int hourSet = 0;
  Serial.println("Realtime: " + (String)timeClient.getFormattedTime());

  if(Minutes(sunset) >= 30)
    hourSet = Hours(sunset) + 1;
  else 
    hourSet = Hours(sunset);

  Serial.println("Hour Set: " + (String)hourSet + ";");

  if(timeClient.getHours() < hourSet && timeClient.getHours() >= Hours(sunrise) + 1)
    starting = false;
  else 
    starting = true;

  if(starting){    
    if(digitalRead(pyro_pin) == 1){
      timer = millis();
      digitalWrite(rele_pin, HIGH);
    }

    if(millis() == timer + 60000){
      timer = 0;
      digitalWrite(rele_pin, LOW);
    }
  }

  Serial.println("Active: " + (String)starting);
}

void Parse(){
  HTTPClient http;
  http.begin(host);
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload from server

  if(httpCode == 200)
  {
    const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
    DynamicJsonBuffer jsonBuffer(capacity);
  
   // Parse JSON object
    JsonObject& root = jsonBuffer.parseObject(payload);
    if (!root.success()) {
      Serial.println(F("Parsing failed!"));
      return;
    }

    sunset = root["results"]["astronomical_twilight_end"].as<String>();
    sunrise = root["results"]["sunrise"].as<String>();
    
    Serial.println("Sunset: " + (String)sunset + "; Sunrise: " + (String)sunrise + ";");
    jsonBuffer.clear();
  }
  else
    Serial.println("Error in response");

  http.end();  //Close connection
}

int Hours(String data){
  int hours = 0;
  
  if(data[8] == 'P')
    hours = data[0] - '0' + 12;
  else
    hours = data[0] - '0';
  
  return hours;
}

int Minutes(String data){
  int minutes = 0;
  minutes = (data[2] - '0') * 10 + data[3] - '0';
  
  return minutes;
}
