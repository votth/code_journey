# Handling input error
while True:
    try:
        n = int(input("Height: "))
        if n in range(1, 9):
            break
        else:
            print("Please provide an int between 1-8")
    except ValueError:
        print("That is not an int")

# Loop through floors
for i in range(n):
    # Print out first half
    print((n - 1 - i) * " " + (i + 1) * "#", end="")
    # Print spacer: 2 spaces
    print("  ", end="")
    # Print the other half and go to next floor
    print((i + 1) * "#")