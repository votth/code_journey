astring = "Hello World!"

print(len(astring))
print(astring.index("o"))

# astring[start:stop:step]
print(astring[3:7])

# C has strev to reverse string, here's the hack in Python
print(astring[::-1])

# astring.upper()
# astring.lower()

# Starts with and Ends with
# astring.startswith("Hello")
# astring.endswith("ajdfjfl")

# astring.split("[delimiter]")
splitted = astring.split(" ")
