myList = [1, 2 , 3, 4, 5, 6]
reverseList = []

len = len(myList)
i = 0

while i < len:
    reverseList.append(myList[-1])
    del(myList[-1])
    i += 1

print(reverseList)
