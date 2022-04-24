class Vehicle:

    def __init__(self, name, kind, color, value):
        self.name = name
        self.kind = "car"
        self.color = color
        self.value = value

    def description(self):
        desc_str = "%s is a %s %s worth $%.2f." % (self.name, self.color, self.kind, self.value)
        return desc_str

# # my code
# car1 = Vehicle()
# car1.name = "Fer"
# car1.color = "red"
# car1.value = 60000
car1 = Vehicle("Fer", "car", "red", 60000)

# test code
print(car1.description())
# print(car2.description())

