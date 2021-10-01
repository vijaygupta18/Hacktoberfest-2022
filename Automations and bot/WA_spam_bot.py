import time
import tkinter as tk
from tkinter import *
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

def startBombing():
    victim=str(name.get())
    msg=str(message.get())
    num=msgCount.get()
    driver=webdriver.Chrome('enter you path here example of a path : [C:/Users/91728/Desktop/pythonProject/chromedriver.exe] ')
    driver.get("https://web.whatsapp.com/")

    time.sleep(15)
    user=driver.find_element_by_xpath('//span[@title = "'+victim+'"]')
    user.click()

    msg_box=driver.find_element_by_xpath('//*[@id="main"]/footer/div[1]/div[2]/div/div[2]')
    for i in range(num):
        msg_box.send_keys(msg)
        msg_box.send_keys(Keys.ENTER)


#GUI
root=tk.Tk()
root.title("Whatsapp Bombing")
root.geometry("500x500")
root.resizable(height=False,width=False)

headingLabel=Label(root,text="Wait for 15 - 30 sec to start BOOM!",font=('Helvetics',12,'bold'))
headingLabel.place(relx=.5,y=15,anchor='center')

# victim name label
Label(root,text="Enter Name/No.").place(x=120,y=80)
name=StringVar()
nameBox=Entry(root,textvariable=name).place(x=220,y=80)
#  Msg label
Label(root,text="Enter Message").place(x=120,y=150)
message=StringVar()
msgBox=Entry(root,textvariable=message).place(x=220,y=150)

Label(root,text="No Of Message").place(x=120,y=220)
msgCount=IntVar()
countBox=Entry(root,textvariable=msgCount).place(x=220,y=220)
tk.Button(root,text="Start Bombing",command=startBombing).place(relx=.5,y=300,anchor="center")
root.mainloop()