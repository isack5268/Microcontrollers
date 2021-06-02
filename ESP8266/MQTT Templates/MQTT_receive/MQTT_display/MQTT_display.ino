#include <Wire.h> 
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <PubSubClient.h>
#include "ArduinoJson.h" 
#include <LiquidCrystal_I2C.h>

const char *ssid = "{{ ssid }}";
const char *pass = "{{ pass }}";
const char *mqtt_server = "{{ ip_mqtt_server }}";
const int mqtt_port = {{ mqtt_port }};
const char *mqtt_user = "{{ mqtt_user }}";
const char *mqtt_pass = "{{ mqtt_password }}";

WiFiClient esp_client;
PubSubClient mqtt_client(esp_client);

LiquidCrystal_I2C lcd(0x27,20,4);  // Устанавливаем дисплей

byte lamp_pic[8] = {
0b00000,
0b01110,
0b10001,
0b10001,
0b10001,
0b01010,
0b01110,
0b01110
};

byte door_pic[8] = {
0b11111,
0b10001,
0b10001,
0b11001,
0b10001,
0b10001,
0b10001,
0b11111
};

byte temp_pic[8] = {
0b00100,
0b01010,
0b01010,
0b01010,
0b10001,
0b11111,
0b11111,
0b01110
};

byte photo_pic[8] = {
0b00000,
0b10101,
0b01110,
0b11111,
0b11111,
0b01110,
0b10101,
0b00000
};

byte pyro_pic[8] = {
0b01110,
0b01110,
0b00000,
0b10001,
0b01110,
0b00000,
0b10001,
0b01110
};

int list = 0;
String pyro, lamp, temp, door, photo; 

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

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
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  mqtt_client.setServer(mqtt_server, mqtt_port);
  mqtt_client.setCallback(callback);
 
  while (!mqtt_client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (mqtt_client.connect("ESP8266_Display", mqtt_user, mqtt_pass )) {
      Serial.println("connected");  
    } 
    else {
      Serial.print(" failed with state ");
      Serial.print(mqtt_client.state());
      delay(2000);
    }
  }
  
  lcd.init();                     
  lcd.backlight();// Включаем подсветку дисплея

  lcd.createChar(1, lamp_pic);
  lcd.createChar(2, door_pic);
  lcd.createChar(3, temp_pic);
  lcd.createChar(4, photo_pic);
  lcd.createChar(5, pyro_pic);

  mqtt_client.subscribe("pacs/door");
  mqtt_client.subscribe("pacs/lamp");
  mqtt_client.subscribe("pacs/photo");
  mqtt_client.subscribe("pacs/pyro");
  mqtt_client.subscribe("pacs/temp");
  Display();
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  payload[length] = '\0';
  String str_payload = String((char*)payload);
  Serial.println("Payload: " + String(str_payload));

  StaticJsonBuffer<300> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(str_payload);
  
  if (!root.success()) {
    Serial.println(("Parsing failed!"));
    return;
  }

  if(String(topic) == "pacs/door"){
    Clear_Disp(0, 3, 0);
    door = root["command"].as<String>();
  }

  if(String(topic) == "pacs/lamp"){
    Clear_Disp(0, 1, 0);
    lamp = root["command"].as<String>();
  }

  if(String(topic) == "pacs/pyro"){
    Clear_Disp(0, 3, 1);
    pyro = root["value"].as<String>();
  }

  if(String(topic) == "pacs/photo"){
    Clear_Disp(10, 3, 0);
    photo = root["value"].as<String>();
  }
  
  if(String(topic) == "pacs/temp"){
    Clear_Disp(10, 1, 0);
    temp = root["value"].as<String>();
  }
  
  jsonBuffer.clear();
  Display();
}

void loop()
{
  ArduinoOTA.handle();
  mqtt_client.loop();
}

void Display(){      
  switch(list){
    case 0:
      lcd.setCursor(0, 0);
      lcd.print(char(1));
      lcd.print(" Lamp");
      lcd.setCursor(1, 1);
      lcd.print(lamp);
      lcd.setCursor(0, 2);
      lcd.print(char(2));
      lcd.print(" Door");
      lcd.setCursor(1, 3);
      lcd.print(door);
      lcd.setCursor(10, 0);
      lcd.print(char(3));
      lcd.print(" Temp.");
      lcd.setCursor(11, 1);
      lcd.print(temp);
      lcd.setCursor(10, 2);
      lcd.print(char(4));
      lcd.print(" Light");
      lcd.setCursor(11, 3);
      lcd.print(photo);
      break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.print(char(5));
      lcd.print(" Motion");
      lcd.setCursor(1, 1);
      lcd.print(pyro);
      break;
  }
}

void Clear_Disp(int x, int y, int list_num){
  if(list_num == list){
    lcd.setCursor(x, y);
    lcd.print("         ");
  }
}
