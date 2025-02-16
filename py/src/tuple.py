# lists are defined using []
# tuples use () and are immutable
# scalar tuples require trailing ','
t1 = (123,)
print(t1)
t2 = tuple((1, 2, 3))
print(len(t2))

# packing a tuple (applicable to lists, strings)
a = 1, 2, 3, 4, 5
print(type(a))
# unpack into scalar integers:
b, c, d, e, f = a
print(b)

# tuple comprehension (using shorthand):
L1 = [x for x in range(20)]
T1 = tuple(x for x in range(20))
print("List: ", L1)
print("Tuple: ", T1)

# more shorthand notation for constructing a tuple with trailing ','
T2=(*(x for x in range(10)),)
print("T2: ", T2)
# but using tuple() is cleaner:
T3=tuple(x for x in "PyThOn" if x.islower())
print("T3: ", T3)
# can use 'x' as value reference:
T4 = tuple(x**2 for x in (1,2,3,4,5))
print("T4: ", T4)
# tuples have methods:
print(T4.count(1))
