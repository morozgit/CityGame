import os
import sys

from dotenv import find_dotenv, load_dotenv
from telebot import TeleBot, apihelper, types

# Добавьте каталог, содержащий classes.so, в путь Python
sys.path.append(os.path.join(os.path.dirname(__file__), 'build'))


from classes import City

load_dotenv(find_dotenv())

tg_token = os.environ.get("TG_TOKEN")
bot = TeleBot(tg_token)

city = City()

@bot.message_handler(commands=['start'])
def start_message(message):
    city.SetName('Привет) Введи название города.')
    bot.send_message(message.chat.id, text=city.GetName())
    

@bot.message_handler(func=lambda message: True)
def discuss_with_bot(message):
    is_city_exist = city.CheckCityExist(message.text)
    city.UpdateCityExist(message.text)
    print(is_city_exist)
    last_letter = message.text[-1]
    city_name = city.FindCity(last_letter.upper())
    print(is_city_exist)
    if city_name and (is_city_exist == 0):
        bot.send_message(message.chat.id, text=city_name)
        city.UpdateCityExist(city_name)
    else:
        bot.send_message(message.chat.id, text="Город был назван")

bot.infinity_polling()