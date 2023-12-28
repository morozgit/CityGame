import os

from city_game import CityGame
from dotenv import find_dotenv, load_dotenv
from telebot import TeleBot, apihelper, types

load_dotenv(find_dotenv())
tg_token = os.environ.get("TG_TOKEN")
bot = TeleBot(tg_token)

@bot.message_handler(commands=['start'])
def start_message(message):
    bot.send_message(message.chat.id, 'Привет) Введи название города.')


bot.infinity_polling()