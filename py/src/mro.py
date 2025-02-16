# Method Resolution Order intrinsic function
# depth first left->right order
class A:
    def show(self):
        print("A")


class B(A):
    pass


class X:
    pass


class Y(X):
    pass


# Multiple Inheritance
class C(B, Y):
    pass


class D(B):
    # def show(self):
    #     print("D")
    pass


###############################################################################################
# BEGIN CODE
###############################################################################################
b = B()
b.show()
print(f"Dump of method resolution order:\n{B.mro()}")


c = C()
c.show()
print(f"Dump of method resolution order:\n{C.mro()}")


d = D()
d.show()
print(f"Dump of method resolution order:\n{D.mro()}")
