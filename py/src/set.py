# sets use {} but don't do slicing/indexing.
# sets support heterogeneous data and are unordered.
a = {1, 2, "pws", 3, "psh"}

# b = set((1, 3, 5))
# The following is the "unwrapped" version of line 5:
b = {1, 3, 5}
c = set("python")  # makes iterable

s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
t = {1, 2, 3, 5, 7}
u = {5, 7, 9, 10, 11}

b.discard(3)
b.add(133)
print("Mod: ", b)

# more cool set methods:
print(f"t={t} and u={u}")
print(f"t union u = {t|u}")
print(f"t intersection u = {t&u}")
print(f"t difference u = {t-u}")
print(f"t symmetric difference u = {t^u}")
print(f"t subset of s = {t<s}")
print(f"s superset of t = {s>t}")
print(f"3 in t {3 in t}")
print(f"4 not in t {4 not in t}")

# union assignment
t |= u
print(f"t: {t}")

# update() can take lists and sets - adds unique values only:
t.update((9, 10, 11, 99))
print(f"Updated t: {t}\n")

print("Set comprehensions")
s2 = {x**2 for x in [-2, -1, 0, 1, 2]}
print(f"s2 using list - set returns uniques: {s2}")
s3 = {x for x in (10, 5, 7, 8, 12, 3) if x % 2 == 0}
print(f"s3 passing in tuple: {s3}")

print("set only stored non-mutable objects.  unhashable types, ex. list, nested sets\n")

