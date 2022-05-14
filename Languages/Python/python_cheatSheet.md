[Python Cheatsheet](https://www.pythoncheatsheet.org/)


# Python basics

## Data types
Integers  
Floating-point numbers  
Strings

## Variables
- One word
- Only letters, numbers and underscores
- Can't begin with number
- Starting with underscore is considered as "unuseful". Not to be used again?

## Comments
`#`
``` python
a = 1  # pay attention to two spaces
```
`""" ... """` which is docstring, retains the lines, spaces format

## Input / Output
`print()` and `input()` functions.
``` python
print("Enter your name: ")
name = input()
print("Hello " + name + "!")
```

## len()
- returns length of strings in int
- should not be used for test of emptiness, but rather  
``` python
a = [1, 2, 3]
if a:
	print("List is not empty.")
```

## str(), int() and float()
Converter functions.
``` python
print('I am {} years old.'.format(str(29)))
```


# Flow control

## Comparision operators
Evaluate to `True` or `False`:
- `==` and `!=`
- `<` and `>`
- `<=` and `>=`

## Boolean evaluation
Always use `is` or `is not` with boolean
``` python
True Is True  # result True
# The followings are equivalent
if a is True:
	pass
if a is not False:
	pass
if a:
	pass
#
if a is False:
	pass
if a is not True:
	pass
if not a:
	pass
```

## Boolean operators: `and`, `or` and `not`

## `if`, `else` and `elif` statements
``` python
name = 'Bob'
age = 5
if name == 'Alice':
	print('Hi, Alice.')
elif age == 5:
	print('Are you Bob?')
else
	print('Hello stranger!')
```

## `while` loop statements
``` python
spam = 0
while spam < 5:
	print('Hello world')
	spam = spam + 1
```

## `break` statements: exit out of a loop when reached

## `continue` statements: jump back to start of the loop

## `for` loop and `range()`
``` python
print('Counting...')
for i in range(5):
	print('{}'.format(str(i)))
# will result in
# 0
# 1
# 2
# 3
# 4
```
range() can also be called with three arguments, which can also be used with negative:  
`range(start, stop, step)`

## `for else` statement
Allows to specify a statement to execute in case of the full loop has been executed. Only useful when a `break` condition occur in the loop.
``` python
for i in [1, 2, 3, 4, 5]:
	if i == 3:
		break
else:
	print('Only execute if there\'s no 3 in the list')
```

## Importing Modules
``` python
import random
for i in range(5):
	print(random.randint(1, 10))
```

``` python
import random, sys, os, math
```

``` python
from random import *
```

## Ending program early with `sys.exit()`
``` python
import sys
while True:
	print('Type exit to exit.')
	respone = input()
	if respone == 'exit':
		sys.exit()
	print('You typed {}.'.format(respone))
```

# Functions
``` python
def hello(name):
	print('Hello {}.'.format(name))

hello('Alice')
hello('Bob')
```

## Return values and return statements
When creating a func using the `def` keyword, you can specify what the return value should be with a return statement:
- `return` keyword
- value or expr that the func should return
``` python
import random
def getAnswer(answerNumber):
	if answerNumber == 1:
		return 'It is certain'
	elif answerNumber == 2:
		return 'It is decidedly so'
	elif answerNumber == 3:
		return 'Yes'

r = random.randint(1, 3)
fortune = getAnswer(r)
print(fortune)
```

## The `None` value

## Keyword Arguments and print()
``` python
print('Hello', end='')  # no endline
print('World')

print('cats', 'dogs', 'mice')
# cats dogs mice
# vs
# cats,dogs,mice
print('cats', 'dogs', 'mice', sep=',')
```

## Local and Global scope
- Code in global scope can't use any local variables.
- But a locale scope can access global variables.
- Code in a function's local scope cannot use variables in any other local scopes.
- You can use the same name for different variables if they are in different scopes.

## The global Statement
If you need to modify a global variable from within a func, use the global statement, `global`.
``` python
def spam():
	global eggs
	eggs = 'spam'

eggs = 'global'
spam()
print(eggs)
# spam
```


# Exception handling

## Basic exception handling
``` python
def spam(divideBy):
	try:
		return 42 / divideBy
	except ZeroDivisionError as e:
		print('Error: Invalid argument: {}.'.format(e))

print(spam(2))
print(spam(0))
print(spam(1))
# 21.0
# Error...
# None
# 42.0
```

## Final code in exception handling
Code inside `finally` section is always executed.
``` python
def spam(divideBy):
	try:
		return 42 / divideBy
	except ZeroDivisionError as e:
		print('Error: Invalid argument: {}.'.format(e))
	finally:
		print("--division finished--")

print(spam(2))
print(spam(0))
# --division finished--
# 21.0
# Error...
# --division finished--
# None
```


# Lists
``` python
spam = ['cat', 'bat', 'rat']
spam
# ['cat', 'bat', 'rat']
```

## Gettings values in List with indexes
``` python
spam[0]
# cat
spam[1]
# bat
spam[2]
# rat
# Negative indexes
spam[-1]
# rat
spam[-3]
# cat
```

## Getting Sublists with slices
``` python
spam.append('dog')
spam[0:3]
spam[:2]
spam[0:-1]
```

## Getting List's length
``` python
len(spam)
```

## Changing a List's value with index
``` python
spam[1] = 'hat'
```

## List concatenation and replication
``` python
[1, 2, 3] + ['A', 'B', 'C']
# [1, 2, 3, 'A', 'B', 'C']

[1, 2, 3] * 3
# [1, 2, 3, 1, 2, 3, 1, 2, 3]

spam = spam + ['A', 'B', 'C']
```

## Remove value with index using `del spam[i]` or `spam.pop[i]`

## Using `for` with Lists
``` python
supplies = ['pens', 'staplers', 'flame-throwers', 'binders']
for i, supply in enumerate(supplies):
	print('Index {} in supplies is: {}'.format(str(i), supply))
```

Looping multiple Lists with `zip()`
``` python
name = ['Pete', 'John', 'Eliza']
age [6, 23, 44]
for n, a in zip(name, age):
	print('{} is {} years old.'.format(n, str(a)))
```

## The `in` and `not in` operators
``` python
'howdy' in ['hello', 'hi', 'howdy']
# True
spam = ['hello', 'hi', 'howdy']
'howdy' in spam
# True
'meow' in spam
# False
'meow' not in spam
# True
```

## Multiple assigment trick
``` python
cat = ['fat', 'orange', 'loud']
size, color, disposition = cat
```

Can also be used to swap values
``` python
a, b = 'Alice', 'Bob'
a, b = b, a
```

## Augmented assignment operators
+=    -=    \*=    /=    \%=

## Finding index of a value
``` python
spam.index('cat')
# 0
```

## Adding values to Lists with `append(value)` and `insert(pos, value)`

## Removing values using `remove(value)`
If there're duplicates, only the first occurence will be removed.

## Sorting: `sort()`
``` python
spam.sort()
# Reverse
spam.sort(reverse=True)
# Alphabetical order, ignoring case
spam.sort(key=str.lower)
# Return a new list instead of changing
sorted(spam)
```

## Tuple Data Type
Main difference from Lists is that Tuples, likes strings are immutable.
``` python
egss = ('hello', 42, 0.5)
eggs = [0]  # 'hello'
eggs[1:3]   # (42, 0.5)
len(eggs)   # 3
```

## Converting types with `list()` and `tuple()`
``` python
tuple(['cat', 'dog'])
list(('cat', 'dog'))
```


# Dictionaries and Structuring Data
Keys and values pair.
``` python
myCat = {
	'size': 'fat',
	'color': 'gray',
	'disposition': 'loud'
}
```

## `key()`, `values()` and `items()` methods
By using these methods, a `for` loop can iterate over the keys, values, or key-value pairs in a Dict.
``` python
for v in myCat.values():
	print(v)
# fat
# gray
# loud

for k in myCat.keys():
	print(k)
# size
# color
# disposition

for i in myCat.items():
	print(i)
# ('size', 'fat')
# ('color', 'gray')
# ('disposition', 'loud')
```

## Checking if a key or value exists in a Dict
Using `in` and `not in` with `keys()` and `values()`.

## `get()` method
Getting value of a key if the key exists.  
Takes two arguments: key and default value if the key did not exist
`get('size', 0)  # 'fat'` and `get('jump', 0)  # 0`

## `setdefault()` method
Check if a key already exists in a Dict, if not then append it.
``` python
spam = {'name': 'Pooka', 'age': 5}
if 'color' not in spam:
	spam['color'] = 'black'
# same code but more succinctly
spam.setdefault('color', 'black')
```

## Pretty printing
``` python
import pprint
count = {}
# fill Dict count
pprint.pprint(count)
```

## Merging Dicts
``` python
# 3.5+
x = {}
y = {}
z = {**x, **y}
# 2.7
z = dict(x, **y)
```


# Sets
"A set is an unordered collection with no duplicate elements. Basic uses include membership testing and eliminating duplicate entries. Set objects also support mathematical operations like union, intersection, difference, and symmetric difference."

## Initializing a set
Using `{}` or `set()`.  
When creating an empty set, don't use `{}` since it will return an empty Dict instead.  
Cannot be indexed: `s[0]` will return error.  
Will automatically remove duplicates.
``` python
s = {1, 2, 3}
s = set([1, 2, 3])
```  
``` python
s = {1, 2, 3, 2, 3, 4}
s  # {1, 2, 3, 4}
```

## Set's `add()` and `update()`
Adding elements to the Set, singulary with `add()` or multiples with `update()`

## Set's `remove()` and `discard()`
Both will remove an element from the Set, `remove()` will raise a *key error* if the element doesn't exist.

## Set's `union()` or `|`
Will create a new set that contains all the elements from the Sets provided.
``` python
s1 = {1, 2, 3}
s2 = {4, 3, 5}
s1.union(s2)  # or s1 | s2
# {1, 2, 3, 4, 5}
```

## Set's `intersection()` or `&`
Return a set containing common elements of all provided Sets.

## Set's `symetric_difference` or `^`
Return a set containing non-common elements of all provided Sets.

## Set's `difference()` or `-`
Return a set containing unique elements of the first/invoked set.


# `itertools` module
The *itertools* module is a collection of tools intended to be fast and use memory efficiently when handling iterators (like Lists or Dicts).

## `accumulate()`
Makes an iterator taht returns the results of a function.  
`itertools.accumulate(iterable[, func])`
``` python
data = [1, 2, 3, 4, 5]
result = itertools.accumulate(data, operator.mul)
for each in result:
	print(each)
# 1			# operator.mul takes two numbers and multiplies them
# 2			# operator(1, 2)
# 6			# operator(2, 3)
# 24		# operator(6, 4)
# 120		# operator(24, 5)
```  
``` python
# default behavior is to sum the items
data = [5, 2, 6, 4, 5, 9, 1]
result = itertools.accumulate(data)
for each in result:
	print(each)  # 5 7 13 17 22 31 32
```

## `combinations()`
Takes an iterable and an integer and creates all the unique combination that have *r* members.  
`itertools.combinations(iterable, r)`
``` python
data = [1, 2, 3]
result = itertools.combinations(data, 2)
for each in result:
	print(each)  # (1,2) (1,3) (2,3)
```
## `combinations_with_replacement()`
Allows individual elements to be repeated more than once.  
(1,1) (1,2) (1,3) (2,2) (2,3) (3,3)

## `count()`
`itertools.count(start, step)`

## `cycle()`
Cycles through an iterator endlessly.
`itertools.cycle(iterable)`

## `chain()`
Takes a series of iterables and returns them as one long interable.
`itertools.chain(\*iterables)`

## `compress()`
Filters one iterable with another.
`itertools.compress(data, selectors)`
``` python
data = [1, 2, 3, 4, 5]
selectors = [True, False, True, False, True]
result = itertools.compress(data, selectors)
for each in result:
	print(each)  # 1 3 5
```

## `dropwhile()`
Makes an iterator that drops elements from the itarable as long as the predicate is true; afterwards, returns every element.
`itertools.dropwhile(predicate, iterable)`
``` python
data = [1, 2, 3, 4, 5, 6, 7, 1]
result = itertools.dropwhile(lambda x: x < 5, data)
for each in result:
	print(each)  # 5 6 7 1
```

## `filterfalse()`
Makes an iterator that filters elements from the iterable returning only those for which the predicate is false.
``` python
result = itertools.filterfalse(lambda x: x < 5, data)
# 5 6 7
```

## `groupby()`
`itertools.groupby(iterable, key = None)`


# Comprehensions

## List comprehension
``` python
a = [1, 3, 5, 7, 9, 11]
[i - 1 for i in a]
# [0, 2, 4, 6, 8, 10]
```

## Set comprehension
``` python
b = {"abc", "def"}
{s.upper() for s in b}
# {"ABC", "DEF"}
```

## Dict comprehension
``` python
c = {
	'name': 'Pooka',
	'age': 5
}
{v: k for k, v in c.items()}
# {'Pooka': 'name', 5: 'age'}
```
List comprehension from a Dict
``` python
c = {'name': 'Pooka', 'first_name': 'Oooka'}
["{}:{}".format(k.upper(), v.upper()) for k, v in c.items()]
# ['NAME:POOKA', 'FIRST_NAME:OOOKA']
```
