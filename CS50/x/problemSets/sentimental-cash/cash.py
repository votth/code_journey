from cs50 import get_float

# Handling user input
while True:
    owed = get_float("Change owed: ")
    if (owed >= 0):
        break
# after subtracting the floating value keeps being 0.15(9)
owedPrecision = owed * 100

# Set up for coins value
coins = [0.25, 0.1, 0.05, 0.01]
change = 0

# Loop to check
for i in coins:
    while owedPrecision >= i * 100:
        owedPrecision -= i * 100
        change += 1

# Print result
print(change)