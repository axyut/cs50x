#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isANumber(string key);
string encrypt(string text, int num_key);

int main(int argc, string argv[])
{
    //Check for single Argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Check if the string is valid or not
    string key = argv[1];
    int valid_key = isANumber(key);
    if (valid_key)
    {
        return valid_key;
    }

    //Converts string to integer
    int num_key = atoi(key);
    string text = get_string("plaintext: ");

    string encryptedText = encrypt(text, num_key);
    printf("ciphertext: %s\n", encryptedText);
    return 0;
}


int isANumber(string key)
{
    //int count=0;
    int key_len = strlen(key);
    for (int i = 0; i < key_len; i++)
    {
        if (key[i] < '0' || key[i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    return 0;
}

string encrypt(string text, int num_key)
{
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            int letter_th = text[i] - 'a';
            int letter_crypted_th = (letter_th + num_key) % 26;
            text[i] = 'a' + letter_crypted_th;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            int letter_th = text[i] - 'A';
            int letter_crypted_th = (letter_th + num_key) % 26;
            text[i] = 'A' + letter_crypted_th;
        }
    }
    return text;
}