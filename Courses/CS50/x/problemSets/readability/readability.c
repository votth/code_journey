#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_letters(string text);
// count spacing characters: spaces, newlines, tabs
int count_words(string text);
// doesn't not accounted for Mr. Ms. etc, only counts: . ! ?
int count_sentences(string text);

int main(void)
{
    string text = get_string("Your text: ");

// not the actual L and S in Coleman-Liau index yet, only counters
    int l = count_letters(text);
    int s = count_sentences(text);
// !! word count is part of a division, so begin float helps retain the correct of calculation
    float w = count_words(text);

// calculating average number of letters/sentences per 100 words
    float L = l / w * 100;
    float S = s / w * 100;

// calculating index value
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);

// categorizing output
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index >= 1)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

int count_letters(string text)
{
// i acts as index for looping through the string's elements, letters is counter
    int i = 0, letters = 0;

    while (text[i] != '\0')
    {
        // only account for alphabets, upper- and lowercase
        if (('a' <= text[i] && text[i] <= 'z') || ('A' <= text[i] && text[i] <= 'Z'))
        {
            letters++;
        }

        // moving to the next character
        i++;
    }

    return letters;
}

int count_words(string text)
{
// i for index looping, words as words counter
    int i = 0, words = 0;
// space to determine if currently index is at a 'spacing character'
// initial value is 'true' to account for the very first word counting
    bool space = true;

// \0 string's last element
    while (text[i] != '\0')
    {
        // spacing characters are accounted for are: spaces, newlines, tabs
        // if the index-ed element is spacing then space is still true
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
        {
            space = true;
        }
        // when index-ed element is no longer spacing, elseif will be ran since space=true
        // space will then be false to prevent the program going into this elseif
        // it will only be ran again when the above if condition is true at least once
        //    meaning there's a 'spacing again'
        else if (space)
        {
            space = false;
            words++;
        }

        // moving to the next characters
        i++;
    }

    return words;
}

int count_sentences(string text)
{
    int sentences = 0, i = 0;

    while (text[i] != '\0')
    {
        // only accounts for dot, acclamation point and questionmark
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }

        // moving to the next character
        i++;
    }

    return sentences;
}