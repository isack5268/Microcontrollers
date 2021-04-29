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

String received;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  mqtt_client.setServer(mqtt_server, mqtt_port);
  mqtt_client.setCallback(callback);
 
  while (!mqtt_client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (mqtt_client.connect("ESP8266Client", mqtt_user, mqtt_pass )) {
      Serial.println("connected");  
    } 
    else {
      Serial.print(" failed with state ");
      Serial.print(mqtt_client.state());
      delay(2000);
    }
  }
 
  mqtt_client.subscribe("esp/test");
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  payload[length] = '\0';
  String str_topic = String(topic);
  String str_payload = String((char*)payload);
  Serial.println("Payload: " + String(str_payload));

  StaticJsonBuffer<300> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(str_payload);
  
  if (!root.success()) {
    Serial.println(("Parsing failed!"));
    return;
  }
  
  received = root["device"].as<String>();
  jsonBuffer.clear();
}

void loop() {
  mqtt_client.loop();
  Serial.println("Decripted message: " + String(received));
  delay(1000);
}
