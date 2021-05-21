#blink led using buttons

import RPi.GPIO as gpio  # the library for gpio
from time import sleep #//library for delay

#//setup
gpio.setmode(gpio.BOARD) #//choose it as board 
gpio.setup(7,gpio.OUT)  #//make the gpio 7 as output
gpio.setup(11,gpio.IN)
sit = False
gpio.output(7,False)
#LOOP
while True :
	button=gpio.input(11)
	if(button == 1 ):
		#different way
		curr=gpio.input(7)
		gpio.output(7,not curr)
		#sit = not sit
		#gpio.output(7,sit)
		while gpio.input(11)==1:
			pass
