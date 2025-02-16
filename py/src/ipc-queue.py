# Queue's are cool - hold multiple values!
from threading import *
from time import *
from queue import *


def producer(que):
    i = 1
    while True:
        q.put(i)
        print(f"Producer {i}")
        i += 1
        sleep(1)


def consumer(que):
    while True:
        x = q.get()
        print(f"Consumer {x}")
        sleep(1)


################################################################################
# BEGIN MAIN
################################################################################
print("Thread Synchronization\n")
print("Interprocess Communication - IPC")
print("Sharing resources using Queue object")
q = Queue()

t1 = Thread(target=lambda: producer(q))
t2 = Thread(target=lambda: consumer(q))

t1.start()
t2.start()

t1.join()
t2.join()
