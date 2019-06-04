#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Check that only 2 command line arguments were passed in
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }

    int n = strlen(argv[1]);

    //Make sure that the key is all letters
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Error\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: "); //Get user plaintext

    printf("ciphertext: ");

    int j = 0; //variable to keep track of jth character of the key

    for (int i = 0; i < strlen(plaintext); i++) //Iterate through plaintext
    {
        if (isalpha(plaintext[i])) //Make sure the character is an alphabet
        {
            int key = (argv[1][j % n]); //Rotate through the key
            j++;

            //If key is uppercase
            if (key >= 'A' && key <= 'Z')
            {
                key %= 65;
            }
            //Else if key is lowercase
            else if (key >= 'a' && key <= 'z')
            {
                key %= 97;
            }

            //If plaintext is uppercase
            if (isupper(plaintext[i])) //if it is uppercase
            {
                printf("%c", (((plaintext[i] + key) % 65) % 26) + 65);
            }

            //if plaintext is lowercase
            if (islower(plaintext[i])) //if it is lowercase
            {
                printf("%c", (((plaintext[i] + key) % 97) % 26) + 97);
            }
        }
        else //if it is not an alphabet, leave it the same
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}