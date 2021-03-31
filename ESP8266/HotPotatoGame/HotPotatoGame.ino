#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266TrueRandom.h>

#define cButton1 14  // центральная кнопка
#define cButton2  2  // правая кнопка
#define cButton3 12  // левая кнопка
#define soundPin 13  // пин пищалки 13
#define dispPin 15  // пин питания дисплея

Adafruit_SSD1306 display(128, 32, &Wire, -1);  // инициализируем дисплей                                                                                                                              

#define logo_width 20
#define logo_height 20
static const unsigned char PROGMEM logo[] = {
  0x00, 0x0C, 0x00, 0x80, 0x33, 0x00, 0xB0, 0xE7, 0x00, 0xC8, 0xE1, 0x01, 
  0x44, 0x88, 0x02, 0x40, 0x80, 0x02, 0x84, 0xC2, 0x02, 0x0C, 0x6E, 0x03, 
  0x1E, 0xC8, 0x03, 0xFC, 0xDF, 0x03, 0x7C, 0xD8, 0x03, 0x9C, 0xDF, 0x03, 
  0xEC, 0xCF, 0x03, 0x7C, 0xF0, 0x03, 0x1C, 0x9F, 0x03, 0xFE, 0xFB, 0x03, 
  0x3C, 0xCA, 0x03, 0xE8, 0xBF, 0x01, 0x70, 0x60, 0x00, 0x00, 0x1F, 0x00, };  // добавляем лого

unsigned const int startMelody[] = {440, 165, 440, 0, 440, 165, 440, 0, 330, 330, 262, 494, 440, 494, 262, 294, 330, 165, 440, 0};
unsigned const int times1[] = {250, 250, 250, 250, 250, 250, 250, 250, 125, 125, 125, 125, 125, 125, 125, 125, 250, 250, 250, 250};

int  roundMelody[] = {329, 392, 392, 329, 440, 392, 440, 392, 440, 392, 440, 392, 440, 493};
int  durations2[]  = {300, 600, 300, 600, 300, 300, 300, 300, 300, 300, 300, 300, 300, 600 };
int  times2[]  = {200, 800, 200, 800, 200, 200, 200, 200, 200, 200, 200, 200, 200, 500 };

int rightMelody[] = {1318, 1318, 1318, 1046, 1318, 1568, 784, 1046, 784, 659, 880, 987, 932, 880, 784, 1318, 1568, 1750, 1396, 1568, 1318, 1046, 1174, 987, 1046, 784, 659, 880, 987, 932, 880, 784, 1318, 1568, 1750, 1396, 1568, 1318, 1046, 1174, 987, 1568, 1480, 1396, 1244, 1318, 830, 880, 1046, 880, 1046, 1174, 0, 1568, 1480, 1396, 1244, 1318, 2093, 2093, 2093, 1568, 1480, 1396, 1244, 1318, 830, 880, 1046, 880, 1046, 1174, 1244, 1174, 1046};
int duration3[] = {150, 300, 150, 150, 300, 600, 600, 450, 150, 300, 300, 150, 150, 300, 210, 210, 150, 300, 150, 150, 300, 150, 150, 450, 450, 150, 300, 300, 150, 150, 300, 210, 210, 150, 300, 150, 150, 300, 150, 150, 450, 150, 150, 150, 300, 150, 150, 150, 150, 150, 150, 150, 0, 150, 150, 150, 300, 150, 300, 150, 600, 150, 150, 150, 300, 150, 150, 150, 150, 150, 150, 150, 300, 450, 600};
int times3[] = {150, 300, 300, 150, 300, 600, 600, 450, 450, 450, 300, 300, 150, 300, 210,210, 150, 300, 150, 300, 300, 150, 150, 450, 450, 450, 450, 300, 300, 150, 300, 210, 210, 150, 300, 150, 300, 300, 150, 150, 600, 150, 150, 150, 300, 300, 150, 150, 300, 150, 150, 150, 300, 150, 150, 150, 300, 300, 300, 150, 600, 150, 150, 150, 300, 300, 150, 150, 300, 150, 150, 450, 450, 450, 1200};

// словарь
String words[] = {"подпись","вырез","гранит","кругозор","блузка","фараон","клапан","ёж","вымя","турист","колготки","стоп-кран","питание","свёрток","дочерь","шампунь","броня","зайчатина","гимназист","стелька","подделка","виза","затычка","решение","алкоголь","шуруп","воровка","колодец","кабан","команда","бордель","ловушка","буква","опера","сектор","математика","пароварка","невезение","глубина","штука","справочник","вождь","хобот","ширинка","усталость","служитель","жар","спальная","видео","рот","просьба","фишка","рукопись","ракетчик","каблук","шрифт","палец","ножка","халва","черника","незнайка","компания","работница","мышь","исследование","кружка","мороженое","сиденье","пулемёт","печь","солист","свёкла","стая","зелье","дума","посылка","коготь","семафор","брат","различие","плоскостопие","двигатель","сфера","тюльпан","затвор","внедорожник","самурай","стан","алгоритм","параграф","глаз","медалист","пульт","поводок","подлежащее","ор","бунт","удочка","лес","диспетчер","монитор","вдова","пиратство","астролог","сосед","пуп","изобретатель","чума","танец","затишье","пластелин","йог","маска","блоха","судьба","сияние","рукавица","филе","заплыв","сёмга","гиппопотам","мастер","походка","ландыш","яблоня","кляча","лиса","свёртываемость","раствор","соты","солод","спорт","шифер","прощение","стопка","побег","простота","запах","беседа","варенье","пароль","актёр","вырубка","гвоздь","шкаф","скальпель","гонг","профессор","казан","скорбь","извоз","добавка","тропа","шеф","космонавт","грифель","лауреат","ромб","борец","звон","канистра","олимпиада","оплата","спирт","баян","перекрёсток","влажность","лотерея","насморк","оправдание","мушкетёр","мороз","утюг","санитария","опрятность","неряшливость","фляга","приключение","пирс","пион","убыль","путник","ходатайство","шагомер","акушер","палеозой","уведомление","оторва","хамство","хутор","передвижение","киловатт","оксид","навес","напильник","сруб","круиз","узкость","матерщинник","трансплантация","творение","полтинник","астматик","преимущество","митрополит","чужестранец","резиденция","категория","тяжесть","ударник","скептицизм","изверг","физиономия","витрина","самоуничижение","управляющий","кадило","хорист","буйство","ночлег","микроскоп","щипчики","стружка","священнослужитель","сплин","тлен","чужеземец","погремушка","морфий","крепостной","водопровод","бездна","леший","улучшение","самозванец","надзиратель","эшафот","усадьба","возбудитель","канун","вихрь","рецидивист","туберкулёз","признание","карабин","разгром","инцест","гениальность","разделение","виртуоз","брезент","описание","частица","спринтер","прочтение","дисциплина","мякиш","взяточник","множитель","гарантия","контекст","расширитель","самоконтроль","таинство","фальшивомонетчик","канон","объединение","неведение","скважина","политолог","скряга","атрибут","безумие","балаган","искусствовед","самовнушение","аперитив","взаимодействие","успешность","проектировщик","шматок","основатель","свинство"};
unsigned const int wordsSize = sizeof(words) / sizeof(String);  // размер словаря
unsigned int rung = 1, score1 = 0, score2 = 0, rndTime = 0;
unsigned long startTime = 0;
bool check1 = false, timeGo = false, change = false, first = true;

void setup() {
  pinMode (soundPin, OUTPUT);
  pinMode(cButton1, OUTPUT);
  pinMode(cButton1, INPUT_PULLUP);
  digitalWrite(cButton1,HIGH);
  pinMode(cButton2, OUTPUT);
  digitalWrite(cButton2,HIGH);
  pinMode(cButton3, OUTPUT);
  digitalWrite(cButton3,HIGH);
  pinMode(dispPin, OUTPUT);
  digitalWrite(dispPin, HIGH);
  
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // определяем дисплей по адресу 0x3C
  display.clearDisplay(); 
  display.cp437(true);  // задаем сдвиг под символам на вывод
  display.setRotation(2);  // задаем поворот экрана
  display.setTextColor(WHITE); 
  delay(1000);
  
  display.drawXBitmap(128 / 2 - logo_width / 2, 0, logo, logo_width, logo_height, 1);  // рисуем лого
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
  Random(1); 
  rndTime = ESP8266TrueRandom.random(3000, 10000);
  
  for (int i = 0; i < sizeof(startMelody) / sizeof(int); i++){
    tone(soundPin, startMelody[i], times1[i]);
    delay(times1[i]);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(25, 5);
  display.println(utf8rus("погнали?"));
  display.display();
}

void loop() {
  bool but1 = !digitalRead(cButton1); // читаем состояние центральной кнопки и переводим в булевую
  bool but2 = !digitalRead(cButton2); // читаем состояние правой кнопки и переводим в булевую
  bool but3 = !digitalRead(cButton3); // читаем состояние левой кнопки и переводим в булевую

  if(rung == wordsSize){
    Serial.println("Over");
    rung = 1;
    Random(1);
  } // когда мы прошли весь словарь - решафлим его и пускаем заново

  if(timeGo && millis() >= startTime + rndTime){
    startTime = 0;
    timeGo = false;
    display.clearDisplay();
    display.drawRoundRect (1, 1, 127, 31, 5, 1);    
    display.setTextSize(1,2);                  
    display.setCursor(25, 7);
    display.println(utf8rus("раунд окончен"));
    display.display();
    
    for (int i=0; i < sizeof(roundMelody) / sizeof(int); i++){
      tone(soundPin, roundMelody[i], durations2[i]);
      delay(times2[i]);
    }
    
    display.clearDisplay();
    display.drawRoundRect (1, 1, 127, 31, 5, 1); 
    display.setTextSize(1,2);
    display.setCursor(10, 7);
    display.println(utf8rus("введите победителя"));
    display.display();
    change = true;
    
    while(change){
      bool but2 = !digitalRead(cButton2); // читаем состояние правой кнопки и переводим в булевую
      bool but3 = !digitalRead(cButton3); // читаем состояние левой кнопки и переводим в булевую
      
      if(but2){  // 
        score2 += 1;
        change = false;
        tone (soundPin, 600, 200); // пиликаем;
      }  

      if(but3){  // 
        score1 += 1;
        change = false;
        tone (soundPin, 600, 200); // пиликаем;
      } 

      delay(50);
    }

    if(score1 != 5 && score2 != 5){
      display.clearDisplay();
      display.drawRoundRect (1, 1, 127, 31, 5, 1);
      display.setTextSize(1,2);
      display.setCursor(13, 7);
      display.println(utf8rus("готовы продолжать?"));
      display.display();
      change = true;
    
      while(change){
        bool but1 = !digitalRead(cButton1); // читаем состояние центральной кнопки и переводим в булевую

        if(but1){
          change = false;
          tone (soundPin, 600, 200); // пиликаем;
        }

        delay(50);
      }
      
      display.clearDisplay();
      display.drawRoundRect (1, 1, 127, 31, 5, 1);
      display.setCursor(19, 7);
      display.println(utf8rus("продолжаем через"));
      display.display();
      delay(1500);

      for(int i = 0; i < 4; i++){
        if(i < 3){
          display.clearDisplay();
          display.setTextSize(2);
          display.setCursor(60, 5);
          display.println(3 - i);
          display.display();
          tone (soundPin, 600, 200); // пиликаем;
        }
        else{
          display.clearDisplay();
          display.setTextSize(2);
          display.setCursor(25, 5);
          display.println(utf8rus("погнали"));
          display.display();
          tone (soundPin, 1500, 500); // пиликаем;
        }
        delay(1000);
      }
      
      StartRound();
    }
    else{
      display.clearDisplay();

      if(score2 == 5){
        display.setCursor(18, 7);
        display.drawRoundRect (1, 1, 127, 31, 5, 1); 
        display.println(utf8rus("победили правые!"));
        display.display();
        score1 = 0;
        score2 = 0;
        
        for (int i = 0; i < sizeof(rightMelody) / sizeof(int); i++){  // мелодия 
          tone(soundPin, rightMelody[i], duration3[i]);
          delay(times3[i]);
        }
      }
      else{
        display.setCursor(20, 7);
        display.drawRoundRect (1, 1, 127, 31, 5, 1); 
        display.println(utf8rus("победили левые!"));
        display.display();
        score1 = 0;
        score2 = 0;
        
        for (int i = 0; i < sizeof(rightMelody) / sizeof(int); i++){  // мелодия 
          tone(soundPin, rightMelody[i], duration3[i]);
          delay(times3[i]);
        }
      }

      display.clearDisplay();
      display.setTextSize(1,2);
      display.setCursor(20, 7);
      display.println(utf8rus("погнали дальше?"));
      display.display();
      change = true;

      while(change){
        bool but1 = !digitalRead(cButton1); // читаем состояние центральной кнопки и переводим в булевую
        
        if(but1){
          change = false;
          tone (soundPin, 600, 200); // пиликаем;
          
          for(int i = 0; i < 3; i++){
            display.clearDisplay();
            display.setTextSize(2);
            display.setCursor(60, 5);
            display.println(3 - i);
            display.display();
            tone (soundPin, 600, 200); // пиликаем;
            delay(1000);
          }
          
          StartRound(); 
        }

        delay(50);
      }
    }
  }

  if(but1 && !check1){ // начало раунда по нажатию кнопки
      while(first){
        tone (soundPin, 600, 200); // пиликаем;
          
        for(int i = 0; i < 4; i++){
        if(i < 3){
          display.clearDisplay();
          display.setTextSize(2);
          display.setCursor(60, 5);
          display.println(3 - i);
          display.display();
          tone (soundPin, 600, 200); // пиликаем;
        }
        else{
          display.clearDisplay();
          display.setTextSize(2);
          display.setCursor(28, 5);
          display.println(utf8rus("вперед"));
          display.display();
          tone (soundPin, 1500, 500); // пиликаем;
        }
        delay(1000);
      }
        
        first = false;
        delay(50);
      }
    
    check1 = true;
    StartRound();
  }
  else if(!but1)
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

void StartRound(){    
  if(!timeGo){
      timeGo = true;
      rndTime = ESP8266TrueRandom.random(3000, 10000);
      Serial.println(rndTime);
      startTime = millis();
    } // начинаем отсчет

  Output(rung);
  rung++;
  tone (soundPin, 600, 200); // пиликаем
  delay(200);
}

void Output(int num){  // вывод слова на экран
  Serial.print("Индекс = ");
  Serial.print(num);
  Serial.print("; Размер = ");
  Serial.println(wordsSize);
  display.clearDisplay();
  display.drawRoundRect (1, 1, 127, 31, 5, 1);    
  display.setTextSize(1,2);                 

  switch (words[num].length() / 2){
    case 2:
      display.setCursor(60, 14);
      display.println(utf8rus(words[num]));
      break;

    case 3:  //
      display.setCursor(56, 14);
      display.println(utf8rus(words[num]));
      break;

    case 4:  //
      display.setCursor(53, 14);
      display.println(utf8rus(words[num]));
      break;

    case 5:  //
      display.setCursor(50, 14);
      display.println(utf8rus(words[num]));
      break;

    case 6:  //
      display.setCursor(47, 14);
      display.println(utf8rus(words[num]));
      break;

    case 7:  //
      display.setCursor(44, 14);
      display.println(utf8rus(words[num]));
      break;

    case 8:  //
      display.setCursor(41, 14);
      display.println(utf8rus(words[num]));
      break;

    case 9:  //
      display.setCursor(38, 14);
      display.println(utf8rus(words[num]));
      break;

    case 10:
      display.setCursor(35, 14);
      display.println(utf8rus(words[num]));
      break;

    case 11:  //
      display.setCursor(32, 14);
      display.println(utf8rus(words[num]));
      break;

    case 12:
      display.setCursor(29, 14);
      display.println(utf8rus(words[num]));
      break;

    case 13:
      display.setCursor(26, 14);
      display.println(utf8rus(words[num]));
      break;

    case 14:
      display.setCursor(23, 14);
      display.println(utf8rus(words[num]));
      break;

    case 15:
      display.setCursor(20, 14);
      display.println(utf8rus(words[num]));
      break;
  }
  Score(score1, score2); 
  display.display();;
}

void Score(int a, int b){
  display.setTextSize(1,1);

  for(int i = 0; i < a; i++){
    display.setCursor(5 + (i * 10), 3);
    display.write(35);
  }

  for(int i = 0; i < b; i++){
    display.setCursor(118 - (i * 10), 3);
    display.write(35);
  }
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
