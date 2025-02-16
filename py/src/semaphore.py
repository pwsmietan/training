from threading import *
from time import *

print("Thread Synchronization\n")
print("Semaphore")


def display(str1):
    l.acquire(blocking=True)

    for x in str1:
        print(x)
        sleep(0.1)

    l.release()


# When semaphore is decremented to 0 no thread is allowed inside a function.
# Multiple semaphores may exist and represent multiple threads (which can introduce a race condition).
l = Semaphore(1)
print(f"Semaphore is: {l}")

# Create threads and pass in arguments as tuples:
t1 = Thread(target=display, args=("Hello World!",))
t2 = Thread(target=display, args=("\nAnd hello to you.",))
t3 = Thread(target=display, args=("\nBut don't forget about me!",))

# Start our threads:
t1.start()
t2.start()
t3.start()

t1.join()
t2.join()
t3.join()
