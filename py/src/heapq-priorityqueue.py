import heapq

print("heapq - priority queue")
H = []  # create empty list to populate
heapq.heappush(H, 10)
heapq.heappush(H, 20)
heapq.heappush(H, 50)
heapq.heappush(H, 40)
heapq.heappush(H, 60)
heapq.heappush(H, 30)
heapq.heappush(H, 70)
heapq.heappush(H, 11)

print("heapq automatically gets sorted")
print(H.count)
print(H)
print("Now we'll pop LIFO")
heapq.heappop(H)
print(H.count)
print(H)

print("Using heapify() to treat a list as a heapq")
L = [50, 30, 66, 40, 70, 50, 60, 3]
heapq.heapify(L)
print(f"List remains a {type(L)}")
print(L)
print("What's the smallest first 3 values?")
print(heapq.nsmallest(3, L))
