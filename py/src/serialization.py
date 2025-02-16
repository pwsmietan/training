# serialization: pickle and unpickle


class Student:
    def __init__(self, roll, name, dept):
        self.roll = roll
        self.name = name
        self.dept = dept

    def display(self):
        print(f"Roll: {self.roll}\nName: {self.name}\nDept: {self.dept}")
