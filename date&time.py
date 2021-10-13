# write a program to display current date and time

import datetime
now = datetime.datetime.now()
print("The current date and time is")
print(now.strftime("%d-%m-%Y %H:%M:%S"))
