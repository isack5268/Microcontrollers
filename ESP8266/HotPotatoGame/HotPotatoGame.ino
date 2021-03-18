#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266TrueRandom.h>

#define cButton 12 // центральная кнопка

Adafruit_SSD1306 display(128, 64, &Wire, -1); // инициализируем дисплей                                                                                                                              

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
  0x00, 0xF0, 0xE7, 0xF0, 0xFF, 0x80, 0xFF, 0xE7, };  // добавляем лого

 // словарь
String words[] = {"подпись", "вырез", "гранит", "кругозор", "блузка", "фараон", "клапан", "ёж", "вымя", "турист", "колготки", "стоп-кран", "питание", "свёрток", "дочерь", "шампунь", "броня", "зайчатина", "гимназист", "стелька", "подделка", "виза", "затычка", "решение", "алкоголь", "шуруп", "воровка", "колодец", "кабан", "команда", "бордель", "ловушка", "буква", "опера", "сектор", "математика", "пароварка", "невезение", "глубина", "штука", "справочник", "вождь", "хобот", "ширинка", "усталость", "служитель", "жар", "спальная", "видео", "рот", "просьба", "фишка", "рукопись", "ракетчик", "каблук", "шрифт", "палец", "ножка", "халва", "черника", "незнайка", "компания", "работница", "мышь", "исследование", "кружка", "мороженое", "сиденье", "пулемёт", "печь", "солист", "свёкла", "стая", "зелье", "дума", "посылка", "коготь", "семафор", "брат", "различие", "плоскостопие", "двигатель", "сфера", "тюльпан", "затвор", "внедорожник", "самурай", "стан", "алгоритм", "параграф", "глаз", "медалист", "пульт", "поводок", "подлежащее", "ор", "бунт", "удочка", "лес", "диспетчер", "монитор", "вдова", "пиратство", "астролог", "сосед", "пуп", "изобретатель", "чума", "танец", "затишье", "пластелин", "йог", "маска", "блоха", "судьба", "сияние", "рукавица", "филе", "заплыв", "сёмга", "гиппопотам", "мастер", "походка", "ландыш", "яблоня", "кляча", "лиса", "свёртываемость", "раствор", "соты", "солод", "спорт", "шифер", "прощение", "стопка", "побег", "простота", "запах", "беседа", "варенье", "пароль", "актёр", "вырубка", "гвоздь", "шкаф", "скальпель", "гонг", "профессор", "казан", "скорбь", "извоз", "добавка", "тропа", "шеф", "космонавт", "грифель", "лауреат", "ромб", "борец", "звон", "канистра", "олимпиада", "оплата", "спирт", "баян", "перекрёсток", "влажность", "лотерея", "насморк", "оправдание", "мушкетёр", "мороз", "утюг", "санитария", "опрятность"};
unsigned const int wordsSize = sizeof(words) / sizeof(String), soundPin = 13;  // размер словаря
unsigned int rung = 1;
unsigned long startTime = 0;
bool check1 = false, timeGo = false;

void setup() {
  pinMode (soundPin, OUTPUT);
  pinMode(cButton, OUTPUT);
  digitalWrite(cButton,HIGH);
  
  Serial.begin(115200);
  Random(1);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // определяем дисплей по адресу 0x3C
  display.clearDisplay(); 
  display.cp437(true);  // задаем сдвиг под символам на вывод
  display.setTextColor(WHITE); 
  delay(2000);
  
  display.drawXBitmap(128 / 2 - logo_width / 2, 0, logo, logo_width, logo_height, 1);
  display.display();
  display.setTextSize(1,2);
  display.setCursor(25, 45);
  display.write(80);  // P
  display.write(97);  // a
  display.write(110); // n
  display.write(99);  // c
  display.write(97);  // a
  display.write(107); // k
  display.write(101); // e
  display.write(70);  // F
  display.write(97);  // a
  display.write(99);  // c
  display.write(101); // e
  display.write(115); // s
  display.display();
  delay(1500);  
}

void loop() {
  bool but1 = digitalRead(cButton); // читаем состояние кнопки и переводим в булевую

  if(rung = wordsSize){
    Serial.println("Over");
    rung = 1;
    Random(1);
  } // когда мы прошли весь словарь - решафлим его и пускаем заново

  if(timeGo && millis() >= startTime + ESP8266TrueRandom.random(50000, 70000)){
    startTime = 0;
    timeGo = false;
    display.clearDisplay();
    display.drawRoundRect (1, 1, 127, 63, 5, 1);    
    display.setTextSize(2);                  
    display.setCursor(5, 15);
    tone (soundPin, 2000, 200);
    display.println(utf8rus("Раунд"));
    display.setCursor(5, 35);
    display.println(utf8rus("окончен"));
    display.display();;
    delay(1500);
  } // окончание времени на раунд

  if(!but1 && !check1){ // начало раунда по нажатию кнопки
    check1 = true;

    if(!timeGo){
      timeGo = true;
      startTime = millis();
    } // начинаем отсчет
    
    Output(rung);
    rung++;
    tone (soundPin, 600, 200); // пиликаем
  }
  else if(but1)
    check1 = false;
}

String utf8rus(String source){ // перевод латиницы в кириллицу
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

void Output(int num){  // вывод слова на экран
  display.clearDisplay();
  display.drawRoundRect (1, 1, 127, 63, 5, 1);    
  display.setTextSize(2);                  
  display.setCursor(5, 25);
  display.println(utf8rus(words[num]));
  display.display();;
}

void Random(int i){ // шафлим словарь
  switch(i){
    case 1:
      for (int i = 0; i < wordsSize; i++){
        int j = ESP8266TrueRandom.random(0, wordsSize - i);
        String t = words[i];
        words[i] = words[j];
        words[j] = t;
      }
    break;
  }
}



/*void WordsUpdate(){
  String str = "";
  
  if (Serial.available() > 0) {
    str = Serial.readString();
    
  for(int i = 0; i < wordsSize; i++){
    if(words[i] == ' ')
      spaces++;
  }
}*/
