import serialization, pickle


students = [
    serialization.Student(10, "John", "cs"),
    serialization.Student(20, "Paul", "music"),
    serialization.Student(30, "Tom", "Eng"),
]

# pickle up our object:
with open("students.data", "wb") as f:
    for s in students:
        pickle.dump(s, f)

# unpickle object:
with open("students.data", "rb") as g:
    for i in range(3):
        s = pickle.load(g)
        s.display()
