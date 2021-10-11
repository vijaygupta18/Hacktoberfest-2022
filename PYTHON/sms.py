# Download the helper library from https://www.twilio.com/docs/python/install
import os
from twilio.rest import Client


# Find your Account SID and Auth Token at twilio.com/console
# and set the environment variables. See http://twil.io/secure
account_sid ='AC84dee919cfa8bf1cb805f6df64' 
auth_token = '998f90990f0a60c34998cfb3fa'
client = Client(account_sid, auth_token)


text = input("Enter Your Message   : ")
message = client.messages \
                .create(
                        body= f"{text}",
                     from_='twilio number',
                     to='number'
                 )

print(message.sid)

