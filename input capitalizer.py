# Write a Python program to
# input a string and change its
# case to Sentence case using capitalize()
# function. It will convert only the first
# (beginning)lower case letter to upper case.
# it will capitalize only first letter
# of a Sentence.
# The user will enter String
# during program execution

# Start of the Python program

# display message to enter string
# and get input string
str1 = input("Enter a string to convert into Sentence case:")


# use capitalize() method
sentence_string = str1.capitalize()

# now print UPPER CASE string
print(str1, "In sentence case =", sentence_string)
