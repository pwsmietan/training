l = float(input("Length: "))
b = float(input("Breadth: "))
h = float(input("Height: "))

fb = 2 * l * h
bt = 2 * l * b
lr = 2 * b * h

# this is more elegant with ()'s
total = 2 * ((l * h) + (l * b) + (b * h))

t = fb + bt + lr
print("t = ", t)
print("total = ", total)