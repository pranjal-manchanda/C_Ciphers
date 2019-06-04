#include <cs50.h>
#include <ctype.h> //Check isupper/islower/isalpha
#include <stdio.h>
#include <stdlib.h> //atoi
#include <string.h> //strlen

int main(int argc, string argv[])
{
    if (argc != 2) //Ensure that 2 arguments were passed in (first is the program name)
    {
        printf("Error\n");
        return 1;
    }

    int key = atoi(argv[1]); //Convert key to an int

    string plaintext = get_string("plaintext: "); //Receive user input

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i])) //Make sure the character is an alphabet
        {
            if (isupper(plaintext[i])) //if it is uppercase
            {
                plaintext[i] = (((plaintext[i] % 65) + key) % 26) + 65;
                //char % 65 gives each character an index starting at 0
                //+ key) % 26 adds the key to it and ensure that it is a value between 0 - 25
                //+ 65 assings the final cipher value
            }

            if (islower(plaintext[i])) //if it is lowercase
            {
                plaintext[i] = (((plaintext[i] % 97) + key) % 26) + 97;
                //char % 97 gives each character an index starting at 0
                //+ key) % 26 adds the key to it and ensure that it is a value between 0 - 25
                //+ 97 assings the final cipher value
            }
        }
        else //if it is not an alphabet, leave it the same
        {
            plaintext[i] = plaintext[i];
        }
    }

    printf("ciphertext: ");
    //Iterate through each element of the ciphertext and print it
    for (int x = 0, y = strlen(plaintext); x < y; x++)
    {
        printf("%c", plaintext[x]);
    }
    printf("\n");
}