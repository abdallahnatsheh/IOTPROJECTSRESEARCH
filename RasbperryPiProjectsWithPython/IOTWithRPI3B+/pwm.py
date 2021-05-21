#PWm
#pulse width modulator
#12,13,18,19 gpio for pwm

import RPi.GPIO as gpio
from time import sleep

gpio.setmode(gpio.BCM)
gpio.setup(19.OUT)

#create a pwm object
pwmobj=gpio.PWM(19,1000)
pwmobj.start(0) # this is the duty cycle
# duty cycle is = ontime/total time

for in range(0,101,5):         #increase the voltage (increase the led light)
	pwm.ChangeDutyCycle(i) 
	sleep(0.3)

for in range(100,0,-5):        #decrease the voltage of the led light
	pwm.ChangeDutyCycle(i) 
	sleep(0.3)
