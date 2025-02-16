def Days():
    print("Generators")
    G = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]

    i = 0
    while True:
        x = G[i]
        i = (i + 1) % 7
        yield x


print("Iterator Fun()")
L1 = {1: "a", 2: "b", 3: "c"}
itr = iter(L1)
print(itr)
print(next(itr))
print(next(itr))
print(next(itr))

d = Days()
print(next(d))
print(next(d))
print(next(d))
print(next(d))
print(next(d))
print(next(d))
print(next(d))
