class NumberHolder:

    # is called when the class is being initiated. It's used for asigning values in a class
    def __init__(self, number):
        self.number = number

    def returnNumber(self):
        return self.number

var = NumberHolder(7)
print (var.returnNumber()) # this will print out number 7
