import copy

L = [10, 20, 30, 40, 50]
L1 = copy.copy(L)
L2 = copy.deepcopy(L)

print("All objects will have unique addresses in memory.")
print(f"Address of L: {id(L)}; L1 (Shallow Copy): {id(L1)}; L2 (Deep Copy): {id(L2)}\n")
print("Addresses of each 0th element:")
print(
    f"Address of L[0]: {id(L[0])} and address of L1[0]: {id(L1[0])} and address of L2[0]: {id(L2[0])}"
)
