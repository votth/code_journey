// Declares a dictionary's functionality
// so clang doesn't complie this file twice, eventhough it is called twice in distrionary.c and speller.c
#ifndef DICTIONARY_H
#define DICTIONARY_H

// for the bool data type
#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Prototypes
bool check(const char *word);
unsigned int hash(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
