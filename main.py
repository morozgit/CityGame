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

db_name = os.environ.get("BD_NAME")

city = City()
rc = city.CreateDB(db_name)
@bot.message_handler(commands=['start'])
def start_message(message):
    city.SetName('Привет) Введи название города.')
    bot.send_message(message.chat.id, text=city.GetName())


bot.infinity_polling()