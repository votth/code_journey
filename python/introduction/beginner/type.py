myInt = 7
print(myInt)

myFloat = 7.0
myFloat2 = float(7)
print(myFloat, myFloat2)

# Using quote "" will be easier to include apostrophes '' within strings and vice-versa
myString = 'Hello'
myString2 = "Hello"
print(myString, myString2)

print('"Yes", they said')
print("\"Yes\", they said")

# r makes it so that string is considered as `raw`
print(r'C:\some\path')

print("""\
Usage: thingy [OPTIONS]
     -h                        Display this usage message
     -H hostname               Hostname to connect to
""")

print(3 * 'un' + 'ium')

text = ('Multiple lines can be broken up'
        'by using this')

prefix = 'Py'
# prefix 'thon'
prefix + 'thon'

word = 'Python'
print(word[0], word[5],
      word[-1], word[-6])
print(word[0:2], word[:2])
