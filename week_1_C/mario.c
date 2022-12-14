#include <cs50.h>
#include <stdio.h>

//Declaring functions
void loop();

//Main function
int main(void)
{
    int input;
    do
    {
        input = get_int("Height: ");
    }
    while (input < 1 || input > 8);
    //printf("%d", input);
    loop(input);
}


//Defining functions
void loop(int num)
{
    int i, j;
    // Loop for rows(each line)
    for (i = 1; i <= num; i++)
    {
        //Nested Loops for columns (each value in a row)
        for (j = i; j < num; j++)
        {
            printf(" ");
        }
        for (j = i; j >= 1; j--)
        {
            printf("#");
        }

        //Printig next line
        printf("\n");
    }
}
