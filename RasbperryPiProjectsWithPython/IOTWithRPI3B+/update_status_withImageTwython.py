#tweet an image with twython library

from key import api_key,api_sec,ac_tk,ac_tk_sec
from twython import Twython

#create twython pbject
#must be in order
print("using api now")
twitter=Twython(api_key,api_sec,ac_tk,ac_tk_sec)

#update with image

photo = open('/home/pi/Pictures/watch_dogs.jpg', 'rb')
response = twitter.upload_media(media=photo)
twitter.update_status(status='Checkout this cool image!', media_ids=[response['media_id']])
