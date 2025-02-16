import numpy as np
import random

L = [1, 3, 5, 7, 9]
ar = np.array([1, 3, 5, 7, 9])
ar2 = np.array([[1, 3, 5, 7, 9], [11, 22, 33, 44, 55]])
ar3 = np.array([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])

print(
    f" One dimensional array shape of {ar.shape}:\n{ar}\nTwo dimensional array shape of {ar2.shape}:\n{ar2}\n"
)
print(f"Three dimensional shape of {ar3.shape}:\n{ar3}\n")

ar4 = np.array([1, 3, 5, 7, 9], ndmin=3)
print(
    f"Declared 3 dimensional array with shape of {ar4.shape} consuming {ar4.nbytes} bytes.\n{ar4}\n"
)

ar5 = np.array([[[[1, 2], [3, 4]], [[5, 6], [7, 8]]]])
print(f"Four dimensional array shape of {ar5.shape}\n{ar5}\n")

ar6 = np.zeros((3, 4))
ar7 = np.zeros((3, 4, 8))
print(f"Another {ar7.shape}\n{ar7}\n")
ar8 = ar7.reshape(3, 8, 4)
print(f"Reshaped {ar8.shape}\n{ar8}\n")

ar9 = np.eye(4)
print(f"Identity matrix: {ar9}\n")

ar10 = np.diag([2, 3, 4, 5])
print(f"Diagonal Matrix:\n{ar10}\n")

ar11 = np.arange(1, 10)
print(f"Arange function shape of {ar11.shape}\n{ar11}\n")

ar12 = np.linspace(0, 10, num=5)
print(f"Calculates array using intervals:\n{ar12}\n")

a = np.array([[1, 2], [3, 4], [5, 6], [7, 8], [9, 10]])
print(f"Numpy arrays can be sliced: \n{a[0:3:2]}")
print(f"Indexing a cell: {a[2,1]}")

f = ar2.flatten()
print(f"Arrays can be reshaped to 1 dimension using flatten(): {f}")

#x = random.choice([3, 5, 7, 9], p=[0.1, 0.3, 0.6, 0.0], size=100)
#print(x)
