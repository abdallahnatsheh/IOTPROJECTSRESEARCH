#first button to ask the user what to write in the email
#second button will send the email
#send email with button pressed 

import smtplib
from gpiozero import Button
from signal import pause

button1 = Button(22)
button2 = Button(27)
//choose your email server
server=smtplib.SMTP("smtp.gmail.com",587)
server.starttls()
print("server conected")
#check if the server work
try:
    server.ehlo()
except RuntimeError :
    print(error+"/n")
#login
try:
    server.login("","")
    print("login is good")
except RuntimeError :
    print(error+"/n")
    


def userinput():
    global touser
    global msg
    touser=input("insert the destination email :")
    subject=input("enter the subject for your email")
    emailcon = input("enter your email ")
    msg="TO :"+touser+"/n"+subject:"+subject+"/n"+emailcon
    
def sendemail():
    global touser
    global msg
    server.sendmail("write your email here",touser,msg)
    
    
button1.when_pressed=userinput
button2.when_pressed=sendemail


pause()