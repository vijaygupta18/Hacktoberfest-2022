numbers = []
num = str(input("enter the number: "))
numbers.append(num)
for num in numbers:
    if len(num)==13 or len(num)==12:
        if num.startswith('+91'):
            print(num," is indian. ")
        elif num.startswith('0'):
            print(num," is indian. ")
        elif num.startswith('+1'):
            print(num," is U.S.")
    elif len(num)<12:
        print(num," is not valid")