# Step 1 --> Make sure the terminal is having correct path to this folder
# Step 2 --> Run the command "python -m pip install -r requirements.txt"
# Step 3 --> Install PyAudio with "pip install PyAudio" if your python version is less than 3.6 or else Use this link
#            https://www.youtube.com/watch?v=UiPGi-Ewb2c&ab_channel=ProgrammingFever to download PyAudio with No error

# Now, The setup was completed

# First and the only Rule is "Only tell commands when the bot tells you to SPEAK NOW !!"

import pyttsx3
import speech_recognition as sr
import datetime
import webbrowser
import time
import random
import os
from googletrans import Translator
engine = pyttsx3.init("sapi5")
voices = engine.getProperty('voices')
engine.setProperty('voice',voices[1].id)  #To change the voice --> Use 1 for female and 0 for male

def talk(audio):
    engine.say(audio)
    engine.runAndWait()

def get_audio():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)
        print("Listening....")
        talk('Speak now')
        audio = r.listen(source)
        try:
            global speech
            speech=" "
            speech = r.recognize_google(audio)
            speech = speech.lower()
            print("You said: "+speech)
        except sr.UnknownValueError:
            x = "Sorry,I couldn't hear your voice"
            talk(x)
            print(x)
        except sr.RequestError:
            talk("Sorry , My API to recognize voice is down")
    return speech

def today_time():
    date = str(datetime.datetime.now().date())
    hour = str(datetime.datetime.now().hour)
    min = str(datetime.datetime.now().minute)
    sec = str(datetime.datetime.now().second)
    time=date+" "+hour+"hours "+min+"minutes "+sec+"seconds"
    return time

def get_audio_telugu():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)
        print("Listening....")
        talk("Speak now")
        audio = r.listen(source)
        try:
            global speech
            speech=" "
            speech = r.recognize_google(audio,language='te-IN')
            speech = speech.lower()
            print("You said: "+speech)
        except sr.UnknownValueError:
            x = "Sorry,I couldn't hear you"
            talk(x)
            print(x)
        except sr.RequestError:
            talk("Sorry , My API to recognize voice is down")
    return speech

def get_audio_hindi():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)
        print("Listening....")
        talk("Speak now")
        audio = r.listen(source)
        try:
            global speech
            speech=" "
            speech = r.recognize_google(audio,language='hi')
            speech = speech.lower()
            print("You said: "+speech)
        except sr.UnknownValueError:
            x = "Sorry,I couldn't hear you"
            talk(x)
            print(x)
        except sr.RequestError:
            talk("Sorry , My API to recognize voice is down")
    return speech

def trans_hindi():
    translator = Translator(service_urls=['translate.googleapis.com'])
    print("Vaibhav Assistant : What should I translate")
    talk("what Should I translate")
    trans_ = get_audio_hindi()
    results = translator.translate(trans_)
    Text = results.text
    return Text+" is the translated text"

def trans_telugu():
    translator = Translator(service_urls=['translate.googleapis.com'])
    print("Vaibhav Assistant : What should I translate")
    talk("what Should I translate")
    trans_ = get_audio_telugu()
    results = translator.translate(trans_)
    Text = results.text
    return Text+" is the translated text"

def coin_toss():
    print("Vaibhav Assistant : I am going to flip coin......!")
    talk("I am going to flip coin")
    result = random.choice(["Heads","Tails"])
    return result
#### Starts here
print("Vaibhav Assistant : Hello this is Vaibhav Assistant , the voice assisstant")
talk("Hello this is Vaibhav Assistant , the voice assisstant")
while True:
    text = get_audio()
    speak = "Sorry, I don't have reply for this"
    if "time" in text:
        X = today_time()
        speak = X
                
                
    elif "hello" in text or "hai" in text or "hey" in text:
        speak="Hello, Nice to hear your voice"
    elif "who are you" in text or "who created you" in text:
        speak = "Hello, I am Vaibhav Assistant, created by Gopi Vaibhav"
        
    elif "your name" in text:
        speak = "This is Vaibhav Assistant."
    elif "good morning" in text:
        speak="Good Morning, Have a nice day"
    elif "good afternoon" in text:
        speak="Good Afternoon, How are you?"
    
    elif "good evening" in text:
        speak="Good Evening, I hope you enjoyed your day"
    
    elif "good night" in text:
        speak="Good Night, I will be waiting for you"
    elif "who am i" in text:
        speak = "You are a Human"
    
    elif "where are you" in text:
        speak = "I am in your PC"
    
    elif "what are you doing" in text:
        speak = "I am waiting to help you"
    
    elif "what can you do" in text:
        speak = "I can do many things, Checkout my manual"
    elif "old are you" in text:
        speak = "I am 1 month old"
    
    elif "i love you" in text:
        speak = "Thanks, I love you too"
    elif "robot" in text:
        speak = "Yes, I am a robot"
    elif "my name" in text:
        speak = "I am really sorry, I dont remember your name"
        
    elif "why are you here" in text or "why did you come" in text:
        speak = "Because you activated me."

    elif "how are you" in text:
        speak =  "I am fine, Thank you!"
        speak += "\nWhat about you?"
                
    elif "i am good" in text or "i am fine" in text or "i am nice" in text:
        speak  ="cool , How can i help you?"
        
    elif "open" in text.lower():                
        if "whatsapp" in text.lower():
            speak = "opening whatsapp web in browser"
            webbrowser.open("https://web.whatsapp.com/")
            
        else:
            l=text.lower().split('open ')
            webbrowser.open("https://"+l[1]+".com")
            speak = " opening "+l[1]+" in browser"
            
    elif "youtube" in text.lower():
        ind = text.lower().split().index("youtube")
        search = text.split()[ind + 1:]
        webbrowser.open("https://www.youtube.com/results?search_query=" + "+".join(search))
        speak ="opening" + str(search) +  " on youtube "
                    
    elif "search" in text.lower():
        x = text.lower().split().index("search")
        y = text.split()[x + 1:]
        webbrowser.open("https://www.google.com/search?q="+"+".join(y))    
        speak ="searching" + str(y) + " on google"
        
            
    elif "where is" in text:
        a =  text.lower().split().index("is")
        location = text.split()[a +1: ]
        speak ="searching for "+str(location)
        webbrowser.open("https://www.google.com/maps/place/"+"+".join(location)) 
                    
    elif "don't listen" in text or "do not listen" in text:
        print("Vaibhav Assistant : How many seconds do you want me to sleep")
        talk("How many seconds do you want me to sleep?")
        a = int(get_audio())
        time.sleep(a)
        speak = str(a) + " seconds completed. Now you can ask me anything"
    
    elif "translate" in text:
        print("Vaibhav Assistant : What is the language you are going to speak?(Hindi or Telugu)")
        talk("What is the language you are going to speak?(Hindi or Telugu)")
        lang = get_audio()
        lang = lang.lower()
        if "hindi" in lang:
            speak=trans_hindi()
        else:
            speak=trans_telugu()
    elif "shutdown" in text or "shut down" in text :
        print("Vaibhav Assistant : Would you like to shutdown PC?(yes or no)")
        talk("Would you like to shutdown PC(yes or no)?")
        shutdown = get_audio()

        if shutdown == 'yes':
            talk("Shutting down PC")
            os.system("shutdown /s /t 1")
            
        else:
            print("Vaibhav Assistant : Request Cancelled")
            talk("request cancelled")
            continue
    
    elif "restart" in text:
        print("Vaibhav Assistant : Would you like to restart PC?(yes or no)")
        talk("Would you like to restart PC(yes or no)?")
        restart = get_audio()

        if restart == 'yes':
            talk("Restarting your PC")
            os.system("shutdown /r /t 1")
        else:
            print("Vaibhav Assistant : Request Cancelled")
            talk("request cancelled")
            continue
            
            
    elif "goodbye" in text or "bye" in text or "quit" in text or "exit" in text:
        print("Terminating Vaibhav Assistant")
        talk("......Terminating Vaibhav Assistant......")
        break 
    
    print("Vaibhav Assistant : "+speak)
    talk(speak)