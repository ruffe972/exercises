﻿USE ershov

DELETE FROM authorship
DELETE FROM book_genre
DELETE FROM book_user_record

DELETE FROM genre
DBCC CHECKIDENT ('[genre]', RESEED, 0);
GO
DELETE FROM book
DBCC CHECKIDENT ('[book]', RESEED, 0);
GO
DELETE FROM author
DBCC CHECKIDENT ('[author]', RESEED, 0);
GO
DELETE FROM site_user
DBCC CHECKIDENT ('[site_user]', RESEED, 0);
GO

INSERT INTO book
VALUES (
	--1
	'Сила Objective-C 2.0. Эффективное программирование для iOS и OS X',
	'2014',
	'obj-c.jpg',
	'Эта книга поможет вам освоить всю мощь языка программирования Objective-C 2.0 и научит применять его максимально эффективно при разработке мобильных приложений для iOS и OS X. Автор описывает работу языка на понятных практических примерах, которые помогут как начинающим программистам, так и опытным разработчикам повысить уровень понимания Objective-C и существенно обогатить опыт его применения в своей работе.'
), (
	--2
	'Гарри Поттер и философский камень',
	'1997',
	'hp_1.jpeg',
	'«Перевернув конверт трясущимися руками, Гарри увидел на обратной стороне лиловую сургучную печать с гербом: лев, орел, барсук и змея вокруг большой буквы "Х"». Гарри Поттер ни разу даже не слышал о «Хогварце», но на дверной коврик дома номер четыре по Бирючинной улице начинают падать письма. Адрес написан зелеными чернилами на желтоватом пергаменте, а конверт скрепляет лиловая печать. Однако письма тут же конфисковывают тетя и дядя мальчика, имеющие на редкость скверный характер. Потом, на одиннадцатый день рождения Гарри, в дом врывается гигант по имени Рубеус Огрид с невероятными новостями: Гарри Поттер – волшебник, и его ждет место в школе колдовства и ведьминских искусств «Хогварц». Потрясающие приключения начинаются!'
), (
	--3
	'Гарри Поттер и тайная комната',
	'1998',
	'hp_2.jpeg',
	'«Заговор, Гарри Поттер. Заговор – в этом году в Хогвартсе, школе колдовства и ведьминских искусств, произойдут ужаснейшие события». Лето у Гарри Поттера состояло из самого ужасного дня рождения в жизни, мрачных предупреждений от домового эльфа по имени Добби и спасения от Дурслеев, когда его друг Рон Уизли прибыл за ним на волшебной летающей машине! Вернувшись в школу колдовства и ведьминских искусств «Хогварц» на второй курс, Гарри слышит странный шепот, который эхом раздается в пустых коридорах. А потом начинаются нападения. Студентов находят будто превращенными в камень… Кажется, что зловещие предсказания Добби начинают сбываться.'
), (
	--4
	'Гарри Поттер и узник Азкабана',
	'1999',
	'hp_3.jpeg',
	'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'
), (
	--5
	'Гарри Поттер и Кубок огня',
	'2000',
	'hp_4.jpeg',
	'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'
), (
	--6
	'Гарри Поттер и Орден Феникса',
	'2003',
	'hp_5.jpeg',
	'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'
), (
	--7
	'Гарри Поттер и Принц-полукровка',
	'2005',
	'hp_6.jpeg',
	'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'
), (
	--8
	'Гарри Поттер и Дары Смерти',
	'2007',
	'hp_7.jpeg',
	'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'
), (
	--9
	'Приемы объектно-ориентированного проектирования. Паттерны проектирования',
	'1994',
	'patterns.jpg',
	'В предлагаемой книге описываются простые и изящные решения типичных задач, возникающих в объектно-ориентированном проектировании. Паттерны появились потому, что многие разработчики искали пути повышения гибкости и степени повторного использования своих программ. Найденные решения воплощены в краткой и легко применимой на практике форме. Авторы излагают принципы использования паттернов проектирования и приводят их каталог. Таким образом, книга одновременно решает две задачи. Во-первых, здесь демонстрируется роль паттернов в создании архитектуры сложных систем. Во-вторых, применяя содержащиеся в справочнике паттерны, проектировщик сможет с легкостью разрабатывать собственные приложения.'
), (
	--10
	'Беовульф',
	NULL,
	'',
	'Англосаксонская эпическая поэма, действие которой происходит в Ютландии, до переселения англов в Британию. Названа по имени главного героя. Текст состоит из 3182 строк и написан аллитерационным стихом. Эпос создан в конце VII или в начале VIII века и сохранился в единственном списке XI века, который чуть не погиб во время пожара библиотеки Роберта Коттона в 1731 году. Это древнейшая эпическая поэма «варварской» (германской) Европы, сохранившаяся в полном объёме.'
), (
	--11
	'Добрые предзнаменования',
	'1990',
	'good_omens.jpg',
	'Согласно книге "Прекрасные и точные пророчества" Агнессы Псих, конец мира наступит в субботу, через одиннадцать лет после того, как ребенка американского атташе по культурным связям подменят на сына Сатаны. В результате роковой ошибки сын Сатаны отправляется жить в самое обычное семейство в рядовой английской семье. Демон Кроули и ангел Азирафель пытаются предотвратить конец света, но по земле уже едут "четыре байкера Апокалипсиса" – СМЕРТЬ, Война, Голод и Загрязнение. Судьба мира – в руках одиннадцатилетнего Адама'
), (
	--12
	'Пикник на обочине',
	'1972',
	'picnic.png',
	'"Счастье для всех, и пусть никто не уйдет обиженным!" Знаковые слова... Шедевр братьев Стругацких. Жесткая, бесконечно увлекательная и в то же время бесконечно философская книга. Время идет... Но история загадочной Зоны и лучшего из ее сталкеров - Рэда Шухарта - по-прежнему тревожит и будоражит читателя.'
)

INSERT INTO author
VALUES (
	--1
	'Мэтт Гэлловей',
	'galloway.png',
	''
), (
	--2
	'Эрих Гамма',
	'',
	'Программист из Швейцарии, является ведущим разработчиком JUnit (фреймворка для выполнения юнит-тестов на Java) и Eclipse (кросс-платформенной интегрированной среды разработки программного обеспечения). Работал в IBM над проектом Jazz.'
), (
	--3
	'Ричард Хелм',
	'',
	'Учёный, получил докторскую степень по информатике в Университете Мельбурна, начал свою карьеру в IBM Global Services. С 1991 проводил исследования в IBM в Научно-исследовательском центре Томаса Уотсона в Хоторне, Нью-Йорк.'
), (
	--4
	'Ральф Джонсон',
	'',
	''
), (
	--5
	'Джон Мэттью Влиссидес',
	'vlissides.jpg',
	'Американский учёный в области компьютерной инженерии греческого происхождения, программист. Являлся сотрудником компании IBM.'
), (
	--6
	'Джоан Роулинг',
	'rowling.jpg',
	'Джоан Роулинг, известная под псевдонимами Дж. К. Роулинг и Роберт Гэлбрейт, — британская писательница, сценарист и кинопродюсер, наиболее известная как автор серии романов о Гарри Поттере.'
), (
	--7
	'Нил Гейман',
	'',
	'Нил Гейман — английский писатель-фантаст, автор графических романов и комиксов, сценариев к фильмам.'
), (
	--8
	'Терри Пратчетт',
	'pratchett.jpg',
	'Терри Пратчетт - популярный английский писатель. Наибольшей популярностью пользуется его цикл сатирического фэнтези про Плоский мир (англ. Discworld).'
), (
	--9
	'Аркадий Стругацкий',
	'arkady_strugatsky.png',
	'Профессиональный писатель, член Союза писателей СССР с 1964 года.'
), (
	--10
	'Борис Стругацкий',
	'boris_strugatsky.png',
	'С 1964 года — профессиональный писатель, член Союза писателей СССР. Ещё несколько лет проработал в Пулковской обсерватории на полставки. С 1972 года — руководитель Ленинградского семинара молодых писателей-фантастов (впоследствии стал известен как "семинар Бориса Стругацкого"). Учредитель премии "Бронзовая улитка". С 2002 года главный редактор журнала "Полдень. XXI век".'
)

INSERT INTO genre
VALUES
('программирование'),  --1
('приключения'),  --2
('фантастика'),  --3
('детектив'),  --4
('сказка'),  --5
('эпос'),  --6
('антиутопия'),  --7
('сатира'),  --8
('математика'),  --9
('киберпанк')  --10

INSERT INTO site_user VALUES
('ivanershov51', '341243', 1, 0),  --1
('user1', '62634', 1, 0),  --2
('user2', '243612', 0, 0),  --3
('user3', '2345', 1, 0),  --4
('user4', '542352', 1, 0),  --5
('user5', '5234525', 0, 0),  --6
('bot1', '3415243', 0, 1),  --7
('bot2', '5743573', 1, 1),  --8
('bot3', '23452', 1, 1),  --9
('bot4', '234522', 0, 1)  --10