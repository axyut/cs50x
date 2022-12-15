#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Declaring functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int result(int L, int W, int S);

//Global variable
int text_len;

int main(void)
{
    string text = get_string("Text: ");
    text_len = strlen(text);

    int L = count_letters(text);
    int W = count_words(text);
    int S = count_sentences(text);
    int index = result(L, W, S);

    //Result
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}


int count_letters(string text)
{
    int num = 0;
    for (int i = 0; i < text_len; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            num++;
        }
    }
    //printf("Letters: %d\n", num);
    return num;
}

int count_words(string text)
{
    int num = 1;
    for (int i = 0; i <  text_len; i++)
    {
        if (text[i] == ' ')
        {
            num++;
        }
    }
    //printf("words: %d\n", num);
    return num;
}

int count_sentences(string text)
{
    int num = 0;
    for (int i = 0; i < text_len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            num++;
        }
    }
    //printf("Sentences: %d\n", num);
    return num;
}

int result(int L, int W, int S)
{
    float letter = ( L * 100 ) / W ;
    float sentence = ( S * 100 ) / W;
    int index = round(0.0588 * letter - 0.296 * sentence - 15.8);
    return index;
}