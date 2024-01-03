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
    last_letter = message.text[-1]
    city_name = city.FindCity(last_letter.upper())
    if city_name:
        bot.send_message(message.chat.id, text=city_name)
    else:
        bot.send_message(message.chat.id, text="Город не найден.")

bot.infinity_polling()