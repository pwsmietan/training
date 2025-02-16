print("Lambda (anonymous) Functions")
m2k = lambda milesTokm: 1.6 * milesTokm
print(f"{m2k(10)} kms")

f = lambda a, b: a**b
print(f(10, 5))

c = lambda a, b: a if a > b else 0
print(c(10, 5))
