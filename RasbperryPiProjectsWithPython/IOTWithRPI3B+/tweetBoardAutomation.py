#we will use two buttons one for asking to tweet and the second tweeting the text on twitter
#we will use gpiozero library
#it send a tween on button pressed
from key import api_key,api_sec,ac_tk,ac_tk_sec
from twython import Twython
from time import sleep
from gpiozero import LED ,Button
from signal import pause

led = LED(18)
#we will add the buttons
button1= Button(22)
button2= Button(27)
twitter=Twython(api_key,api_sec,ac_tk,ac_tk_sec)


def tweet_make():
	global mainText
	mainText = input("input the tweet you want to publish :)\n")
def tweet_post():
	global mainText
	twitter.update_status(status=mainText)
	print("its done ")
	
button1.when_pressed=tweet_make
button2.when_pressed=tweet_post


pause()
