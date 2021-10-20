"""We are given a sorted list of integers... Arrange the squares of the digits in sorted order
NOTE:-- Complexity Must be O(n)
"""

data = list(map(int, input().split(" ")))

front, rear = 0, len(data) - 1

final = [0] * len(data)

ind = len(data) - 1
# print(final)

while front <= rear:
    a, b = data[front] * data[front], data[rear] * data[rear]
    print(a, b)
    if a >= b:
        final[ind] += a
        front += 1
    elif b >= a:
        final[ind] += b
        rear -= 1
    ind -= 1
    print(final)
