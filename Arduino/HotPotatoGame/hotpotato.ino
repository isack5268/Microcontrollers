#include <SPI.h>
#include <SD.h>

int soundPin = 9;
int dataPin = 4;
bool check1 = false;
bool check2 = false;
bool check3 = false;
File file;

void setup() {
  pinMode (soundPin, OUTPUT);
  pinMode(10, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
  InitializeSd();
}

void loop() {
  bool but1 = digitalRead(A2);
  bool but2 = digitalRead(A3);
  bool but3 = digitalRead(A4);

  if(but1 && !check1){
    check1 = true;
    Serial.println(Read(random(80)));
    analogWrite (soundPin, 200);
    delay (30);
    analogWrite (soundPin, 0);
  }
  else if(!but1) check1 = false;

  if(but2 && !check2){
    check2 = true;
    
    analogWrite (soundPin, 200);
    delay (30);
    analogWrite (soundPin, 0);
  }
  else if(!but2) check2 = false;

  if(but3 && !check3){
    check3 = true;
    Serial.println("Work");
    analogWrite (soundPin, 200);
    delay (30);
    analogWrite (soundPin, 0);
  }
  else if(!but3) check3 = false;
}

String utf8rus(String source){
  int i,k;
  String target;
  unsigned char n;
  char m[2] = { '0', '\0' };

  k = source.length(); i = 0;

  while (i < k) {
    n = source[i]; i++;

    if (n >= 0xC0) {
      switch (n) {
        case 0xD0: {
          n = source[i]; i++;
          if (n == 0x81) { n = 0xA8; break; }
          if (n >= 0x90 && n <= 0xBF) n = n + 0x30;
          break;
        }
        case 0xD1: {
          n = source[i]; i++;
          if (n == 0x91) { n = 0xB8; break; }
          if (n >= 0x80 && n <= 0x8F) n = n + 0x70;
          break;
        }
      }
    }
    m[0] = n; target = target + String(m);
  }
return target;
}

String Read(int num){ 
  InitializeSd();
  String post = "";
  char sym;
  int i = 0;
  OpenFile();
  file.seek(0);

  while(file.available()){
    sym = file.read();

    if(sym == '\n' && num == i){
      CloseFile();
      return utf8rus(post);
    } else if(sym == '\n'){
      i++;
      post = "";
    }
    else post += sym;
  }
}

void InitializeSd(){
  Serial.println("Initializing SD card...");

  while (!SD.begin(dataPin)) {
    Serial.println("Card failed, or not present");
    delay(1000);
  }
  
  Serial.println("Card initialized!");
}

void OpenFile(){
  file = SD.open("13371.txt", FILE_WRITE);

  if (!file){
    Serial.println("Could not open sensor file!");
    while(1); 
  } else Serial.println("Sensor file is open!");
}

void CloseFile(){
  if(file){
    file.close();
    Serial.println("File closed");
  }
}
