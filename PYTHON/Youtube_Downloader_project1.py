from tkinter import * 
from pytube import YouTube
root = Tk()
root.geometry("800x700")
root.title("Youtube video downloader")
Label(root,text = 'Youtube Video Downloader', font ='arial 20 bold').pack()


video_link = StringVar()


Label(root, text="Paste link here:", font="Arial 25 bold", bg="green").place(x=160, y=60)
link_enter = Entry(root, width=80, textvariable=video_link).place(x=40,y=200)

def Downloader():
    url = YouTube(str(video_link.get()))
    video = url.streams.first()
    video.download()
    Label(root, text="Download completed!", font="Arial 25 bold", bg="light pink").place(x=180,y=150)
    
Button(root,text = 'DOWNLOAD', font = 'arial 15 bold' ,bg = 'pale violet red', padx = 2, command = Downloader).place(x=180 ,y = 150)

root.mainloop()




