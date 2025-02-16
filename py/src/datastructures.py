from collections import Counter, deque
from array import *

L = ["Mark", "Wamba", "Mark", "Paul", "Paul", "Mark"]
c = Counter(L)
print(c)
print(c["Mark"])
print(c.get("Paul"))
c.update({"Fubar": 4})
print(f"Most common: {c.most_common()}")
print(c)
print(c.pop("Mark"))
print(c)

# Queue - FIFO

d = [1, 2, 3, 4, 5]
print("deque can work FIFO or as a stack LIFO")
q = deque(d)
q.append(6)
q.appendleft(7)
print(q)
q.popleft()
print(q)
q.extendleft([11, 22, 33, 44])
print(q)
q.rotate(2)
print(f"Rotate right side by 2: {q}")
q.remove(4)
print(q)

print("Array is homogeneous; List is heterogeneous")
L = [10, "Hello", 12.5]
A = array("i", [10, 20, 30, 40])
s1 = b"abcdef"
ar2 = array("b", s1)
print(ar2)
