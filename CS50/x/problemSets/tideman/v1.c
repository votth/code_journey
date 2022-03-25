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
bool no_head(void);

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
    int i, j, max_index, max;

    for (i = 0; i < pair_count - 1; i++)
    {
        max_index = i;
        for (j = i + 1; j < pair_count; j++)
        {
            max = preferences[pairs[max_index].winner][pairs[max_index].loser];
            if (max < preferences[pairs[j].winner][pairs[j].loser])
            {
                max_index = j;
            }
        }

        swap(pairs[i].winner, pairs[max_index].winner);
        swap(pairs[i].loser, pairs[max_index].loser);
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
    bool no_cycle;

    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        if (!no_head())
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }

    return;
}

bool no_head(void)
{
    int i, j;
    bool no_head;

    for (i = 0; i < pair_count; i++)
    {
        no_head = true;

        for (j = 0; j < candidate_count; j++)
        {
            if (locked[j][pairs[i].winner])
            {
                no_head = false;
                break;
            }
        }

        if (no_head)
        {
            return true;
        }
    }

    return false;
}

// Print the winner of the election
void print_winner(void)
{
    int i, j;
    bool found;

    for (i = 0; i < pair_count; i++)
    {
        if (locked[pairs[i].winner][pairs[i].loser])
        {
            found = true;

            for (j = 0; j < candidate_count; j++)
            {
                if (locked[j][pairs[i].winner])
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                printf("%s\n", candidates[i]);
                // since we assume that there's no more than 1 source
                // therefore the function can end write when found
                return;
            }
        }
    }

    printf("No winner\n");
    return;
}