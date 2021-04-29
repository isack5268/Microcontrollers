#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "ArduinoJson.h" 

const char *ssid = "MGTS_GPON_CE9C";
const char *pass = "KTQJ4JEG";
const char *mqtt_server = "M5.WQTT.RU";
const int mqtt_port = 2806;
const char *mqtt_user = "u_P82CIX";
const char *mqtt_pass = "9aDyVbJS";

WiFiClient esp_client;
PubSubClient mqtt_client(esp_client);

String mail;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  mqtt_client.setServer(mqtt_server, mqtt_port);
  //mqtt_client.setCallback(callback);
 
  while (!mqtt_client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (mqtt_client.connect("ESP8266Client", mqtt_user, mqtt_pass )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print(" failed with state ");
      Serial.print(mqtt_client.state());
      delay(2000);
 
    }
  }
}

void loop() {
  StaticJsonBuffer<300> JSONbuffer;
  JsonObject& JSONencoder = JSONbuffer.createObject();
 
  JSONencoder["device"] = "ESP8266";
  
  char JSONmessageBuffer[100];
  JSONencoder.printTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
  Serial.println("Sending message to MQTT topic..");
  Serial.println(JSONmessageBuffer);
 
  if (mqtt_client.publish("esp/test", JSONmessageBuffer) == true) {
    Serial.println("Success sending message");
  } else {
    Serial.println("Error sending message");
  }
  
  delay(1000);
}
