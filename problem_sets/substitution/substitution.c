#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool is_valid_key(string key);
string substitute(string text, string key);

int main(int argc, string argv[])
{
    // Check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    string key = argv[1];

    // Validate the key
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Get plaintext input
    string plaintext = get_string("plaintext: ");

    // Encrypt and output
    string ciphertext = substitute(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

bool is_valid_key(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }

    int letters[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = toupper(key[i]) - 'A';

        if (letters[index] > 0)
        {
            return false;
        }
        letters[index]++;
    }

    return true;
}

string substitute(string text, string key)
{
    int n = strlen(text);
    string result = malloc(n + 1); // +1 for null terminator

    for (int i = 0; i < n; i++)
    {
        char c = text[i];
        if (isupper(c))
        {
            result[i] = toupper(key[c - 'A']);
        }
        else if (islower(c))
        {
            result[i] = tolower(key[c - 'a']);
        }
        else
        {
            result[i] = c;
        }
    }

    result[n] = '\0';
    return result;
}
