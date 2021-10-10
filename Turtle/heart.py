import turtle


t = turtle.Turtle()
t.speed(1)
t.begin_fill()
t.fillcolor("red")
t.color("red")
t.pensize(10)
t.left(140)
t.forward(180)

t.circle(-90, 200)
t.left(120)
t.circle(-90, 200)
t.forward(180)
t.end_fill()
t.getscreen()._root.mainloop()
