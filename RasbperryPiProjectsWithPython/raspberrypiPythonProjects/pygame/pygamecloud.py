#simple pygame on raspberry pi

import random
WIDTH = 500
HEIGHT = 500
score = 0
timer = 10
clouds = list()

for i in range(6):
	filename = 'target' + str(i)
	clouds.append(Actor(filename))
	this_cloud = clouds[i]
	this_cloud.x = random.randint(int(this_cloud.width / 2), int(WIDTH - this_cloud.width / 2))
	this_cloud.y = HEIGHT + this_cloud.height
	animate(this_cloud, tween='linear',duration=random.uniform(1, 3),pos=(this_cloud.x + random.randint(10, 100), -200))

def draw():
	screen.clear()
	for i in range(6):
		this_cloud = clouds[i]
		this_cloud.draw()
		
	screen.draw.text("Score: " + str(score), (2, 2), color="orange")
	screen.draw.text("Timer: " + str(timer), (WIDTH - 70, 2), color="orange")

	if timer == 0:
		screen.draw.text(str(score), (130, 120), color="white", fontsize=300)

def update():
	for i in range(6):
		this_cloud = clouds[i]
		if this_cloud.y < 0 - this_cloud.height:
			this_cloud.y = HEIGHT + this_cloud.height
			if timer > 0:
				this_cloud.x = random.randint(int(this_cloud.width / 2),int(WIDTH - this_cloud.width / 2))
				this_cloud.image = 'target' + str(i)
				animate(this_cloud, tween='linear', duration=random.uniform(1, 3),pos=(this_cloud.x + random.randint(10,100), -200))

def on_mouse_down(pos):
	global score
	for i in range(6):
		this_cloud = clouds[i]
		if this_cloud.collidepoint(pos) and timer > 0 and this_cloud.image != 'pop':
			this_cloud.image = 'pop'
			sounds.blop.play()
			score += 1
def countdown():
	global timer
	timer -= 1
	if timer == 0:
		clock.unschedule(countdown)
		sounds.whoops.play()
		
clock.schedule_interval(countdown, 1)
