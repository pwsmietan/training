def MyCommonFn():
    print("My common function!")


def disp(msg):
    print(msg)


def add(x, y):
    print(x + y)


def sqrSigma(x, y):
    print((x + y) ** 2)


# Cover function calls another function by reference:
def coverFn(f, x, y):
    f(x, y)


# Function Factory
def Outer():
    def Inner():
        print("Inner fn called!\n")

    return Inner


class Department:
    def __init__(self):
        self.depts = {"hr": "Human Resource", "sa": "Sales", "en": "Engineering"}

    # caller class
    def __call__(self, dept):
        return self.depts[dept]


"""
A Closure in Python is a function object that remembers values in enclosing scopes even if they are not present in memory. 

It is a record that stores a function together with an environment: a mapping associating each free variable of the 
function (variables that are used locally but defined in an enclosing scope) with the value or reference to which the name 
was bound when the closure was created.
A closure—unlike a plain function—allows the function to access those captured variables through the closure’s 
copies of their values or references, even when the function is invoked outside their scope.
"""


def Depts():
    depts = {"hr": "Human Resource", "sa": "Sales", "en": "Engineering"}

    def dname(dept):
        return depts[dept]

    # return the function without parenthesis (like a pointer to a fn)
    return dname


# alias fn
display = disp
display("In Common")
