# Тестовое задание. Инфотекс.
## Выполнил: Шаньшин Семен Евгеньвич, ТУСУР

## Tasks 

Реализация всех методов находится в арихве Shanshin_Tasks.rar, скрипт реализующий методы пронаименован как for_dict.py (данный файл не является запускающим файлом, а лишь содержит методы, которые реализуют задания).

## Начало

Выполняет несколько простых шагов.
1) распаковываем архив
2) в терминале пишем python script.py 
После этого все необходимые библиотеки скачиваются и запускается сервер по адресу 127.0.0.1:8000

### Метод №1. Метод принимает идентификатор geonameid и возвращает информацию о городе.

Проверка работоспобности метода осуществляется путем написание в url строке в браузере или в Postman  127.0.0.1:8000/first/?geoname, где мы указываем путь и прописываем параметры (ID города), после чего происходит возврат информации о городе с присвоенным ему уникальным ID в виде JSON-файла.

Пример реализации REST-запросов и протестированных в POSTMAN представлен ниже на скриншоте: 

 ![alt text](https://sun9-14.userapi.com/impf/ouoLtAjND8OPp58OAe4eCzH74XNqULGZ6NpkyQ/VOHwqfg7kNM.jpg?size=936x456&quality=96&proxy=1&sign=d9a29e9dc8dbb798e846bffd21dde450&type=album)

### Метод №2. Метод принимает номер страницы и количество отображаемых на странице городов и возвращает список городов с их информацией. 

Проверка работоспобности метода осуществляется путем написание в url строке в браузере или в Postman 127.0.0.1:8000/second/?page=...&count=..., где мы подаем на вход параметры: page - страница, count - количество городов на странице. (Троеточие означает значение параметров)
На выходе мы получаем сформированный JSON-файл, в котором содержится выбранное кол-во городов.

Пример реализации REST-запросов и протестированных в POSTMAN представлен ниже на скриншоте: 

 ![alt text](https://sun9-76.userapi.com/impf/W9IEjE4IcMLhG5JH-s0wUoo86a7WdBgxrxA6cQ/E6ey7kcoSJY.jpg?size=936x496&quality=96&proxy=1&sign=d8bb2ebfc704a5f0520a2504c909e1db&type=album)

### Метод №3. Метод принимает название города (на русском языке) и получает информацию о найденном городе. Если несколько городов имеют одно и то же название, то разрешать неоднозначность, выбирая город с большим населением; если население совпадает, то брать первый по списку.

Проверка работоспобности метода осуществляется путем написания  в  url строке в браузере или в Postman 127.0.0.1:8000/third/?town_name=, где мы подаем вход параметры: town_name - название города (на русском языке), на выходе мы поулчаем сформированный JSON-файл, в котором содержится информация о городе.

Пример реализации REST-запросов и протестированных в POSTMAN представлен ниже на скриншоте: 

 ![alt text](https://sun9-25.userapi.com/impf/ak5R8Mbwh7xA8gRuhJW0l9bJSDxbDf5dQxLXiA/BAmMjdGGCeY.jpg?size=936x474&quality=96&proxy=1&sign=379ba122e9062c4930356fe379d02c94&type=album)
 
 ### Метод №4 Метод принимает название двух городов и выдает самый северный город, находятся ли оба в города в одном часовом поясне и сами часовые пояса двух городов.
 
 Проверка работоспобности метода осуществляется путем написания в в  url строке в браузере или в Postman 127.0.0.1:8000/fouth/?town1=...&town2=..., где мы подаем вход параметры: town1 - название первого города (на русском языке),town2  - название второго города на русском на выходе мы поулчаем сформированный JSON-файл. Задание было модернизировано (ввод название городов на русском , т.к. была не ясность в задании).
 
 Пример реализации REST-запросов и протестированных в POSTMAN представлен ниже на скриншоте: 
 
 ![alt text](https://sun9-62.userapi.com/impf/h0yg1eN_ijcACUygJBO4UVzXbKpSf2qByzhezg/kUXojMbIjRk.jpg?size=1527x770&quality=96&proxy=1&sign=13bbef9c983925a67faec112a2ae2a3b&type=album)
 


