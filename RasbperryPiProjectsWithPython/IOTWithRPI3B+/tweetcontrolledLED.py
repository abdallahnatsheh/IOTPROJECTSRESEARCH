#blink led on tweet

from key import api_key,api_sec,ac_tk,ac_tk_sec
from twython import Twython
from twython import TwythonStreamer # this api read a tweet and act upon specific word
import RPi.GPIO as gpio
from time import sleep
gpio.setmode(gpio.BOARD)
gpio.setup(7,gpio.OUT)

#on success and on error will be changed
#data is a dicitionary wich have a key called is text
class MyStreamer(TwythonStreamer):
    def on_success(self, data):
        if 'text' in data:
            print(data['text'])# contain the key we are searching in tweet
            gpio.output(7,True)
            sleep(2)
            gpio.output(7,False)

    def on_error(self, status_code, data):
        print(status_code)
        
#mystreamer object        
stream = MyStreamer(api_key,api_sec,ac_tk,ac_tk_sec)
stream.statuses.filter(track='COVID19')
