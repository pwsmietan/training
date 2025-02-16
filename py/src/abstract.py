# Python has a built-in Abstract Base Class (ABC) which is kind of cool:
from abc import ABC, abstractmethod


class Parent(ABC):
    @abstractmethod
    def show(self):
        pass

    def display(self):
        print("I'm a concrete method - parent display")


class Child(Parent):
    # Override the parent's abstract method:
    def show(self):
        print("Show from child class")


c = Child()
c.show()
c.display()
