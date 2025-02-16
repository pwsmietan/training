import math
import statistics as s

n = [1, 2, 3, 4, 5, 6]
v = [2, 2, 2, 3, 3, 3, 8, 8, 8]
print(f"Dataset: {n}")
print(f"Mean: {s.mean(n)}")
print(f"Harmonic Mean: {s.harmonic_mean(n)}")
print(f"Median: {s.median(n)}")
print(f"Median High: {s.median_high(n)}")
print(f"Median Low: {s.median_low(n)}")
print(f"Mode of {v}: {s.mode(v)}")
print(f"Variance Sigma(n-mean**2)/count of {n} {s.variance(n)}")
print(f"Standard Deviation of population: {s.pstdev(n)}")
print(f"Standard Deviation: {s.stdev(n)}")
