# An example of encapsulation, inheritance, and polymorphism concepts.
# Here three classes named Simon, Sally and Ruby are inherited from class Cat.
# Polymorphism concept is shown by Pets and Cat class, since it is using same methods <walk>
# which is performing different actions. And also by three cats which are
# using same method <action> for different purpose.

class Pets():
    animals = []

    def __init__(self, animals):
        self.animals = animals

    def walk(self):
        for animal in self.animals:
            print(animal.walk())


class Cat():
    is_lazy = True

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def walk(self):
        return f'{self.name} is just walking around'


class Simon(Cat):  # inheritance
    def action(self, char):
        return f'{self.name} is {char}'


class Sally(Cat):  # inheritance
    def action(self, char):
        return f'{self.name} is {char}'


class Ruby(Cat):   # inheritance
    def action(self, char):
        return f'{self.name} is {char}'


# creating three cat instances
s = Simon('Simon', 12)
S = Sally('Sally', 10)
R = Ruby('Ruby', 13)
my_cat = [s, S, R]

my_pets = Pets(my_cat)  # Instantiating the Pets class
my_pets.walk()          # Polymorphism
print(s.action("jumping"))
