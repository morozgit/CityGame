# Игра "Города".

## Установка Python

Установите [python3](https://realpython.com/installing-python/).

## Установка Компилятора
[Windows](https://metanit.com/cpp/tutorial/1.2.php),
[Ubuntu](https://andreyex.ru/ubuntu/kak-ustanovit-g-v-ubuntu/)

 ## Установка Boost.Python
[Документация](https://www.boost.org/doc/libs/1_84_0/libs/python/doc/html/index.html)

## Установка CMake

[Сайт](https://cmake.org/)

## Репозиторий
Клонируйте репозиторий в удобную папку.

## Виртуальное окружение
В терминале перейдите в папку с репозиторием.

### Создание виртуального окружения
```bush 
python3 -m venv venv
```

### Активация виртуального окружения Linux.

```bush
source venv/bin/activate
```

### Активация виртуального окружения Windows.

```bush
venv\Scripts\activate
```

### Установка библиотек.

```bush 
pip3 install -r requirements.txt
```

#### Запись Telegram токена.
```bush
echo TG_TOKEN=ваш токен > .env
```

## Запуск

### Скомпилировать С++

Собрать CMake.
```bush
mkdir build
cd build
cmake ..
make
```
### Запуск бота
Из директории с проектом выполните команды.
```bush
python3 main.py
```
