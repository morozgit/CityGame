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
    bot.send_message(message.chat.id, text='Привет) Первый город Москва.')
    city.SetName('Москва')
    city.UpdateCityExist('Москва')


@bot.message_handler(func=lambda message: True)
def discuss_with_bot(message):
    city_name = city.GetName()
    if message.text[0] == city_name[-1].upper():
        is_city_exist = city.CheckCityExist(message.text)
        city.UpdateCityExist(message.text)
        print(message.text[0], city_name[-1])
        if is_city_exist == 0:
            last_letter = message.text[-1]
            found_city_name = city.FindCity(last_letter.upper())
            bot.send_message(message.chat.id, text=found_city_name)
            city.SetName(found_city_name)
            city.UpdateCityExist(found_city_name)
        else:
            bot.send_message(message.chat.id, text='Уже было')
    else:
        bot.send_message(message.chat.id, text='Надо на последнюю букву')

bot.infinity_polling()