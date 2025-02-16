import math
import fractions
import random

print("Fractions support multiple types:")
f1 = fractions.Fraction(1, 2)
print("1/2: {}".format(f1))
f2 = fractions.Fraction(0.2)
print(f"Float 0.2: {f2}")
print(f"Limited denominator: {f2.limit_denominator(10)}")
f3 = fractions.Fraction("0.3")
print(f"decimal 0.3: {f3}")

print("Tuple -> Fractions:")
L = [(1, 2), (4, 9), (6, 8), (3, 3), (9, 16), (13, 3)]
for n, d in L:
    print("{}".format(fractions.Fraction(n, d)))

print(f"Our list: {L}")
random.shuffle(L)
print(f"Shuffle up our list: {L}\n")

print("Random Seeds:")
for i in range(0, 3):
    print(f"Seed: {random.random()}")
    print(f"Between 1..12: {random.uniform(1,20)}")
    print(f"int 1..10: {random.randint(1,10)}")
    print(f"range 1..111 steps of 3: {random.randrange(1,111,3)}")
    print(f"My choice is: {random.choice(L)}")
    print(f"My choices are: {random.choices(L,k=2)}")
    print(f"Random bits 2**3: {random.getrandbits(3)}")

u = 2
v = 12.578
w = 35
x = 21
y = 50
a = [1, 2, 3, 4, 5]
b = 256
print(f"Ceiling {v}: {math.ceil(v)}")
print(f"Floor {v}: {math.floor(v)}")
print(f"FABS {-v}: {math.fabs(-v)}")
print(f"FMOD {u,v}: {math.fmod(v,u)}")
print(f"Remainder {u,v}: {math.remainder(v,u)}")
print(f"Factorial {u*7}: {math.factorial(u*7)}")
print(f"Greatest Command Divisor {w,x}: {math.gcd(w,x)}")
print(f"Permutations (!n/(n-k)): {y,u}: {math.perm(y,u)}")
print(f"Combinations (!n/!k*(n-k))): {y,u}: {math.comb(y,u)}")
print(f"Product {a}: {math.prod(a)}")
print(f"Sum/Sigma {a}: {math.fsum(a)}")
print(f"Radians {w}: {math.radians(w)}")
print(f"Radians {180}: {math.radians(180)}")
print(f"SIN {w}: {math.sin(math.radians(w))} theta.")
print(f"COS {w}: {math.cos(math.radians(w))} theta.")
print(f"TAN {w}: {math.tan(math.radians(w))} theta.")

print(
    "\nThe logarithm of a number x to the base b is the exponent to which b must be raised to produce x."
)
# For example, since 1000 = 103, the logarithm base 10 of 1000 is 3,
# or log10 (1000) = 3. The logarithm of x to base b is denoted as logb (x),
# or without parentheses, logb x. When the base is clear from the
# context or is irrelevant it is sometimes written log x.")
print(f"LOG base 2 {b} return 2**{math.log2(b)}")
