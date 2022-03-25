// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);

    // if hash book is empty, nothing to compare too
    if (table[index] == NULL)
    {
        return false;
    }

    // case-insensitively using strcasecmp()
    node *cmp = table[index];
    // compare to first link's word
    if (strcasecmp(word, cmp->word) == 0)
    {
        return true;
    }
    // while there're remaining words
    while (cmp->next != NULL)
    {
        // cmp moves to next link
        cmp = cmp->next;
        if (strcasecmp(word, cmp->word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';

    // since lowercase alphabets have higher ASCII value than UPPERCASE
    // avoid using <ctype.h> I guess xD
    return word[0] - 'a' < 0 ? word[0] - 'A' : word[0] - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary to read
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    // fill table with NULL
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char new_word[LENGTH];
    node *n = NULL;

    // read word by word from dict
    while (fscanf(dict, "%s", new_word) != EOF)
    {
        // allocate memory for n node
        n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(dict);
            unload();
            return false;
        }
        // record n->word
        strcpy(n->word, new_word);
        int index = hash(n->word);

        // attach n node as head
        n->next = table[index];
        table[index] = n;
    }

    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // counter
    unsigned int count = 0;

    // loop through table[i]
    for (int i = 0; i < 26; i++)
    {
        // if hash is NULL, skip
        if (table[i] == NULL)
        {
            continue;
        }
        // there's at least one so ++
        node *tmp = table[i];
        count++;
        // check and ++ until there's no word remained
        while (tmp->next != NULL)
        {
            count++;
            tmp = tmp->next;
        }
    }

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // loop through table[i] to free memory
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }

    return true;
}
