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
db = city.CheckDB()

@bot.message_handler(commands=['start'])
def start_message(message):
    if db == 0:
        city.SetName('Привет) Введи название города.')
        bot.send_message(message.chat.id, text=city.GetName())
    else:
        bot.send_message(message.chat.id, text='Базы данных не существует')

bot.infinity_polling()