print("Similar to arrays, but using keys and values instead of ixdexes to call for its elements")

phoneBook = {}
phoneBook["John"] = 291834
phoneBook["Jack"] = 1092384
phoneBook["Jill"] = 1239847
print(phoneBook)

phoneBook2 = {
        "John": 102384,
        "Jack": 109283,
        "Jill": 4823947
}
print(phoneBook2)

# deleting an element/index
# use either of the following
del phoneBook["John"]
phoneBook.pop("John")

for name, number in phoneBook.items():
    print("Phone number of %s is %d" % (name, number))
