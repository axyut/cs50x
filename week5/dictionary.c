// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int numOfWords = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int code = hash(word);
    node *target = table[code];

    while (target != NULL)
    {
        if (strcasecmp(word, target->word) == 0)
        {
            return true;
        }
        target = target->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];
    FILE *openedDictionary = fopen(dictionary, "r");
    if (openedDictionary != NULL)
    {
        while (fscanf(openedDictionary, "%s", word) != EOF)
        {
            node *target = malloc(sizeof(node));

            if (target != NULL)
            {
                int code = hash(word);
                strcpy(target->word, word);
                target->next = table[code];
                table[code] = target;
                numOfWords ++;
            }

        }

    }
    else
    {
        return false;
    }
    fclose(openedDictionary);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return numOfWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *target = table[i];
        while (target != NULL)
        {
            node *tmp = target;
            target = target->next;
            free(tmp);
        }
        if (i == N - 1 && target == NULL)
        {
            return true;
        }
    }
    return false;
}
