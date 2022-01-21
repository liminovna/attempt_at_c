#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "cs50.h"


int estimate(string text);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    printf("%d letters\n", letters);

    int words = count_words(text);
    printf("%d words\n", words);

    int sentences = count_sentences(text);
    printf("%d sentences\n", sentences);

    // float ans = estimate(text);
    float L = (float)letters / (float)words * 100;
    // printf("L = %.3f\n", L);
    float S = (float)sentences / (float)words * 100;
    // printf("S = %.3f\n", S);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    printf("index = %.3f\n", index);
    // int ans = round(index);

    if (ans < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (ans >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", ans);
    }
}

int count_letters(string text)
{
    int letters = 0;

    for (int i=0; i<strlen(text); i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            letters++;
        }
    }
    return letters;
}


int count_words(string text)
{
    int words = 1;

    for (int i=0; i<strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}


int count_sentences(string text)
{
    int sentences = 0;

    for (int i=0; i<strlen(text); i++)
    {
        char symbol = text[i];
        if (symbol == '.' || symbol == '?' || symbol == '!')
            {
                sentences++;
            }
    }
    return sentences;
}


int estimate(string text)
{
    int letters = 0;
    int words = 0;
    int sentences=0;

    for (int i=0; i<strlen(text); i++)
    {
        char symbol = text[i];
        
        if (islower(text[i]) || isupper(text[i]))
        {
            letters++;
        }
        else
        {
            words++;
            if (symbol == '.' || symbol == '?' || symbol == '!')
            {
                sentences++;
            }
        }
    }

    float L = (float)letters / (float)words * 100.0;
    float S = (float)words / (float)sentences * 100.0;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int ans = round(index);
    return ans;
}
