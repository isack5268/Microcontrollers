#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);                                                                                                                                  

#define logo_width 40
#define logo_height 40
static const unsigned char PROGMEM logo[] = {
  0xFF, 0xF7, 0x0F, 0xFF, 0x9F, 0xFF, 0xFF, 0x01, 0xF8, 0x8F, 0xFF, 0x07, 
  0x00, 0xF0, 0x8F, 0xFF, 0x03, 0xF0, 0xE0, 0xDF, 0xFF, 0x00, 0x80, 0x03, 
  0xFF, 0x3F, 0x30, 0x84, 0x03, 0xFE, 0x1F, 0x1C, 0xFC, 0x03, 0xFC, 0x0F, 
  0x0F, 0x3C, 0x03, 0xF8, 0x86, 0x87, 0x3C, 0x13, 0xF0, 0xC4, 0xC7, 0x3F, 
  0x33, 0xF0, 0xC0, 0xC7, 0x3F, 0x3E, 0xF0, 0xE0, 0x87, 0x3F, 0x0E, 0xF2, 
  0xC6, 0x0F, 0xFE, 0x03, 0xF1, 0xC7, 0x0F, 0x80, 0x83, 0xF1, 0x87, 0x3F, 
  0x00, 0xC3, 0xE0, 0x07, 0xFE, 0x01, 0x43, 0xE0, 0x07, 0xF8, 0x1F, 0x06, 
  0xF0, 0x07, 0xC0, 0x3F, 0x06, 0xF0, 0x07, 0x00, 0x00, 0x0C, 0xF0, 0x07, 
  0x00, 0x00, 0x0C, 0xF0, 0x07, 0xC0, 0x00, 0x0C, 0xF0, 0x07, 0x00, 0x00, 
  0x0C, 0xF0, 0x07, 0x04, 0x00, 0x0C, 0xF0, 0x07, 0xE0, 0x41, 0x0C, 0xF0, 
  0x07, 0x00, 0x00, 0x0C, 0xF0, 0x07, 0x04, 0x00, 0x04, 0xF0, 0x07, 0x60, 
  0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x20, 
  0xF0, 0x07, 0x70, 0x00, 0x06, 0xF0, 0x07, 0x00, 0x3E, 0x00, 0xE0, 0x07, 
  0x02, 0x00, 0x00, 0xF0, 0x07, 0x18, 0x00, 0x0C, 0xF0, 0x0F, 0x80, 0xFF, 
  0x00, 0xF0, 0x0F, 0x00, 0x00, 0x40, 0x78, 0x1F, 0x08, 0x00, 0x08, 0xFC, 
  0x79, 0x40, 0xF9, 0x01, 0xBE, 0xF8, 0x00, 0x00, 0x80, 0x1F, 0xF0, 0x07, 
  0x00, 0xF0, 0xE7, 0xF0, 0xFF, 0x80, 0xFF, 0xE7, };

String words[] = {"Памперс", "Киллер", "Ассасин", "Майнкрафт", "Кондиционер", "Мама", "Бомж", "Дебил", "Карл", "Фетиш", "Игрушка", "Скрипка", "Баян", "Водка", "Пиво", "Колесо", "Машина", "Кружка", "Рот", "Батарейка"};
const int wordsSize = sizeof(words) / sizeof(String);
int soundPin = 13, rung = 0;
bool check1 = false;

void setup() {
  pinMode (soundPin, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12,HIGH);
  randomSeed(analogRead(0));
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay(); 
  display.cp437(true);
  delay(2000);
  display.drawXBitmap(128 / 2 - logo_width / 2, 0, logo, logo_width, logo_height, 1);
  display.display();
  display.setTextSize(1,2);
  display.setTextColor(WHITE);
  display.setCursor(25, 45);
  display.write(80); //P
  display.write(97); //a
  display.write(110); //n
  display.write(99); //c
  display.write(97); //a
  display.write(107); //k
  display.write(101); //e
  display.write(70); //F
  display.write(97); //a
  display.write(99); //c
  display.write(101); //e
  display.write(115); //s
  display.display();
  delay(3000);
  display.clearDisplay();
  display.setTextSize(1,2);             
  display.setTextColor(WHITE); 
  display.drawRoundRect (1, 1, 127, 63, 5, 1);       
  display.setCursor(15,15);             
  display.println(utf8rus("Добро пожаловать"));
  display.setCursor(47,35);
  display.println(utf8rus("мастер!"));
  display.display();
  Random();
  delay(2000);
}

void loop() {
  bool but1 = digitalRead(12);

  if(rung >= wordsSize){
    Serial.println("Over");
    rung = 1;
    Random();
  }

  if(!but1 && !check1){
    check1 = true;
    Serial.println(wordsSize);
    Output(rung);
    rung++;
    tone (soundPin, 600, 200);
  }
  else if(but1) 
    check1 = false;
}

void Output(int num){ 
  display.clearDisplay();
  display.setTextSize(1.5);             
  display.setTextColor(WHITE);        
  display.setCursor(0, 32);
  display.println(utf8rus(words[num]));
  display.display();;
}

void Random(){
  for (int i = 0; i < wordsSize; i++){
    int j = random(0, wordsSize - i);
    String t = words[i];
    
    words[i] = words[j];
    words[j] = t;
  }
}

/*int SpaceEnum(){
  int spaces = 0;
  
  for(int i = 0; i < wordsSize; i++){
    if(words[i] == ' ')
      spaces++;
  }
  return spaces;
}*/

String utf8rus(String source)
{
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
