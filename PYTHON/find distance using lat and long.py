from tkinter import *
from math import *
#-----------------------------

def EquiRectDist(lat1,long1,lat2,long2):
    R=6371*(10**3)#radius of earth
    x=(long2-long1)*cos((lat1+lat2)/2)
    y=lat2-lat1
    d=sqrt((pow(x,2))+pow(y,2))*R
    return d
    
def EquiRectDistDeg(lat1,long1,lat2,long2):
    return (EquiRectDist(radians(lat1),radians(long1),radians(lat2),radians(long2)))

def calculate():
    lat1=float(e1.get())
    long1=float(e2.get())
    lat2=float(e3.get())
    long2=float(e4.get())
    Z.set(EquiRectDistDeg(lat1,long1,lat2,long2))

    
    


#----------------------------
#Main Page
#----------------------------
window=Tk()
window.title("distance using latitude and longitutude")

#30.516077
#76.659649
#48.814668
#2.213897
l1=Label(window,text="lat1:")
l1.grid(row=0,column=0)

l2=Label(window,text="long1:")
l2.grid(row=1,column=0)

l3=Label(window,text="lat2:")
l3.grid(row=2,column=0)

l4=Label(window,text="long2:")
l4.grid(row=3,column=0)

e1=Entry(window,bg="lightblue")
e1.grid(row=0,column=1)

e2=Entry(window,bg="lightgreen")
e2.grid(row=1,column=1)

e3=Entry(window,bg="orange")
e3.grid(row=2,column=1)

e4=Entry(window,bg="lightpink")
e4.grid(row=3,column=1)

b1=Button(window,text="Quit",command=quit) #in other terminal we use window.destroy()
b1.grid(row=4,column=0)

b2=Button(window,text="Calculate",command=calculate)
b2.grid(row=4,column=2)

Z=StringVar()
l6=Label(window,textvariable=Z)
l6.grid(row=5,column=1)

