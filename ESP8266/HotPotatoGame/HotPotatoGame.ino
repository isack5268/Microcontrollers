#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266TrueRandom.h>

#define cButton 14  // центральная кнопка
#define soundPin 13  // пин пищалки

Adafruit_SSD1306 display(128, 32, &Wire, -1);  // инициализируем дисплей                                                                                                                              

#define logo_width 20
#define logo_height 20
static const unsigned char PROGMEM logo[] = {
  0x00, 0x0C, 0x00, 0x80, 0x33, 0x00, 0xB0, 0xE7, 0x00, 0xC8, 0xE1, 0x01, 
  0x44, 0x88, 0x02, 0x40, 0x80, 0x02, 0x84, 0xC2, 0x02, 0x0C, 0x6E, 0x03, 
  0x1E, 0xC8, 0x03, 0xFC, 0xDF, 0x03, 0x7C, 0xD8, 0x03, 0x9C, 0xDF, 0x03, 
  0xEC, 0xCF, 0x03, 0x7C, 0xF0, 0x03, 0x1C, 0x9F, 0x03, 0xFE, 0xFB, 0x03, 
  0x3C, 0xCA, 0x03, 0xE8, 0xBF, 0x01, 0x70, 0x60, 0x00, 0x00, 0x1F, 0x00, };  // добавляем лого

 // словарь
String words[] = {"подпись", "вырез", "гранит", "кругозор", "блузка", "фараон", "клапан", "ёж", "вымя", "турист", "колготки", "стоп-кран", "питание", "свёрток", "дочерь", "шампунь", "броня", "зайчатина", "гимназист", "стелька", "подделка", "виза", "затычка", "решение", "алкоголь", "шуруп", "воровка", "колодец", "кабан", "команда", "бордель", "ловушка", "буква", "опера", "сектор", "математика", "пароварка", "невезение", "глубина", "штука", "справочник", "вождь", "хобот", "ширинка", "усталость", "служитель", "жар", "спальная", "видео", "рот", "просьба", "фишка", "рукопись", "ракетчик", "каблук", "шрифт", "палец", "ножка", "халва", "черника", "незнайка", "компания", "работница", "мышь", "исследование", "кружка", "мороженое", "сиденье", "пулемёт", "печь", "солист", "свёкла", "стая", "зелье", "дума", "посылка", "коготь", "семафор", "брат", "различие", "плоскостопие", "двигатель", "сфера", "тюльпан", "затвор", "внедорожник", "самурай", "стан", "алгоритм", "параграф", "глаз", "медалист", "пульт", "поводок", "подлежащее", "ор", "бунт", "удочка", "лес", "диспетчер", "монитор", "вдова", "пиратство", "астролог", "сосед", "пуп", "изобретатель", "чума", "танец", "затишье", "пластелин", "йог", "маска", "блоха", "судьба", "сияние", "рукавица", "филе", "заплыв", "сёмга", "гиппопотам", "мастер", "походка", "ландыш", "яблоня", "кляча", "лиса", "свёртываемость", "раствор", "соты", "солод", "спорт", "шифер", "прощение", "стопка", "побег", "простота", "запах", "беседа", "варенье", "пароль", "актёр", "вырубка", "гвоздь", "шкаф", "скальпель", "гонг", "профессор", "казан", "скорбь", "извоз", "добавка", "тропа", "шеф", "космонавт", "грифель", "лауреат", "ромб", "борец", "звон", "канистра", "олимпиада", "оплата", "спирт", "баян", "перекрёсток", "влажность", "лотерея", "насморк", "оправдание", "мушкетёр", "мороз", "утюг", "санитария", "опрятность"};
unsigned const int wordsSize = sizeof(words) / sizeof(String);  // размер словаря
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
  display.setRotation(2);  // задаем поворот экрана
  display.setTextColor(WHITE); 
  delay(2000);
  
  display.drawXBitmap(128 / 2 - logo_width / 2, 0, logo, logo_width, logo_height, 1);
  display.display();
  display.setTextSize(1);
  display.setCursor(27, 25);
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

  if(timeGo && millis() >= startTime + 60000){
    startTime = 0;
    timeGo = false;
    display.clearDisplay();
    display.drawRoundRect (1, 1, 127, 31, 5, 1);    
    display.setTextSize(1,2);                  
    display.setCursor(25, 10);
    tone (soundPin, 2000, 200);
    display.println(utf8rus("Раунд"));
    display.setCursor(60, 10);
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
  display.drawRoundRect (1, 1, 127, 31, 5, 1);    
  display.setTextSize(1,2);                  
  display.setCursor(15, 10);
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
