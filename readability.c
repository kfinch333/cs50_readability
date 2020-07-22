#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

string get_txt(void);
int count_letters(string txt);
int count_words(string txt);
int count_sentences(string txt);
float txt_index(int letters, int words, int sentences);

int main(void)
{
    int letters, words, sentences, cl_index = 0;
    float index = 0;

    string txt = get_txt();
    letters = count_letters(txt);
    words = count_words(txt);
    sentences = count_sentences(txt);
    index = txt_index(letters, words, sentences);
    cl_index = round(index);
    
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", cl_index);
    }
}

//get text
string get_txt(void)
{
    string txt = get_string("Text: ");
    return txt;
}

//count letters
int count_letters(string txt)
{
    int count = 0;
    //printf("%lu\n", strlen(txt));
    for (int i = 0; i < strlen(txt); i++)
    {
        if (isalpha(txt[i]))
        {
            count++;
        }
    }
    //printf("%i letter(s)\n", count);
    return count;
}

//count words
int count_words(string txt)
{
    int count = 1;
    for (int i = 0; i < strlen(txt); i++)
    {
        if (txt[i] == ' ')
        {
            count++;
        }
    }
    //printf("%i word(s)\n", count);
    return count;
}

//count sentences
int count_sentences(string txt)
{
    int count = 0;
    for (int i = 0; i < strlen(txt); i++)
    {
        if (txt[i] == '.' || txt[i] == '!' || txt[i] == '?')
        {
            count++;
        }
    }
    //printf("%i sentence(s)\n", count);
    return count;
}

//calculate index
float txt_index(int letters, int words, int sentences)
{
    float index = 0.0588 * (float) letters / ((float) words / 100) - 0.296 * (float) sentences / ((float) words / 100) - 15.8;
    return index;
}
