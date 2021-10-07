import random

num = random.randint(1, 10)
no_of_guesses = 5
guess = None
i = 1
print("You Have 5 Guesses. Guess a number between 1 and 10")
while guess != num and no_of_guesses>=i:
    print(f"take your guess no {i}:",end =" ")
    guess = int(input())
    i+=1

    if guess == num:
        print("congratulations! you won!")
        break
    elif i>no_of_guesses:
        print("Opps! guesses are up, play again")
    else:
        print("nope, sorry. try again!")

    

