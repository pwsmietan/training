class MyCustomError(Exception):
    # Do some cool recovery code here ...
    def __init__(self, *args: object) -> None:
        super().__init__(*args)

    def __str__(self) -> str:
        return super().__str__()


L = [10, 20, 30, 40, 50]

try:
    idx = int(input("Enter Index: "))
    print(L[idx])

    # trigger the divide by 0 exception:
    # 1 / 0

    print("EOT")
except (IndexError, ValueError) as eX:
    print(f"Index Error: {eX}")
except ZeroDivisionError as eX:
    print(f"Divide by 0: {eX}")
except:
    print("Default Exception!")
else:
    print("In Else as long as there is NO exception.")
finally:
    print("Finally we're here regardless whether is an exception or not.")

# Custom Error Class
try:
    raise MyCustomError("Oh no! Calling custom error class.",
                        "And now we're a tuple!")
except MyCustomError as e:
    print(e)

print("EOJ")
