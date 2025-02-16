# Nested (list) array/matrix
a = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
b = [[9, 8, 7], [6, 5, 4], [3, 2, 1]]
c = []

for i in range(len(a)):
    print("Length of rho: {}".format(len(a[i])))
    # string interpolation (similar to c# using @)
    print(f"Length of rho (f-string) {len(a[i])}")
    print(a[i])
    s = []
    for j in range(len(a[0])):
        s.append(a[i][j] + b[i][j])
        print(f"s array length is {len(s)} since we appended {s}")

    c.append(s)

print("Final array (c) is:\n", c)

# Just for fun - transpose a matrix:
rhos = len(a)
cols = len(a[0])
newMatrix = []

for i in range(cols):
    s = []
    for j in range(rhos):
        s.append(a[j][i])
        print(s)

    newMatrix.append(s)

print(newMatrix)
