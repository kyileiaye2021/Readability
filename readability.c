#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calculate(int letters, int words, int sentences);

int main(void)
{
    string t = get_string("text: ");

    int grade = round(calculate(count_letters(t), count_words(t), count_sentences(t)));

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}///

//counting the letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

//counting the words
int count_words(string text)
{
    int words = 0;
    for (int j = 0; j < strlen(text); j++)
    {
        if (text[j] == ' ')
        {
            words++;
        }
    }
    return words + 1;
}

//counting the sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        if (text[k] == '!' || text[k] == '.' || text[k] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

//calculating the grades
float calculate(int letters, int words, int sentences)
{
    float L = ((float) letters * 100) / (float) words;
    float S = ((float) sentences * 100) / (float) words;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}