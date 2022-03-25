print("Objects are an encapsulation of variables and functions into a single entity. Objects get their variables and functions from classes. Classes are essentially a template to create your objects.")

class MyClass:
    variable = "blah"

    def function(self):
        print("This is a message inside the class.")

myObjectX = MyClass()
myObjectY = MyClass()

myObjectY.variable = "gibberish"

print("\n" + myObjectX.variable)
print("\n" + myObjectY.variable)

myObjectX.function()
