#tweet automation with twython library

from key import api_key,api_sec,ac_tk,ac_tk_sec
from twython import Twython

#create twython pbject
#must be in order
print("using api now")
twitter=Twython(api_key,api_sec,ac_tk,ac_tk_sec)

#updating status 
print("using statuts")
twitter.update_status(status='hi this is test to tweet from my rpi using python ')
