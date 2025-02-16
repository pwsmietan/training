class cuboid:
    # Constructor:
    def __init__(self, l=1, b=1, h=1):
        self.length = l
        self.breadth = b
        self.height = h

    def area(self):
        return self.length * self.length

    def total(self):
        return 2 * (
            self.length * self.breadth + self.breadth * self.height + self.height
        )

    def volume(self):
        return self.length * self.breadth * self.height


# Inheritance
class Cube(cuboid):
    def __init__(self, l=1, b=1, h=1):
        super().__init__(l, b, h)

    def volume(self):
        return super().volume()


class Duck:
    def talk(self):
        print("Quack!")

    def walk(self):
        print("Duck walking ... quack quack!")


class Dog:
    def talk(self):
        print("Woof!")

    def walk(self):
        print("Dog walking ... bark bark!")


class Lilly(Dog):
    def talk(self, msg):
        print(f"Lilly says Grumpffff and {msg}")
        # To call base method:
        # super().talk()


def Pet(pet):
    pet.talk()
    pet.walk()


def SuperPet(pet):
    pet.talk("BARK!")
    pet.walk()


class Rational:
    def __init__(self, p=1, q=1):
        self.p = p
        self.q = q

    # Overload the add primitive
    def __add__(self, other):
        s = Rational()
        s.p = self.p * other.q + self.q * other.p
        s.q = self.q * other.q
        return s


r1 = Rational(2, 3)
r2 = Rational(2, 5)
sum = r1 + r2
print(sum.p, sum.q)

p = Duck()
Pet(p)

print("No need for a new keyword ... implied")
Pet(Dog())

SuperPet(Lilly())

print("Instantiate")
c1 = cuboid(10, 5, 3)
print(c1.volume())

print("Inheritance")
c2 = Cube(10, 20, 30)
print(c2.volume())
