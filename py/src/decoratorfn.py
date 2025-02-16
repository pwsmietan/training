def dec(fun):
    def wrapper(msg):
        print("*" * 10)
        fun(msg)
        print("*" * 10)

    return wrapper


@dec
def display(msg):
    print(msg)


print("By using the @ on [10] we convert display into a wrapper fn")
print("which wires up display() as the passed in fn")
# d = dec(display)
display("Decorator Functions take a fn as a parameter to inject into flow")
