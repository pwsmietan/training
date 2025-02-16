import timeit
import re

print("*" * 10)

a = "fbscplezk"
print(sorted(a))
b = "".join(sorted(a))
print(b)

email = "paul@smietan.com"
print(email.split("@"))

p = "madam"
p_rev = p[::-1]
print("Reveral is palindrome? ", p_rev)

my_list = ["apple", "banana", "cherry", "date"]
print(my_list[0])  # slice index origin 0
print(my_list[1:3])  # slicing output: ['banana', 'cherry'] (1..3-1)
print(my_list[:2])  # slicing output: ['apple', 'banana'] (0..2-1)
print(my_list[2:])  # slicing output: ['cherry', 'date'] (2..n)

# indexing to string:
sentence = "The quick brown fox jumps over the lazy dog"
first_word = sentence[:3]
second_word = sentence[4:9]
third_word = sentence[10:15]
print(first_word)
print(second_word)  # output: "quick"
print(third_word)  # output: "brown"

print("Reveral", sentence[::-1])

# Nice way of subscripting ever 2nd item:
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
odd_numbers = numbers[::2]
print(odd_numbers)  # output: [1, 3, 5, 7, 9]

even_numbers = numbers[1::2]
print(even_numbers)  # output: [2, 4, 6, 8]

print("\n2D arrays")
data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(data, "\n")

column = [row[1] for row in data]
column_0 = [row[0] for row in data]
column_2 = [row[2] for row in data]
print("Col 0\n", column_0)  # output: [1, 4, 7]
print("Col 1\n", column)  # output: [2, 5, 8]
print("Col 2\n", column_2)  # output: [3, 6, 9]

print("\nmodify data:")
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print(numbers)
numbers[1:4] = [10, 20, 30]
print(numbers)  # output: [1, 10, 20, 30, 5, 6, 7, 8, 9]

print("Inserting:")
numbers[4:4] = [40, 50]
print(numbers)  # output: [1, 10, 20, 30, 40, 50, 5, 6, 7, 8, 9]
# implied insertion within vector (will not destroy existing values)
numbers[0:3] = [10, 30, 60, 90, 120]
print("vector insertion:", numbers)
numbers.extend([101, 102, 103])
print("vector extend():", numbers)
numbers.pop()
print("vector pop():", numbers)
del numbers[0:3]
print("vector del[0:3]:", numbers)
numbers.remove(9)
print("vector remove occurance of 9:", numbers)

print("List Comprehension aka short-hand")
L3 = [x for x in (10, 5, 7, 8, 12, 3) if x % 2 == 0]
print("Short-hand assignment using iterable L3: ", L3)

L4 = [x for x in "afu875^&*lpPP***" if x.isalpha()]
print("Another short-hand with filter L4: ", L4)

print("Nested Lists")
NL = [10, 20, ["a", "b", ["c", "d"]], 30, 40]
print("Our nested list: ", NL)
print("Len: ", len(NL))
print("NL[1][0]: ", NL[1])

foo = "0123456"
print(foo[3::-1])
first_4_items_reversed = slice(3, None, -1)
print(first_4_items_reversed)

stop_idx = 0
start_idx = 3

foo[stop_idx : start_idx + 1][::-1]
foo[start_idx : stop_idx - len(foo) - 1 : -1]

t1 = timeit.timeit(
    "foo[stop_idx:start_idx+1][::-1]",
    setup='foo="012345"; stop_idx=0; start_idx=3',
    number=10_000_000,
)
print("Timer 1: ", t1)

t2 = timeit.timeit(
    "foo[start_idx:stop_idx-len(foo)-1:-1]",
    setup='foo="012345"; stop_idx=0; start_idx=3',
    number=10_000_000,
)
print("Timer 2: ", t2)
# support c-style formating although we need to use % for separator:
print("The diff is %2.2f of the timers." % (t1 - t2))
# can also use string.format for palceholders:
print("Diff is {0:2.4}".format(t1 - t2))

# r" " denotes raw string:
str = "Hello World"
x = r"^Hell"
re.compile(x, 0)
r1 = re.match(x, str)
print("r1:", r1)
r = re.search(x, "Hello World")
if r:
    print("Yes!")
else:
    print("No :-()")
