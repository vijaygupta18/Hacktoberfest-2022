#Password Generator in Python --by Deepanshu Mittal
#python 3

#import libraries: random and string
import random
import string

print("PASSWORD GENERATOR IN PYTHON")

#Input the desired length of the password from the user
len_of_pass = int(input("\nEnter the length of the paasword: "))

#Form the strings containing specific type of character using 'string' module
low_char = string.ascii_lowercase
up_char = string.ascii_uppercase
numbers = string.digits
symbols = string.punctuation

#Input the types of characters user want in the password
types_input = input("\nEnter\n 1- For using lower case alphabets in the password\n 2- For using upper case letters in the password\n 3- For using digits in password\n 4- For using symbols in the password\n Enter space separated numbers according to your need in the password\n")
types= types_input.split(' ')

#Form a string containing all required types of characters only
string=""
for i in types:
    if(i=='1'):
        string += low_char
    elif(i=='2'):
        string += up_char
    elif(i=='3'):
        string += numbers
    elif(i=='4'):
        string += symbols
    else:
        print("Invalid inputs")
        exit()

#Length of string containing all required types of characters
len_of_str = len(string)

#Password string initialised
password = ""

#Using 'randrange' function of 'random' module we will generate a random password using characters from the string
for i in range(len_of_pass):
    password += string[random.randrange(len_of_str)]

#Print the generated password
print("\nPassword Generated: ",password)