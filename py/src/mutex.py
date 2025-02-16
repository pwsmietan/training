from threading import *
from time import *


def display():
    for i in range(65, 91):
        print(chr(i))
        sleep(1)


def display(str1):
    l.acquire(blocking=True)

    for x in str1:
        print(x)

    l.release()


# Classes invokes the run() method:
class Alphabets(Thread):
    def run(self):
        for i in range(65, 91):
            print(chr(i))
            sleep(0.1)


# t = Thread(target=display, name="Alphabets")
# t.start()

# t = Alphabets()
# t.start()

# for i in range(65, 91):
#     print(i)

# print("Block main thread until our new thread terminates")
# t.join()

print("Thread Synchronization\n")
print("MUTEX: Mutual Exclusion (create Lock mechanism)")

l = Lock()
print(f"Lock is: {l}")

# Create threads and pass in arguments as tuples:
t1 = Thread(target=display, args=("Hello World!",))
t2 = Thread(target=display, args=("\nAnd hello to you.",))

# Start our threads:
t1.start()
t2.start()
