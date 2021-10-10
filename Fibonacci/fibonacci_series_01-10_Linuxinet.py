
# Program to display the Fibonacci sequence up to n-th term By Linuxinet 01-10-2021

nterms = int(input("How many terms? "))

# first two terms
n1, n2 = 0, 1
count = 0

# check if the number of terms is valid
if nterms <= 0:
   print("Please enter a positive integer")
# if there is only one term, return n1
elif nterms == 1:
   print("Fibonacci sequence upto",nterms,":")
   print(n1)
# generate fibonacci sequence
else:
   print("Fibonacci sequence:")
   while count < nterms:
       print(n1)
       nth = n1 + n2
       # update values
       n1 = n2
       n2 = nth
       count += 1

      
      
#fibonacci alternative

def fibb(a,b,n):
   if(n>0):
      print(a)
      fibb(b,a+b,n-1)

n = int(input("Enter number of terms: "))
fibb(0,1,n)
