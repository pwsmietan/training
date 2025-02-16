import bisect

L = [10, 20, 30, 40, 50, 60, 70, 80, 90]
print(L)
bisect.insort(L, 25)
print(L)

bisect.insort_left(L, 99)
print(L)

bisect.insort_right(L, 98)
print(L)

print(
    f"What position would 5 be (should be 0th since it's the smallest value)? {bisect.bisect(L,5)}"
)
