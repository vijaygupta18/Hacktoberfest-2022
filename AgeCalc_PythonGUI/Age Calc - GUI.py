from tkinter import *
from datetime import date

t=Tk()
t.title("AGE CALCULATOR")

def calc():
    curr=date.today().year
    val=int(ent.get())
    if val> curr:
        message["text"]="INVALID YEAR"
    else:
        message["text"]= f"You are {curr-val} years old!"

t.geometry("500x500")
h1=Label(t, text="AGE CALCULATOR")
h1.pack()

h2=Label(t, text="Enter your year of birth")
h2.pack()


ent= Entry(t)
ent.pack()
btn=Button(t, text=" Calculate away!", width=12, command= calc)
btn.pack()

message=Label(t, text="")
message.pack()

t.mainloop()