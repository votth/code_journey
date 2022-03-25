#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // going through candidates list
    for (int j = 0; j < candidate_count; j++)
    {
        // if there's a match
        if (strcmp(name, candidates[j].name) == 0)
        {
            // then save the voting preferences of voter 'voter'
            // i is the index of the candidate in the 'struct candidates'
            preferences[voter][rank] = j;
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // going through the voters list
    for (int i = 0; i < voter_count; i++)
    {
        // going through the vote 'i' pref. list
        for (int j = 0; j < candidate_count; j++)
        {
            // finding the most pref. candiate, who has not been eliminated
            if (!candidates[preferences[i][j]].eliminated)
            {
                candidates[preferences[i][j]].votes ++;
                // break out of the for loop
                break;
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // calculating the winning number of votes
    int win_vote = voter_count / 2;

    for (int j = 0; j < candidate_count; j++)
    {
        // if somone has more than half the number of votes
        if (candidates[j].votes > win_vote)
        {
            printf("%s\n", candidates[j].name);
            return true;
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min_vote = candidates[0].votes;

    for (int j = 1; j < candidate_count; j++)
    {
        if (!candidates[j].eliminated)
        {
            if (min_vote > candidates[j].votes)
            {
                min_vote = candidates[j].votes;
            }
        }
    }

    return min_vote;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (!candidates[j].eliminated)
        {
            // if a candidate has more than minimum vote
            // meaning there's no tie
            if (min != candidates[j].votes)
            {
                return false;
            }
        }
    }

    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int j = 0; j < candidate_count; j++)
    {
        // doesn't need to check for !candidates.eliminated since their's votes is 0
        // if the candidate has minimum vote
        if (min == candidates[j].votes)
        {
            candidates[j].eliminated = true;
        }
    }

    return;
}