import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py databases/<csv> sequences/<txt>")
        sys.exit(1)

    # Read database file into a variable
    with open(sys.argv[1], "r") as db:
        r_db = csv.reader(db)
        database = []
        for row in r_db:
            database.append(row)
    # extract subsequences from the first line
    subseqs = []
    # i starting from 1 to skip over 'name'
    for i in range(1, len(database[0])):
        subseqs.append(database[0][i])

    # Read DNA sequence file into a variable
    # sinces the txt has only 1 line, read that line directly to a variable
    with open(sys.argv[2], "r") as dna:
        seq = dna.read().rstrip()

    # Find longest match of each STR in DNA sequence
    count = []
    for subseq in subseqs:
        count.append(str(longest_match(seq, subseq)))

    # Check database for matching profiles
    # database[1:] to skip over first line
    for entry in database[1:]:
        # skip over entry[0] which are the names
        if entry[1:] == count:
            print(entry[0])
            sys.exit(0)

    print("No match")
    sys.exit(1)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
