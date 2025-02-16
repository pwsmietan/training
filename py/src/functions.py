from os import system, name


def cls():
    if name == "nt":
        _ = system("cls")
    else:
        _ = system("clear")


def addItem(item, L=None):
    """
    This function appends a list item
    """
    print(f"Address of argument L: {id(L)}")
    L.append(item)
    return L


# args a and b are positional
# the slash denotes that following args can be any/either (positional or by keyword)
# the asterisk denotes the following args are referenced by keyword
def add(a, b, /, c, d, *, e, f):
    print(a)
    return a + b


def variableLengthArgs(*args):
    print(type(args), args)


# variable number of keyword arguments returned as dictionary type:
def keywordVariableLengthArgs(**kwargs):
    print(type(kwargs), kwargs)


def mixedArgs(a, b, *args, **kwargs):
    print(a, b, args, kwargs)


def upk(a, b, c, d):
    print(a, b, c, d)


def addMultiple(a, b, c):
    return a + 1, b + 1, c + 1


# Begin test code:
cls()

L1 = [1, 2, 3, 4]
L2 = [1, 2, 3, 4]
print(f"\n\nAddress of L1: {id(L1)} containing: {L1}")
addItem(5, L1)
print(L1)

print("\nArgument Fun :-)")
print(add(2, 5, 4, d=99, e=100, f=2.2))

print("Variable number of arguments")
variableLengthArgs(1, 2, 3)
variableLengthArgs(1, 2, 3, 4, 5, 6)
variableLengthArgs(1, 2, 3, 4, 5, 6, "pws")

print("Calling function to unpack list->ints")
upk(*L2)

print("Multiple return values from a fn")
x, y, z = addMultiple(10, 20, 31)
print(x, y, z)
print("Multiple return values from a fn call explicit result into tuple")
t = addMultiple(33, 44, 55)
print(t)

print("Variable keyword based arguments:")
keywordVariableLengthArgs(a=1, b=2)
