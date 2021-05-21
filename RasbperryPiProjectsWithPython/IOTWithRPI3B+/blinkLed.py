#just simple led blinking

#RPi.GPIO
import RPi.GPIO as gpio  # the library for gpio
from time import sleep #//library for delay


gpio.setmode(gpio.BOARD) #//choose it as board 

gpio.setup(7,gpio.OUT)  #//make the gpio 7 as output

while True :
	gpio.output(7,True)  #//turn led on 
	sleep(0.5)
	gpio.output(7,False) #//turn led off 
	sleep(0.5)
