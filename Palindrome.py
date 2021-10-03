def palindrome(a):
	if(a == a[::-1]):
		return True
	else:
		return False

n = input("Enter a string or number: ")
if(palindrome(n)):
	print("Palindrome")
else:
	print("Not Palindrome")
