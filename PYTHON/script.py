
import pandas as pd
import smtplib

with smtplib.SMTP('smtp.gmail.com', 587) as smtp:
    smtp.ehlo()
    smtp.starttls()
    smtp.ehlo()

    # Enter the maild id and password of the mail from which you want to send
    smtp.login('your_mail_id', 'your_password')

    # reading the spreadsheet
    email_list = pd.read_excel('emails.py\mails.xlsx')
  
    # reading emails
    emails = email_list['EMAIL']

    for i in range(len(emails)):

        #iterate through mail ids
        email=emails[i]

        # Eneter the subject and body of the mail accordingly

        subject = "Hey Welcome to MLSC"
        body = 'Glad to have you onboard'

        message = f'Subject: {subject} \n\n {body}'

        smtp.sendmail(' Enter your_mail_id', [email], message)

    smtp.close()