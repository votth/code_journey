import sys
import re


def main():
    # User input, 'credit' here is string!!
    credit = input("Number: ")

    # Handling with regex
    # Visa 13-digit or 16-digit and start with 4
    if re.search("^(4+\d{12}|4+\d{15})$", credit):
        if luhn_algo(credit):
            print("VISA")
            sys.exit(0)
    # AMEX 15-digit start with 34 or 37
    if re.search("^(34|37)+\d{13}$", credit):
        if luhn_algo(credit):
            print("AMEX")
            sys.exit(0)
    # MC 16-digit start with in range(51:56)
    if re.search("^(51|52|53|54|55)+\d{14}$", credit):
        if luhn_algo(credit):
            print("MASTERCARD")
            sys.exit(0)

    # Default outcome
    print("INVALID")
    sys.exit(1)


def luhn_algo(credit):

    sum = 0
    # String 0 index but counting backward
    reverse = len(credit) * -1 + 1

    # Go through credit's letter from start to end with step of 2
    # !! going from start-end is wrong, since the algo goes from end to start
    for num in credit[-2:reverse:2]:
        # Convert to int and multiply by 2
        num = int(num) * 2
        # Convert back to str so for in works
        num = str(num)
        for digit in num:
            sum += int(digit)

    # Add the untouched digits
    for digit in credit[-1:reverse:2]:
        sum += int(digit)

    if sum % 10 == 0:
        return True
    else:
        return False


main()