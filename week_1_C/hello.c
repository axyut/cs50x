#include<stdio.h>
int main(void)
{
    //declaring data-type and variable tp store name
    char name[20];

    // Asking User for input
    printf("What your name might be?");

    //Taking input from User
    scanf("%s", name);

    //Presenting User with Hello and Username
    printf("Hello, %s.\n", name);
}