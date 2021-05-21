# Chatbot – random-only version
# this chat bot looks smart and sava your replies when you talk to it
import random

random_replies = ["Oh really?",
"Are you sure about that?",
"Hmmmmm.",
"Interesting...",
"I'm not sure I agree with that...",
"Definitely!",
"Maybe!",
"So what are you saying, exactly?",
"Meaning what?",
"You're probably right.",
"Rubbish! Absolute nonsense!",
"Anyway, what are your plans for tomorrow?",
"I was just thinking exactly the same.",
"That seems to be a popular viewpoint.",
"A lot of people have been telling me that.",
"Wonderful!",
"That could be a bit embarrassing!",
"ahem!",
"Do you really think so?",
"Indeed...",
"My point exactly!",
"Perhaps..."]

chat_dict = {"happy": "I'm happy today too!",
"sad": "Tell me all about it.",
"raspberry": "Oh yum! I love raspberries!",
"computer": "Computers will take over the world! You're already talking to one",
"music": "Have you heard the latest Depeche Mode album?",
"art": "But what is art really, anyway?",
"joke": "I only know this joke: How do you kill a circus? Go for the juggler.",
"python": "I hate snakes!",
"stupid": "Who are you calling stupid, jelly brain?",
"weather": "I wonder if the sun will shine on Saturday?",
#"you": "Leave me out of this!",
"certain": "How can you be so confident?",
"talk": "You're all talk! Do something!",
"think": "You can overthink these things, though.",
"hello": "Why, hello to you too, buddy!",
"wearing": "I don't wear clothes. I don't even come with a case.",
"bye": "...",
"how are you ? ":"im great , you?"}

def dictionary_check(message):
	message = message.lower()
	user_words = message.split()
	smart_replies = []
	for each_word in user_words:
		if each_word in chat_dict:
			answer = chat_dict[each_word]
			smart_replies.append(answer)
	if smart_replies:
		reply_chosen = random.randint (1, len(smart_replies)) - 1
		return smart_replies[reply_chosen]
	else:
		return ""



	
print("What's on your mind?")	
user_says = ""
while user_says != "bye":
	user_says = ""
	while user_says == "":
		user_says = input("Talk to me: ")
	smart_response = dictionary_check(user_says)
	if smart_response:
		print(smart_response)
	else:
		reply_chosen = random.randint(1, len(random_replies)) - 1
		print(random_replies[reply_chosen])
		random_replies[reply_chosen] = user_says

print("Goodbye. Thanks for chatting today. Drop in again soon!")
