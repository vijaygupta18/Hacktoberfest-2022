import random
import smtplib
sender="email@gmail.com"
rec=input("Enter a valid Email address :: ")

otp_ls=[]
for i in range(6):
    otp_ls.append(str(random.randint(0,9)))
otp=""
otp="".join(otp_ls)
message=str(otp)

server=smtplib.SMTP("smtp.gmail.com",587)
server.starttls()
server.login(sender,"password")
server.sendmail(sender,rec,message)

confirm_otp=input("Enter OTP form your mail  :: ")
if confirm_otp==otp:
    print("OTP MATCHED.")
else :
    print("Try Again")