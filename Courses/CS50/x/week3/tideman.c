#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

// Added function
void swap(int x, int y);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int j = 0; j < candidate_count; j++)
    {
        // if the name is found
        if (strcmp(name, candidates[j]) == 0)
        {
            // save candidate's index as the current voter's 'rank'th pref.
            // j here is an index of array candidates[]
            ranks[rank] = j;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // here j and k are to be considered as in ranking order, for ranks[]
    for (int j = 0; j < candidate_count; j++)
    {
        for (int k = j + 1; k < candidate_count; k++)
        {
            // k is always bigger than j, meaning less in ranking
            // while ranks[k] returns the index of the candidate in candidates[]
            // preferences[i][j] keeps count of how many times the I candidates is prefered over the J candidates
            preferences[ranks[j]][ranks[k]]++;
        }
    }

    // the function "creates" a square matrix with main diagonal only has 0

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int j = 0; j < candidate_count; j++)
    {
        // It's enough to only look at the columns with index larger than the row's index
        // since the code below considers both [j][k] and [k][j] pairing
        // once the loop is finished, it would have looked through all elements of the 'j'th row+column
        for (int k = j + 1; k < candidate_count; k++)
        {
            if (preferences[j][k] > preferences[k][j])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = k;
                pair_count++;
            }
            else if (preferences[j][k] < preferences[k][j])
            {
                pairs[pair_count].winner = k;
                pairs[pair_count].loser = j;
                pair_count++;

            }
            // we'll ignore pref.[j][k] == pref.[k][j]
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int min_index = 0;
    int min = preferences[pairs[min_index].winner][pairs[min_index].loser];

    int i;
    int loop_count = pair_count;

    while (loop_count)
    {
        for (i = 1; i < loop_count; i++)
        {
            if (min > preferences[pairs[i].winner][pairs[i].loser])
            {
                min_index = i;
                min = preferences[pairs[min_index].winner][pairs[min_index].loser];
            }
        }

        swap(pairs[min_index].winner, pairs[loop_count].winner);
        swap(pairs[min_index].loser, pairs[loop_count].loser);

        min_index = 0;
        loop_count--;
    }

    return;
}

void swap(int x, int y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    bool no_cycle = true;

    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // check if there's any edge pointing to 'i'
            if (locked[j][i] == true)
            {
                no_cycle = false;
                break;
            }
        }

        if (no_cycle)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }

        no_cycle = true;
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    bool found = false;
    int i = 0;

    for (i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < candidate_count; i++)
        {
            if (locked[j][i])
            {
                break;
            }

            found = true;
        }

        if (found)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }

    printf("No winner\n");
    return;
}
