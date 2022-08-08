import re

# User's input
s = input("Text: ")

# Count letters
letters = 0
for c in s:
    if c.isalpha():
        letters += 1
# Count words: by using str.split()
words = len(s.split())
# Count sentences: with delimeters . ? and !
# !! the space after them is important for differentiating with things like 5.5
sentences = len(re.split('\. |\? |! ', s))

# Calculate the index
L = letters / words * 100
S = sentences / words * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

# Priting grade
if index > 16:
    print("Grade 16+")
elif index > 1:
    print(f"Grade {index}")
else:
    print("Before Grade 1")