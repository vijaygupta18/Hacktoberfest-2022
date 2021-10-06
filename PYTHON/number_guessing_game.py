from random import randint
flag=1
while(flag==1):
    a=int(input('Enter a number :: '))
    b=randint(0,9)
    if a==b:
        print('Numbers matched.\nYOU WON')
    else :
        print('Numbers didnt match')
        flag=int(input('Press 1 to try again. \n'))