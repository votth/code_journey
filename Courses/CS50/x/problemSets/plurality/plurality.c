#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // linear searching for match
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            // if found, then candidate at that 'i' index will be +1
            // and return function as true
            candidates[i].votes++;
            return true;
        }
    }
    // if the name isn't valid/not found
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // assume that the first candidate has the highest vote
    int max = candidates[0].votes;

    // since i=0 is already considered, i can now start with 1
    for (int i = 1; i < candidate_count; i++)
    {
        if (max < candidates[i].votes)
        {
            max = candidates[i].votes;
        }
    }

    // printing winner, and looping in case of multiple winners
    // else we can define a max_index and only print out candidates[max_index].name
    for (int i = 0; i < candidate_count; i++)
    {
        if (max == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}