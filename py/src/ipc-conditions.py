from threading import *
from time import *


class MyData:
    def __init__(self):
        self.data = 0
        self.cv = Condition()

    # producer
    def put(self, d):
        self.cv.acquire()
        self.cv.wait()
        self.data = d
        self.cv.notify()  # inform the consumer
        self.cv.release()

    # consumer
    def get(self):
        self.cv.acquire()
        self.cv.wait(timeout=0)
        x = self.data
        self.cv.notify()
        self.cv.release()
        return x


def producer(data):
    i = 1
    while True:
        data.put(i)
        print(f"Producer {i}")
        i += 1


def consumer(data):
    while True:
        x = data.get()
        print(f"Consumer {x}")


################################################################################
# BEGIN MAIN
################################################################################
print("Thread Synchronization\n")
print("Interprocess Communication - IPC")
print("Sharing resources between threads")

data = MyData()
t1 = Thread(target=lambda: producer(data))
t2 = Thread(target=lambda: consumer(data))

t1.start()
t2.start()

t1.join()
t2.join()
