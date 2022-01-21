#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "cs50.h"
#include <stdlib.h>


bool not_valid(string key);
string cypher(string text);


string KEY;

int main(int argc, string argv[])
{
    KEY = argv[1];

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else if (strlen(KEY) != 26 || not_valid(KEY))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        string pt = get_string("plaintext: ");
        string ct = cypher(pt);
        printf("ciphertext: %s\n", ct);

        return 0;
    }
}

bool not_valid(string key)
{
    for (int i=0; i<26; i++)
    {
        if (!isalpha(key[i]))
        {
            return true;
        }
    }
    return false;
}


string cypher(string text)
{
    char *result = malloc(strlen(text) + 1);
    char cyphered_letter;

    for (int i=0; i<strlen(text)+1; i++)
    {

        if isalpha(text[i])
        {
            if (isupper(text[i]))
            {
                cyphered_letter = KEY[text[i] - 'A'];
                cyphered_letter = toupper(cyphered_letter);
            }
            else if (islower(text[i]))
            {
                cyphered_letter = KEY[text[i] - 'a'];
                cyphered_letter = tolower(cyphered_letter);
            }
        }
        else
        {
            cyphered_letter = text[i];
        }

        result[i] = cyphered_letter;
    }
    return result;
}
