def ir():
    for i in range(1, 10, 2):
        print(i)


def even(x):
    if x % 2 == 0:
        return True
    else:
        return False


print("Byte is immutable; bytearray is mutable")

s1 = "NT7PS"
ba = bytearray(s1.encode())
print(f"Raw bytearray: {ba}")

ba.append(84)
for i in ba:
    print(f"ASCII Code: {i}")

print(f"Is function object callable? {callable(ir)}")
print(f"Is var callable? {callable(ba)}")

q, r = divmod(11, 3)
print(f"divmod() returns tuple: quotient {q} remainder {r}")

e = enumerate(s1)
for i in e:
    print(i)

print(eval("3 * 10 + 15 / 3"))

f = 'print("fubar")'
exec(f)

L = [3, 6, 7, 9, 12, 14, 19, 21]
f = filter(even, L)
for i in f:
    print(i)

print("Lambda is visually clean:")
f = filter(lambda x: x > 10, L)
for i in f:
    print(i)


fz = frozenset(L)
# fz[0] = 4         ---- can't do this. Immutable object!
print(fz)
