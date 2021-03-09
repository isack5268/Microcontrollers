<!doctype html>
<html lang="en-US">
<head>
<title>Разработка</title>
<meta charset="utf-8">
<meta name="description" content="Pancake Faces project ялвляется open source проектом, предоставляющим в открытый доступ свои разработки в игровом движке Unity.">
<meta name="keywords" content="pancake faces, unity, open source, разработки, development, 2d, windows, project, development">
<meta name="author" content="Pancake Faces">
<meta name="copyright" content="Pancake Faces">
<?php include 'lib/module/sys-meta.php';?>
<?php include 'lib/module/sys-css.php';?>
<?php include 'lib/module/sys-js.php';?>
</head>
<body>
<?php include 'lib/module/sys-php.php';?>
<?php include 'lib/module/ui-sidebar-quickstart.php';?>
<div class="page-con-content">
	<div class="banner-con-container darkmode-header">
		<div id="object-particles">
		</div>
		<div class="wavebar-con-container" id="upside">
			<div class="wavebar-con-wrap">
				<div class="wavebar-svg-object">
				</div>
				<div class="wavebar-svg-object">
				</div>
			</div>
		</div>
		<div class='banner-con-title fade-up-onstart'>
			<div class='banner-tx1-title fade-up-onstart pulsate'>
				<h1>Разработка</h1>
			</div>
			<div class="banner-tx2-title fade-up-onstart">
				<p>
					 ПОСПАЛ -> СЕЛ -> ПОЕЛ -> ПОКОДИЛ -> УСНУЛ -> repeat!
				</p>
			</div>
		</div>
	</div>
	<div class="page-con-container">
		<div class="page-in-container">
			<div class="container-con-block darkmode-block">
				<div class="anchor-point" id="requirements">
				</div>
				<div class="container-con-wrapper">
					<div class="container-tx1-block darkmode-txt">
						<h2>Подготовка к установке Unity + Visual Studio 2019</h2>
					</div>
					<div class="container-tx2-block darkmode-txt">
						Unity - это тот самый игровой движок, что запустится даже на древнем ноуте. Однако его требования напрямую зависят от требовательности разрабатываемой игры, так что нужно заранее учитывать мощьность своего стального коня! Ниже я приведу ну очень уж усредненные системные требования, так что перед установкой сверься с минимальными. Если минимальные подходят, то можешь сравнить с рекомендуемыми и возможно немного порадоваться 😉<br>
						Данные системные требования я привел на связку Unity + Visual Studio
					</div>
				</div>
			</div>
			<div class='reqs-con-container'>
				<div class='reqs-con-group'>
					<div class="reqs-con-item reqs-left reqs-head" style="background:#27ae60 !important; color:#fff;">
						<div class='reqs-ico-item' style="background: url('/img/icons/list/recommended.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item">
							<b>Рекомендованные системные требования</b><br>
							 Для, в полной мере, комфортной разработки
						</div>
					</div>
					<div class="reqs-con-item reqs-right reqs-head" style="background:#f39c12 !important; color:#fff">
						<div class='reqs-ico-item' style="background: url('/img/icons/list/minimum.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item">
							<b>Минимальные системные требования</b><br>
							 Для того, чтобы выполнять нетрудоёмкие для железа задачи
						</div>
					</div>
				</div>
				<div class='reqs-con-group'>
					<div class="reqs-con-item reqs-left">
						<div class='reqs-ico-item darkmode-invert' style="background: url('/img/icons/list/cpu.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item darkmode-txt">
							<b>Процессор -</b> Intel Core i5 6600 и выше<br>
							<b>Процессор -</b> AMD Ryzen 5 1600 и выше
						</div>
					</div>
					<div class="reqs-con-item reqs-right">
						<div class='reqs-ico-item darkmode-invert' style="background: url('/img/icons/list/cpu.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item darkmode-txt">
							<b>Процессор -</b> 1.8ГГц с Х64 архитектурой и с поддержкой SSE2<br>
							<b>Процессор -</b> 32-битные процессоры <b>НЕ</b> поддерживаются
						</div>
					</div>
				</div>
				<div class='reqs-con-group'>
					<div class="reqs-con-item reqs-left">
						<div class='reqs-ico-item darkmode-invert' style="background: url('/img/icons/list/gpu.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item darkmode-txt">
							<b>Видеокарта -</b> Поддержка любого из DirectX 10, 11, 12 и 6Гб видеопамяти
						</div>
					</div>
					<div class="reqs-con-item reqs-right">
						<div class='reqs-ico-item darkmode-invert' style="background: url('/img/icons/list/gpu.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item darkmode-txt">
							<b>Видеокарта -</b> Поддержка любого из DirectX 10, 11, 12 и 2Гб видеопамяти
						</div>
					</div>
				</div>
				<div class='reqs-con-group'>
					<div class="reqs-con-item reqs-left">
						<div class='reqs-ico-item darkmode-invert' style="background: url('/img/icons/list/ram.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item darkmode-txt">
							<b>Оперативная память -</b> 8GB DDR4
						</div>
					</div>
					<div class="reqs-con-item reqs-right">
						<div class='reqs-ico-item darkmode-invert' style="background: url('/img/icons/list/ram.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item darkmode-txt">
							<b>Оперативная память -</b> 4Гб DDR3
						</div>
					</div>
				</div>
				<div class='reqs-con-group'>
					<div class="reqs-con-item reqs-left">
						<div class='reqs-ico-item darkmode-invert' style="background: url('/img/icons/list/storage.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item darkmode-txt">
							<b>Жесткий диск -</b>  25Гб свободного пространства и больше
						</div>
					</div>
					<div class="reqs-con-item reqs-right">
						<div class='reqs-ico-item darkmode-invert' style="background: url('/img/icons/list/storage.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item darkmode-txt">
							<b>Жесткий диск -</b> 15Гб свободного пространства
						</div>
					</div>
				</div>
			</div>
			<div class='reqs-con-container-mobile'>
				<div class='reqs-con-group-mobile'>
					<div class="reqs-con-container-mobile" style="background: #27ae60 !Important; color: #fff; webkit-box-shadow: 0px 10px 32px 0 rgba(39, 174, 96, .5); box-shadow: 0px 10px 32px 0 rgba(39, 174, 96, .5);">
						<div class='reqs-ico-item' style="background: url('/img/icons/list/recommended.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item-mobile">
							<b>Рекомендованные системные требования</b><br>
							 Для, в полной мере, комфортной разработки
						</div>
					</div>
				</div>
				<div class='reqs-con-group-mobile'>
					<div class="reqs-con-container-mobile">
						<div class='reqs-ico-item darkmode-invert-mobile darkmode-invert' style="background: url('/img/icons/list/cpu.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item-mobile darkmode-txt">
							<b>Процессор -</b> Intel Core i5 6600 и выше<br>
							<b>Процессор -</b> AMD Ryzen 5 1600 и выше
						</div>
					</div>
				</div>
				<div class='reqs-con-group-mobile'>
					<div class="reqs-con-container-mobile">
						<div class='reqs-ico-item darkmode-invert-mobile darkmode-invert' style="background: url('/img/icons/list/gpu.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item-mobile darkmode-txt">
							<b>Видеокарта -</b> Поддержка любого из DirectX 10, 11, 12 и 6Гб видеопамяти
						</div>
					</div>
				</div>
				<div class='reqs-con-group-mobile'>
					<div class="reqs-con-container-mobile">
						<div class='reqs-ico-item darkmode-invert-mobile darkmode-invert' style="background: url('/img/icons/list/ram.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item-mobile darkmode-txt">
							<b>Оперативная память -</b> 8GB DDR4
						</div>
					</div>
				</div>
				<div class='reqs-con-group-mobile'>
					<div class="reqs-con-container-mobile">
						<div class='reqs-ico-item darkmode-invert-mobile darkmode-invert' style="background: url('/img/icons/list/storage.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item-mobile darkmode-txt">
							<b>Жесткий диск -</b> 25Гб Свободного пространства и больше
						</div>
					</div>
				</div>
				<div class="reqs-con-divider">
				</div>
				<div class='reqs-con-group-mobile'>
					<div class="reqs-con-container-mobile" style="background: #f39c12; color: #fff; webkit-box-shadow: 0px 10px 32px 0 rgba(243, 156, 18, .5); box-shadow: 0px 10px 32px 0 rgba(243, 156, 18, .5)">
						<div class='reqs-ico-item' style="background: url('/img/icons/list/minimum.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item-mobile">
							<b>Минимальные системные требования</b><br>
							 Для того, чтобы выполнять нетрудоёмкие для железа задачи
						</div>
					</div>
				</div>
				<div class='reqs-con-group-mobile'>
					<div class="reqs-con-container-mobile">
						<div class='reqs-ico-item darkmode-invert-mobile darkmode-invert' style="background: url('/img/icons/list/cpu.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item-mobile darkmode-txt">
							<b>Процессор -</b> 1.8ГГц с Х64 архитектурой и с поддержкой SSE2<br>
							<b>Процессор -</b> 32-битные процессоры <b>НЕ</b> поддерживаются
						</div>
					</div>
				</div>
				<div class='reqs-con-group-mobile'>
					<div class="reqs-con-container-mobile">
						<div class='reqs-ico-item darkmode-invert-mobile darkmode-invert' style="background: url('/img/icons/list/gpu.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item-mobile darkmode-txt">
							<b>Видеокарта -</b> Поддержка любого из DirectX 10, 11, 12 и 2Гб видеопамяти
						</div>
					</div>
				</div>
				<div class='reqs-con-group-mobile'>
					<div class="reqs-con-container-mobile">
						<div class='reqs-ico-item darkmode-invert-mobile darkmode-invert' style="background: url('/img/icons/list/ram.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item-mobile darkmode-txt">
							<b>Оперативная память -</b> 4GB DDR4
						</div>
					</div>
				</div>
				<div class='reqs-con-group-mobile'>
					<div class="reqs-con-container-mobile">
						<div class='reqs-ico-item darkmode-invert-mobile darkmode-invert' style="background: url('/img/icons/list/storage.png') no-repeat center;">
						</div>
						<div class="reqs-tx1-item-mobile darkmode-txt">
							<b>Жесткий диск -</b> 15Гб Свободного пространства
						</div>
					</div>
				</div>
			</div>
			<div class="container-con-wrapper">
				<div class="container-tx1-block darkmode-txt">
					<h2>Установка</h2>
				</div>
				<div class="container-tx2-block darkmode-txt" id="download">
					<span class="context-important">Обратите внимание - </span> Требуется 64-разрядная операционная система. Поддерживаются Windows 7, 8 и 10.<br>
					<br>
				</div>
			</div>
			<a href="https://store.unity.com/ru/download-nuo" target="_blank" rel="noopener noreferrer">
			<div class="guide-con-content button-enabled darkmode-panel">
				<div class='guide-ico-content' style="background: url('/img/icons/list/unity.png') no-repeat center;">
				</div>
				<div class="guide-tx1-heading darkmode-txt pulsate">
					<p id="1">
						 Установщик Unity Hub + Visual Studio 2019 Community
					</p>
				</div>
			</div>
			</a>
			<div class='list-con-container' id="2">
				<div class='list-tx1-item darkmode-txt'>
					 1
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						 Переходи по ссылке выше и создавай аккаунт Unity ID
					</p>
				</div>
			</div>
			<div class='list-con-container' id="3">
				<div class='list-tx1-item darkmode-txt'>
					 2
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						 На этой же странице нажимай на кнопку "Начните здесь" и скачивайте установщик Unity Hub
					</p>
				</div>
			</div>
			<div class='list-con-container' id="4">
				<div class='list-tx1-item darkmode-txt'>
					 3
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						Запускай установщик и следуй инструкциям. После чего открывай Unity Hub и входи в Unity ID (справа сверху, только тссс...)
					</p>
				</div>
			</div>
			<div class='list-con-container'>
				<div class='list-tx1-item darkmode-txt'>
					 4
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p id="5">
						 Теперь открывай вкладку Installs и нажимай кнопку Add. Откроется меню с выбором версий Unity, если не шаришь, то выбирай рекомендованную, а если же ты продвинутый user, то выбирай что душе угодно!
					</p>
				</div>
			</div>
			<div class='list-con-container'>
				<div class='list-tx1-item darkmode-txt'>
					 5
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						 На следующем этапе тебе нужно выбрать компоненты с которыми установится выбранная тобой версия Unity. Если ты шаришь, то все как обычно - выбирай что душе угодно, если не шаришь, то слушай:<br>
						 <b>1.</b> Если у тебя нет Visual Studio, то тыкай галочку (Если хочешь другую версию VS, то можешь не ставить галочку, а просто привязать позже нужную)<br>
						 <b>2.</b> В следующей графе выбирай платформу/платформы под которые хочешь разрабатывать игры<br>
						 <b>3.</b> Документацию советую не ставить, тк проще смотреть на оф сайте<br>
						 <b>4.</b> Дополнительные языки по нужде<br>
						 <b id="6">5.</b> Нажимай "Далее" и соглашайся с License and terms<br>
						 <b>6.</b> Нажимай да, после этих действий установится выбранная тобой версия Unity
					</p>
				</div>
			</div>
			<div class='list-con-container' id="7">
				<div class='list-tx1-item darkmode-txt'>
					 6
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						 Теперь переходи во вкладку "Projects" и нажимай кнопку "NEW", после чего тебе предложат выбрать шаблон, тут сам определись, что тебе нужно
					</p>
				</div>
			</div>
			<div class='list-con-container' id="8">
				<div class='list-tx1-item darkmode-txt'>
					 7
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						 Выбери название игры и директорию, в которой она будет находиться. Нажимай кнопку "Create"!
					</p>
				</div>
			</div>
			<div class='list-con-container' id="9">
				<div class='list-tx1-item darkmode-txt'>
					 8
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						 Поздравляю! Можешь приступать к работе над своей игрой!
					</p>
				</div>
			</div>
			<div class='list-con-container' id="10">
				<div class='list-tx1-item darkmode-txt'>
					 Доп.
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						 Дополнительно расскажу о том, как привязать свою версию Visual Studio (если не ставил галочку в 5-ом пункте):<br>
						 <b>1.</b> В редакторе Unity выбери меню <b>Edit > Preferences</b><br>
						 <b>2.</b> Выбреи меню <b>External Tools</b><br>
						 <b>3.</b> Выбирай меню <b>External Script Editor</b> и в выпадающем меню выбери нужную тебе Visual Studio<br>
						 <b>4.</b> Если в выпадающем списке нет твоей версии, то нажимай кнопку <b>Browse...</b>, и в директории Visual Studio, в папке Common7/IDE выбирай файл <b>devenv.exe</b><br>
						 <b>5.</b> Не забудь проверить поставлен ли флажок <b>Editor Attaching</b>
					</p>
				</div>
			</div>
			<div class="container-con-block darkmode-block">
				<div class="anchor-point" id="arduino">
				</div>
				<div class="container-con-wrapper">
					<div class="container-tx1-block darkmode-txt">
						<h2>Программирование под аппаратную платформу Arduino</h2>
					</div>
					<div class="container-tx2-block darkmode-txt">
						Для начала ознакомимся, что такое все таки Arduino? Arduino - это небольшая плата с собственным процессором и памятью. На плате также есть пара десятков контактов, к которым можно подключать всевозможные компоненты: лампочки, датчики, моторы, чайники, роутеры, магнитные дверные замки и вообще всё, что работает от электричества. В процессор Arduino можно загрузить программу, которая будет управлять всеми этими устройствами по заданному алгоритму.<br>
						Начать программировать на Arduino достаточно просто, благо создатели разработали удобную и нетребовательную до железа и системы IDE для работы с аппаратной платформой. Arduino IDE, так называется официальный софт. Ниже я опишу как его скачать и настроить под свою плату.
					</div>
				</div>
			</div>
			<a href="https://www.arduino.cc/en/software" target="_blank" rel="noopener noreferrer">
			<div class="guide-con-content button-enabled darkmode-panel" id="arduino_ref">
				<div class='guide-ico-content' style="background: url('/img/icons/list/arduino.png') no-repeat center;">
				</div>
				<div class="guide-tx1-heading darkmode-txt pulsate">
					<p id="arduino_1">
						 Скачать Arduino IDE с официльного сайта
					</p>
				</div>
			</div>
			</a>
			<div class='list-con-container' id="arduino_2">
				<div class='list-tx1-item darkmode-txt'>
					 1
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						 Устанавливай/распаковывай Arduino IDE и открывай.<br> 
						 Далее открывай вкладку <b>Файл -> Настройки</b>, сразу включим показ строк слева от кода. (очень удобная штука ;) 
					</p>
				</div>
			</div>
			<div class='list-con-container' id="arduino_3">
				<div class='list-tx1-item darkmode-txt'>
					 2
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						  Далее тебе надо настроить IDE под твою плату.<br>
						  Открывай вкладку <b>Инструменты -> Плата -> Arduino AVR Boards</b> и выбирай свою плату.
					</p>
				</div>
			</div>
			<div class='list-con-container' id="arduino_4">
				<div class='list-tx1-item darkmode-txt'>
					 3
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						  Теперь надо выбрать на каком процессоре базируется твоя плата.<br>
						  Открывай вкладку <b>Инструменты -> Процессор</b> и выбирай процессор своей платы.
					</p>
				</div>
			</div>
			<div class='list-con-container' id="arduino_5">
				<div class='list-tx1-item darkmode-txt'>
					 4
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						  Теперь надо выбрать <b>COM порт</b>, к которому подключена твоя плата.<br>
						  Открывай вкладку <b>Инструменты -> Порт</b> и выбирай порт, к которому подключена твоя плата.
					</p>
				</div>
			</div>
			<div class='list-con-container'>
				<div class='list-tx1-item darkmode-txt'>
					 5
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						  Готово! Начинай программировать!
					</p>
				</div>
			</div>
			<div class='list-con-container' id="arduino_6">
				<div class='list-tx1-item darkmode-txt'>
					 Доп.
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						  Если твой ПК не видит подключенную плату на <b>COM порте</b>, значит возможно нужно установить <a href="https://all-arduino.ru/drajver-ch340g-dlya-arduino/" target="_blank">драйвер</a>, это распространенная проблема.
					</p>
				</div>
			</div>
			<div class="container-con-block darkmode-block">
				<div class="anchor-point" id="esp">
				</div>
				<div class="container-con-wrapper">
					<div class="container-tx1-block darkmode-txt">
						<h2>Программирование под аппаратную платформу ESP8266</h2>
					</div>
					<div class="container-tx2-block darkmode-txt">
						Все знакомые с Ардуино уже составили собственный портрет данной платы, представляя её в качестве простого шилда для связи по беспроводному интернету. На деле, это скорее микроконтроллер с несколькими собственными интерфейсами.
						Выбирайте UART или SPI, если хотите сделать оборудование полностью автономным. Именно все эти достоинства дали чипу прозвище «революционный» при его выходе, и если вы занимаетесь проектированием систем и робототехникой на основе Ардуино или РПИ, то вам определённо стоит купить ESP8266 и протестировать его в своих проектах. Небольшое время отклика, скоростные интерфейсы и возможность использования одновременно нескольких протоколов в многоканальном режиме говорят сами за себя.<br id="esp_1">
						Алгоритм получения среды разработки для платы ESP8266 несильно отличается от Arduino. Тебе понадобится все та же Arduino IDE, как её установить - можешь посмотреть выше, так что пропустим этот этап и приступим непосредственно к её настройки под ESP8266!
					</div>
				</div>
			</div>
			<div class='list-con-container'>
				<div class='list-tx1-item darkmode-txt'>
					 1
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p id="esp_2">
						 Начнем! Открывай вкладку <b>Файл -> Настройки</b> и тебе нужно вставить в строку <b>Дополнительные ссылки для Менеджера плат</b>, вот эту ссылку <b>http://arduino.esp8266.com/stable/package_esp8266com_index.json</b><br>
						 Нажимай ОК!
					</p>
				</div>
			</div>
			<div class='list-con-container'>
				<div class='list-tx1-item darkmode-txt'>
					 2
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p id="esp_3">
						 Далее открывай вкладку: <b>Инструменты -> Плата -> Менеджер плат</b>. Начинай вводить в поиске esp8266, после прогрузки ты увидишь пакет с названием - <b>«esp8266 от сообщества ESP8266»</b>.<br> 
						 Установи его!
					</p>
				</div>
			</div>
			<div class='list-con-container'>
				<div class='list-tx1-item darkmode-txt'>
					 3
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p id="esp_4">
						 Теперь остается всего-ничего! Переходи снова во вкладку <b>Инструменты -> Плата</b> и теперь тебе нужно выбрать свою плату ESP в подразделе <b>ESP8266 Boards</b>. Теперь выбери <b>COM порт</b> и все должно заработать.<br>
						 Поздравляю! Теперь можешь приступить к программированию ;)
					</p>
				</div>
			</div>
			<div class='list-con-container'>
				<div class='list-tx1-item darkmode-txt'>
					 Доп.
				</div>
				<div class='list-tx2-description darkmode-txt'>
					<p>
						  Вот подробное <a href="https://habr.com/ru/post/371853/">руководство</a> со всеми нюансами, по типу настройки скоростей и тд. Если что-то непонятно, то почитай.
					</p>
				</div>
			</div>
		</div>
	</div>
</div>
<?php include 'lib/module/ui-main-footer.php';?>
</div>
</body>
</html>
