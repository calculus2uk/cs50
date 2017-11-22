/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <cs50.h>

// Craete an array of nodes()
node *HASHTABLE[SIZE];

// count word
int count = 0;

// pointer to indicate the beginning of a linkedlist
//node *head = NULL;

//Hash function
// int hash_function(char *word_to_hash)
// {
//     int index = toupper(word_to_hash[0]) - 'A';

//     return index % SIZE;
// }

// djb2 hash function from http://www.cse.yorku.ca/~oz/hash.html
unsigned long hash_function(char* word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c);

    }
    return hash % SIZE;
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{

    int len = strlen(word);

    char temp_copy[len + 1];

    for (int i = 0; i < len ; i++)
    {
        if (word[i] =='\'')
        {
            temp_copy[i] = word[i];
        }
        else
        {
            temp_copy[i] = tolower(word[i]);
        }
    }
    //add end of char indicator to word
    temp_copy[len] = '\0';

    //Get index of hashtable
    int index = hash_function(temp_copy);

    // cursor to travers thorugh the linkedlist
    node *cursor = HASHTABLE[index];

    while (cursor != NULL)
    {
        //compare words
        if (strcmp(temp_copy, cursor->word) == 0)
        {
            return true;
        }

        //move cursor to next
        cursor = cursor->next;
    }

    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // Open the dictionary
    FILE *fp = fopen(dictionary, "r");

    if (fp == NULL)
    {
        printf("Unable to open dictionary\n");
    }

    // variable to keep the word copied from the dictionary
    char copied_word[LENGTH + 1];

    // scan the dictionary file, look for string and keep in the var copied_word
    // and continue till get to end of file
    while(fscanf(fp, "%s", copied_word) != EOF)
    {
        // malloc a space for every word scan from dictionary
        node *new_node = malloc(sizeof(node));

        // incase of it doesnt work
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        else
        {
            strcpy(new_node->word, copied_word);

            int index = hash_function(new_node->word);

            new_node->next = HASHTABLE[index];
            HASHTABLE[index] = new_node;
        }
        // increase the word count
        count++;

    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return count;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    for (int i = 0; i < SIZE; i++)
    {
        node *cursor = HASHTABLE[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    return true;
}
