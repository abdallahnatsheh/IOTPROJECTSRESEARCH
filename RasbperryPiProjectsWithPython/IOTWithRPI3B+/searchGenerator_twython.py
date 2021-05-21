#search twitter with twython library

from key import api_key,api_sec,ac_tk,ac_tk_sec
from twython import Twython

#create twython pbject
#must be in order
print("using api now")
twitter=Twython(api_key,api_sec,ac_tk,ac_tk_sec)

#search gen
print("searching..")
results = twitter.cursor(twitter.search, q='python')
for result in results:
    print(result)
