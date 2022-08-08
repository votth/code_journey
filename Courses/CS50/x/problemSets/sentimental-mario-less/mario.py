# Handling input error
while True:
    try:
        # Forcing int type for 'input'
        n = int(input("Height: "))
        # Only accept value between 1-8
        if n in range(1, 9):
            break
        else:
            print("Please provide an int between 1-8")
    except ValueError:
        print("That is not an int")
# Loop through floors
for i in range(n):
    print((n - 1 - i) * " " + (i + 1) * "#")