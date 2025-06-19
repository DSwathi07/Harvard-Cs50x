#include <strings.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

#define HASH_SIZE 5000  // Adjust size as needed

// Node structure for linked list
typedef struct node {
    char word[LENGTH + 1];
    struct node *next;
} node;

// Hash table
node *table[HASH_SIZE];

// Word count
unsigned int word_count = 0;

// Hash function (djb2 algorithm)
unsigned int hash(const char *word) {
    unsigned long hash = 5381;
    int c;
    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + tolower(c);
    }
    return hash % HASH_SIZE;
}

// Loads dictionary into memory
bool load(const char *dictionary) {
    FILE *file = fopen(dictionary, "r");
    if (file == NULL) {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF) {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL) {
            fclose(file);
            return false;
        }

        strcpy(new_node->word, word);
        new_node->next = NULL;

        int index = hash(word);

        // Insert at the beginning of linked list
        new_node->next = table[index];
        table[index] = new_node;
        word_count++;
    }

    fclose(file);
    return true;
}

// Returns true if word is in dictionary
bool check(const char *word) {
    char temp[LENGTH + 1];
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        temp[i] = tolower(word[i]);
    }
    temp[len] = '\0';

    int index = hash(temp);
    node *cursor = table[index];
    while (cursor != NULL) {
        if (strcasecmp(cursor->word, temp) == 0) {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Returns number of words in dictionary
unsigned int size(void) {
    return word_count;
}

// Unloads dictionary from memory
bool unload(void) {
    for (int i = 0; i < HASH_SIZE; i++) {
        node *cursor = table[i];
        while (cursor != NULL) {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
