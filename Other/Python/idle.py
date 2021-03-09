#pyinstaller -F -i "D:\Projects\Speech\icon.ico" idle.py
import speech_recognition as sr
import pyperclip
import winsound
import keyboard
import time

def callback(Recognizer, audio):
    try:
        voice = r.recognize_google(audio, language = 'ru-RU').lower()
        
        if voice.startswith("погнали"):
            with sr.Microphone() as source:
                r.adjust_for_ambient_noise(source)
                print("Слушаю...")
                sound(2000)
                audio = r.listen(source)

            final = r.recognize_google(audio, language = 'ru-RU').lower() + " "
            print("[Log] Речь распознана: " + final)
            copy(final)
        else: print("[Log] Фраза не начата со слова 'погнали'")

    except sr.UnknownValueError:
        print("[Log] Фоновый шум или невнятная речь!")
    except sr.RequestError as e:
        print("[Log] Проверьте соединение с интернетом!") 

    pass

# копируем текст в буфер обмена
def copy(text):
    try:
        pyperclip.copy(text)
        print("[Log] Речь скопирована в буфер обмена!")
        paste()
    except:
        print("[Log] Ошибка копирования в буфер обмена!")
    pass

# реализуем нажатие комбинации клавишь ctrl + v
def paste():
    try:
        keyboard.press_and_release('ctrl+v' ) 
        print("[Log] Текст успешно вставлен!")
    except:
        print("[Log] Ошибка вставки текста!")
    pass

def sound(herz):
    try:
        frequency = herz # задаем частоту сигнала
        duration = 250 # задаем длительность сигнала
        winsound.Beep(frequency, duration)
    except:
        print("[Log] Ошибка подачи звукового сигнала!")

    pass

r = sr.Recognizer()
m = sr.Microphone()

# параметры для настройки
r.pause_threshold = 0.8 # параметр времени молчания для окончания фразы
r.energy_threshold = 150 # параметр отвечающий за порог отличия речи от фона

# настраиваем обработку белых шумов
with m as source:
    r.adjust_for_ambient_noise(source, 1) 

stop_listening = r.listen_in_background(m, callback) # вызываем функцию по обработке звука

while True: time.sleep(0.1) # зацикливаем