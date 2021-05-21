#blinking led with gpio zero library

from gpiozero import LED , Button
from time import sleep
from signal import pause
led = LED(18)
#we will add the buttons
button1= Button(22)
button2= Button(27)

#while True:
 #   if button1.is_pressed:
  #      led.on()
   #     print("on")
    #sleep(1)
   # else :
    #    led.off()
     #   print("off")
    #sleep(1)
def say_hi():
    led.on()
def say_bye():
    led.off()
    
button1.when_pressed=say_hi
button2.when_pressed=say_bye

pause()
