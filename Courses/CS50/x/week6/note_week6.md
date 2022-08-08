---
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
output: pdf_document
---
# Python
## some samples
- no print*f*, and no semi-colon, free newline
``` python
# get_string is from cs50 library
answer = get_string("What's your name? ")
print("Hello, " + answer)
# f"..." formatted string, will translate {} into it's value
print(f"Hello, {answer}")
```
- no counter++ in python, only counter += 1
- conditional: pay attention to indentation, no () for if
``` python
if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```
- while
``` python
while True:
    print("meow")

i = 0
while i < 3:
    print("meow")
    i += 1

# for i in [0, 1, 2]:
for i in range(3):
    print("meow")
```
## data types
- bool, float, int (no overflow), str
- new data types: range, list, tuple, dict, set, etc.
## libraries
import cs50

from cs50 import some_function
## complier
- no complilation step
- "python is being interpreted, not complied" = can skip the complilation step
- might be slower without compling
``` bash
python hello.py
```
## pre-built functions
- equivalence of the blur problem with filter.c
``` python
from PIL import Image, ImageFilter

before = Image.open("bride.bmp")
after = before.filter(ImageFilter.BoxBlur(1))
after.save("out.bmp")
```
- using more . (dots) since OOP - object oriented programming
- functions can be incapsulated in "structs" - objects
- equivalence of speller problem with dicitonary.c
``` python
words = set()

def check(word):
    if word.lower() in words:
	return True
    else
	return False

def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
	word = line.rstrip()
	words.add(word)
    file.close()
    return True

def size():
    return len(words)

def unload():
    return True
```
-
    - trade-off: faster implementation of code for the programmer but has a lower runtime for the program
    - though can sitll be optimized and defends largely on the use case of each languages

# Writing Python
## docs.python.org
## print 'Hello, {user}'
``` python
from cs50 import get_string

# answer = get_string("What is your name? ")
answer = input("What is your name? ")

print(f"Hello, {answer})
```
vs
``` c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What is your name? ");
    printf("Hello, %s\n", answer);
}
```
## calculator
``` python
import cs50

x = cs50.get_int("x: ")
y = cs50.get_int("y: ")

print(x + y)
```
``` python
# will take input as string by default
# x = input("x: ")
# y = input("y: ")
x = int(input("x: ")
y = int(input("y: ")

print(x + y)
```
## exceptions
- try to do something except if something goes wrong
``` python
try:
    x = int(input("x: "))
except ValueError:
    print("That is not an int!")
    exit()
# and similary for y
```
## floating-number problem
- 0.1 = 0 in C if it's an int
``` python
from cs50 import get_int 

x = get_int("x: ")
y = get_int("y: ")

z = x / y
# Though Python solves one of the problem, it still has underflow
printf("{z:.50f}")
```
## agree
``` python
from cs50 import get_string

s = get_string("Do you agree? ").lower() # to both get_string and convert it to lowercase

if s in ["y", "yes"]:
    print("Agreed.")
elif s in ["n", "no"]:
    print("Not agreed.")
```
- string
    - conceptual yes but under-the-hood isn't really array of characters
    - they are *immutable* now, meaning can't change individual characters
## loop
``` python
def main():
    meow(3)

def meow(n):
    for i in range(n):
	print("meow")

main() # unlike in C where main() is mandatory and is automatically called, you have to call for main() in Python
```
- there's no do-while, do
``` python
while True:
    # something something
    if # something you want:
	break
```
``` python
def get_height():
    while True:
	# wiht Python, user can recover from their wrong input if it's in a loop, won't crash the whole program and stops it
	try:
	    n = int(input("n: "))
	    if n > 0:
		break
	except ValueError:
	    print("That's not an integer!")
    return n
```
-
    - return n here can still work eventhough n was declared in the loop
	- different from C, in Python, once a variable is declared, it's available for use anywhere in the function
	- while in C, declaration in a loop will only work for that loop
	- for better or for worse type of feature

## no newline
- positional arguments: printf("Hello, " + "world"); the ones in "" are positional
- no newline
``` python
for i in range(4)
    # By default, by the end= is hidden
    # print("?", end="\n")
    # For no newline
    print("?", end="")
print()
# or just
print("?" * 4)
```
## scores
``` python
from cs50 import get_int

scores = []
for i in range(3):
    score = get_int("Score: ")
    scores.append(score)
    # or
    scores += [score]

average = sum(scores) / len(scores)
print(f"Average: {average}"
```
## UPPERCASE
``` python
from cs50 import get_string

before = get_string("Before: ")
# print("After: ", end="")
# for c in before:
#     print(c.upper(), end="")
# print()
after = before.upper()
printf(f"After: {after}")
# {before.upper()} works too but careful not to make the line too long and unreadable
```
## argv
``` python
from sys import argv

if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")

###

for arg in argv:
    print(arg)
```
## slicing
- argv[:]
    - [1:] from 1 to end
    - [:] from 0 to end
    - [:-1] from 0 to end-1
## exit()
``` python
import sys

if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

print(f"hello, {sys.arg[1]}")
sys.exit(0)
```
## searching
- linear
``` python
import sys

numbers = [4, 6, 8, 2, 7, 5, 0]
names = ["Bill", "Charlie", "Fred"]

if 0 in numbers:
    print("Found")
    sys.exit(0)

print("Not found")
sys.exit(1)


if "Ron" in names:
    print("Found")
    sys.exit(0)
print("Not found")
sys.exit(1)
```
## dictionary
``` python
from cs50 import get_string

# This is a dict(ionary)
people = {
    "Carter": "645645",
    "David": "879340"
}

name = get_string("Name: ")
if name in people:
    number = people[name]
    print(f"Number: {number}")
```
## CSV - comma-separated values
``` python
import csv
from cs50 import get_string

# file = open("phonebook.csv", "a")
# 
# name = get_string("Name: ")
# number = get_string("Number: ")
# 
# writer = csv.write(file)
# writer.writerow([name, number])
# 
# file.close()

name = get_string("Name: ")
number = get_string("Number: ")
# So you don't accidentally close opened file too soon, and don't forget since Python will do it for you with "with"
with open("phonebook.csv", "a") as file:

    writer = csv.write(file)
    writer.writerow([name, number])
```

# Syntax
## Lists
- basically arrays
- declaration:
``` python
    nums = []
    nums = list()
    nums = [x for x in range(500)] # 0-499
```
- append
``` python
    # 5 is the value/new element
    # 4 is the index of where to insert
    nums.append(5)
    nums.insert(4, 5)
    # from the last value of nums list, append the new list to it
    nums[len(nums):] = [5]
```
## Tuples
- an ordered, immutable sets of data: their values are likely never change
- iterable
``` python
presidents = [
    ("George Washington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Madison", 1809)
]

for prez, year in presidents:
    print("In {1}, {0} took office".format(prez, year))
```
## Dictionaries
- allowing you to specify list indices with words or phrases ***keys***, instead of integer, which were restricted to in C
``` python
pizzas = {
    "cheese": 9,
    "pepperoni": 10,
    "vegetable": 11,
    "buffalo chicken": 12
}
# Changing keys' value
pizzas["cheese"] = 8
# Add new keys
pizzas["bacon"] = 4
```
- !problem: can't interate through dict, since it doesn't have idexes
- !! Loops (redux): the *for* loop in Python is extremely flexible
``` python
for pie in pizzas:
    # pie is like i, used for looping

# Prints ingrediences
for pie in pizzas:
    print(pie)
# Prints keys value
# .items() transform dict into list
# !! the order will not necessary be retained
# but pairing is kept
for pie, price in pizzas.items():
    print(price)
# Prints both ingrediences with their prices
for pie, price in pizzas.items():
    print("A whole {} pizza cost ${}".format(pie, price))
```
## Functions
- no need to specify return types or type of arguments (ditto)
- declartion:
    - using main(): main is not automatically defined, so you must do it! And when you're using main, the following must be at the end
    ``` python
    if __name__ == "__main__":
	main()
    ```
    - declare with ***def*** keyword
    ``` python
    def square(x):
	return x**
    ```
## Objects
- object-oriented programming *OOP*
- Object is sort of analogous to a C structure
    - In C, structures contain a number of *fields*, which might be also called *properties*: but those properties can not stand alone
    ``` c
    struct car
    {
	int year;
	char *model;
    }

    struct car herbie;
    herbie.year = 1963;
    herbie.model = "Beetle"; // has to have herbie. for model to work
    ```
    - In Python
	    - objects have properties and also *methods*, or functions that are inherent to the object, and mean nothing outside of it.
	    - methods are defined within the object
	    - properties and methods don't ever stand on their own
	    - ~~function(object)~~ is incorrect
	    - object.method() is correct

- Declaration
    - ***class*** keyword
    - Classes require an initializtion funciton, called *constructor*, which sets the starting values of the properties of the object
    - while defining each method of an object, *self* should be its first parameter, which stipulates on what object the method is called
``` python
class Student():

    def __init__(self, name, id):
	self.name = name
	self.id = id

    def changeID(self, id):
	self.id = id

    def print(self):
	print("{} = {}".format(self.name, self.id))

def main():
    jane = Student("Jane", 10)
    jane.print()
    jane.changeID(11)
    jane.print()


if __name__ == "main":
    main()
```
# Misc
## Styles
- syntax and style are very very important in Python
- !!tabs and indentation
## Including files
from \<something> import \<some_function>
## Shebang
> #!/usr/bin/env python3
    - to avoid having to type python \<program_name> everytime
> chmod +100 \<program_name>
