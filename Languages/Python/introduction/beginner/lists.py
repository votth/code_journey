mylist = []
mylist.append(1)
mylist.append(2)
mylist.append(3)

print(mylist[0]) # prints list first element
print(mylist[1]) # prints list second element
print(mylist[2]) # prints list third element

# loop through elemets in mylist and do something
for x in mylist:
    print(x)


numberList = []
stringList = []

numberList.append(1)
numberList.append(2)
numberList.append(3)

stringList.append('hello')
stringList.append('world')

second_name = stringList[1]

print(numberList)
print(stringList)
print("The second name on the names list is %s" % second_name)
