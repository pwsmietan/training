d = dict()
z = {}
print("\nDictionaries can be defined using dict() class or empty {} braces.")
print(f"Type of d is {type(d)} and type of z is {type(z)}")

d["apple"] = "red"
d["mango"] = "yellow"
print(d)

print("Dictionaries are cool and mutable!")
for x in range(1, 6):
    d[x] = x**2

print(d)

l1 = ["A", "B", "C"]
l2 = ["apple", "ball", "cat", "foo"]
print(f"Zip up (integrate) two iterables: {
      l1} and {l2} disregarding odd # of values.")
d3 = dict(zip(l1, l2))
print(d3)

print("Enumerating through a list:")
l3 = ["a", "b", "c"]
for item in enumerate(l3):
    print(item)


d5 = dict(enumerate(l3))
print(f"Creating a dictionary from an enumerated list: {d5}")

d6 = {x: x**2 for x in range(1, 5)}
print(f"Dictionary using range {d6}")

t1 = {(x, x**2) for x in range(1, 5)}
print(f"Using a ',' returns a set: {type(t1)}")

d7 = dict((x, x**2) for x in range(1, 5))
print(f"Using dict() returns a dictionary: {type(d7)} \n{d7}")

print("Iterate through two lists zip'ed up:")
for x, y in zip(l1, l2):
    print(x, y)

print("Same two lists/tuple zip'd up with cool x: key/value syntax")
d8 = {x: y for x, y in zip(l1, l2)}
print(d8)

print("\nNow enumerate through list:")
for x, y in enumerate(l2):
    print(x, y)

d9 = {x: y for x, y in enumerate(l2)}
print(f"x:y syntax {d9}")

# tuple uses dict()
d10 = dict((x, y) for x, y in enumerate(l2))
print(f"x,y using dict() {d10}")

print("Dictionary get() which is safer over indexing - no exception on illegal key:")
for x in d:
    print(x, d.get(x))

print("Nice way to specify return key error message:")
print(d.get(1000, "Invalid Key"))

print(f"Keys: {d.keys()}")
print(f"Values: {d.values()}")
print(f"Items: {d.items()}")

print("Creating shallow copy - copies by reference")
e = d.copy()
print(f"Address/ID of d[0]: {id(d['apple'])}")
print(f"Address/ID of e[0]: {id(e['apple'])}")

print("Updating one dictionary with another")
f = {"pear": "tan"}
f.update(e)
print(f)

print("Set a default key of dictionary to 1")
f.setdefault(1)
print(f)
f.setdefault(4500)
print(f)

print(f"Get legal key: {f.get(1)}")
print(f"Get illegal key: {f.get(111)}")

l1 = [1, 2, 3, 4]
print(f"Create a dictionary from list: {l1}")
g = {}
print(f"FromKeys: {g.fromkeys(l1)}")

f.pop(1)
print(f"Pop key #1: {f}")

print("Add key foo")
f[99] = 'foo'
print(f)
print("pop last item inserted")
f.popitem()
print(f)

f.clear()
print(f"All cleared: {f}")
