#blink led using internet network

import socket
import RPi.GPIO as gpio
from time import sleep

gpio.setmode(gpio.BOARD)
gpio.setup(5,gpio.OUT)



mysoc=socket.socket()
mysoc.bind(("",1234))
mysoc.listen(5)
conn,addr=mysoc.accept()

while 1:
	data=conn.recv(1000)
	print(data)
	if data == b"on\n":
		print("the led is on")
		gpio.output(5,True)
	elif data == b"off\n":
		print ("the led is off")
		gpio.output(5,False)
	elif data == b"exit\n":
		quit()
	else :
		print ("it accept on or off or exit")
conn.close()
mysoc.close()
