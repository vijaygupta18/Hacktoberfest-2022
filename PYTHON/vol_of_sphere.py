# Write a python program to get the volume of a sphere with radius input from user

from math import pi

r = int(input("Enter the radius of sphere:"))
v = 4.0/3.0*pi*r**3
print("The volume of sphere is:",v)
