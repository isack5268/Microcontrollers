const char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang='ru'>
<head>
  <meta http-equiv="Content-type" content="text/html; charset=utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
  <title>Автоматизация v0.1</title>
  <style>
    html {
      font-family: Helvetica;
      display: inline-block;
      margin: 0px auto;
      text-align: center;
    }

    body {
      margin-top: 50px;
      background: #2f2f2f;
    }

    h1 {
      color: #ffffff;
      margin: 50px auto 30px;
    }

    h3 {
      color: #cccccc;
      margin-bottom: 50px;
    }

    .button {
      display: inline-block;
      width: 200px;
      background-color: #4CAF50;
      border: none;
      color: white;
      padding: 13px 0;
      text-decoration: none;
      font-size: 25px;
      margin: 20px 0;
      cursor: pointer;
      border-radius: 4px;
    }

    .button-on {
      background-color: #4CAF50;
    }

    .button-on:active {
      background-color: #3e8e41;
    }

    .button-off {
      background-color: #4CAF50;
    }

    .button-off:active {
      background-color: #3e8e41;
    }

    p {
      font-size: 14px;
      color: #ffffff;
      margin-bottom: 10px;
    }

    input[type='number'] {
      padding: 10px;
      font-size: 20px;
      width: 175px;
      border: 1px solid #cccccc;
      border-radius: 4px;
      margin-bottom: 20px;
    }

    #signalization {
      font-size: 20px;
      color: #ffffff;
      margin-top: 20px;
    }

    #signalizationResult {
      font-size: 20px;
      color: #ffffff;
      margin-top: 20px;
    }

    #result {
      font-size: 20px;
      color: #ffffff;
      margin-top: 20px;
    }

    #result1 {
      font-size: 20px;
      color: #ffffff;
      margin-top: 20px;
    }

    .input-container {
      display: flex;
      justify-content: center;
      align-items: center;
      margin-bottom: 20px;
    }

    .input-container input {
      margin-right: 10px;
    }

    .input-container p {
      border: 1px solid #4CAF50;
      color: white;
      font-size: 18px;
      background: #4CAF50;
      border-radius: 5px;
      padding: 10px 15px;
      margin: 0 10px;
      box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
    }

    .calc-container {
      display: grid;
      grid-template-columns: repeat(2, 1fr);
      gap: 20px;
    }

    .calc-block {
      background-color: #333333;
      padding: 20px;
      border-radius: 10px;
      box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
      margin: 0 15px;
      width: 400px;
      height: 100%;
    }

    .calc-block h2 {
      color: #ffffff;
      margin-top: 0;
    }

    .calc-block .button {
      margin-top: 20px;
      margin-bottom: 20px;
    }

    .calc-block p {
      margin-top: 10px;
    }

    .settings-block {
      background-color: #333333;
      padding: 20px;
      border-radius: 10px;
      box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
      margin-bottom: 20px;
      width: 600px;
      height: 300px;
      margin: 0 auto;
    }

    .settings-block h1 {
      margin-top: 0;
    }

    .sensors-block {
      background-color: #333333;
      padding: 20px;
      border-radius: 10px;
      box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
      margin-bottom: 20px;
      width: 600px;
      margin: 0 auto;
    }

    .sensors-block h1 {
      margin-top: 0;
    }

    @media (max-width: 768px) {
      .calc-container {
        grid-template-columns: 1fr;
      }
      .calc-block {
        width: 100%;
        margin-bottom: 20px;
      }
      .settings-block {
        width: 100%;
      }
      .sensors-block {
        width: 100%;
      }
    }

    @media (min-width: 769px) {
      .calc-container {
        display: flex;
        justify-content: center;
      }
      .calc-block {
        width: calc(50% - 5px);
        margin: 0 5px;
      }
      .calc-block:first-child {
        margin-left: 15px;
      }
      .calc-block:last-child {
        margin-right: 15px;
      }
    }

    @media (max-width: 480px) {
      .input-container {
        flex-direction: column;
      }
      .input-container input {
        margin-bottom: 10px;
      }
      .button {
        width: 100%;
      }
      h1 {
        font-size: 24px;
      }
      h2 {
        font-size: 20px;
      }
      p {
        font-size: 16px;
      }
    }
  </style>
  <link rel='shortcut icon' href='https://pancakefaces.ru/img/icons/menu/logo.png'>
</head>

<body>
  <div class="sensors-block">
    <h1>Датчики и Счетчики</h1>
    <div class='input-container'>
      <p id='time'></p>
      <p id='term1'></p>
      <p id='term2'></p>
    </div>
  </div>
  <div class="settings-block">
    <h1>Настройки</h1>
    <div class="input-container">
      <input type="number" id="signalizationCuba" placeholder="Сигнал куба" required>
      <input type="number" id="signalizationPara" placeholder="Сигнал пара" required>
      <input type="number" id="error" placeholder="Погрешность" required>
    </div>
    <button class="button button-on" onclick="sendSignalization()">Отправить</button>
    <p id="signalizationResult"></p>
  </div>
  <h1>Калькуляторы</h1>
  <div class="calc-container">
    <div class="calc-block">
      <h2>Расчет голов по абсолютному спирту</h2>
      <div class='input-container'>
        <input type='number' id='input1' placeholder='Литров СС' required>
        <input type='number' id='input2' placeholder='% Крепости' required>
      </div>
      <button class='button button-on' onclick='calculate()' style="margin-top: 107px;">Рассчитать</button>
      <p id='result'></p>
    </div>
    <div class="calc-block">
      <h2>Калькулятор разбавления спирта</h2>
      <div class='input-container'>
        <input type='number' id='input3' placeholder='Литров СС' required>
        <input type='number' id='input4' placeholder='% Крепости' required>
      </div>
      <div class='input-container'>
        <input type='number' id='input5' placeholder='Нужная крепость' required>
      </div>
      <button class='button button-on' onclick='calculate2()'>Рассчитать</button>
      <p id='result1'></p>
    </div>
  </div>
  <script>
    function sendSignalization() {
      var signalizationCubaValue = document.getElementById('signalizationCuba').value;
      var signalizationParaValue = document.getElementById('signalizationPara').value;
      var errorValue = document.getElementById('error').value;

      if (signalizationCubaValue !== '') {
        var xhr = new XMLHttpRequest();
        xhr.open('GET', '/setSignalization?value=' + encodeURIComponent(signalizationCubaValue), true);
        xhr.send();
      }

      if (signalizationParaValue !== '') {
        var xhr = new XMLHttpRequest();
        xhr.open('GET', '/setSignalizationPara?value=' + encodeURIComponent(signalizationParaValue), true);
        xhr.send();
      }

      if (errorValue !== '') {
        var xhr = new XMLHttpRequest();
        xhr.open('GET', '/setError?value=' + encodeURIComponent(errorValue), true);
        xhr.send();
      }

      if (signalizationCubaValue !== '' || signalizationParaValue !== '' || errorValue !== '') {
        document.getElementById('signalizationResult').innerText = 'Данные отправлены';
      } else {
        document.getElementById('signalizationResult').innerText = 'Нет значений для отправки';
      }
    }

    function calculate() {
      var x = parseFloat(document.getElementById('input1').value);
      var y = parseFloat(document.getElementById('input2').value);
      if (!isNaN(x) && !isNaN(y)) {
        var result = (x * (y / 100)) * 0.1;
        document.getElementById('result').innerText = 'Результат: ' + result.toFixed(2) + ' л';
        // Отправка данных на сервер
        sendDataToServer(result);
      } else {
        document.getElementById('result').innerText = 'Пожалуйста, введите числа.';
      }
    }

    function calculate2() {
      var x = parseFloat(document.getElementById('input3').value);
      var y = parseFloat(document.getElementById('input4').value);
      var z = parseFloat(document.getElementById('input5').value);
      if (!isNaN(x) && !isNaN(y) && !isNaN(z)) {
        var result1 = Math.round(100 * y * (x * 1000 / 100) / z - x * 1000); // Изменено на Math.round()
        document.getElementById('result1').innerText = 'Результат: ' + result1 + ' мл';
      } else {
        document.getElementById('result1').innerText = 'Пожалуйста, введите числа.';
      }
    }

    function updateTerm1() {
      fetch('/getTerm1')
        .then(response => response.text())
        .then(data => {
          document.getElementById('term1').innerText = data;
        });
      setTimeout(updateTerm1, 1000); // Обновление времени
    }

    function updateTerm2() {
      fetch('/getTerm2')
        .then(response => response.text())
        .then(data => {
          document.getElementById('term2').innerText = data;
        });
      setTimeout(updateTerm2, 1000); // Обновление времени
    }

    function updateTime() {
      fetch('/getTime')
        .then(response => response.text())
        .then(data => {
          document.getElementById('time').innerText = data;
        });
      setTimeout(updateTime, 1000); // Обновление времени
    }
    window.onload = function() {
      updateTerm1();
      updateTerm2();
      updateTime();
    }; // Запускаем обновление
  </script>
</body>

</html>
)=====";