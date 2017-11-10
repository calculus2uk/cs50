#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    //Check that the total number of arguments is not more than 2
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // Convert the key (second argument) to an int
    int key = atoi(argv[1]);

    printf("Enter text: \n");
    //Get the plaintext to cipher from the user
    string text = get_string();

    printf("ciphertext: ");

    //Iterate over each character in the plaintext
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //If character is alphabetic
        if (isalpha(text[i]))
        {
            //If the aplahabetic character is in UPPERCASE
            if (isupper(text[i]))
            {
                // Getting the alphabetic index and store it as int cipher_key
                int cipher_key = (((int)(text[i]) - 'A') + key) % 26;
                printf("%c", (char)(cipher_key + 'A'));
            }
            //   //If the aplahabetic character is in lowercase
            else if (islower(text[i]))
            {
                // Getting the alphabetic index and store it as int cipher_key
                int cipher_key = (((int)(text[i]) - 'a') + key ) % 26;
                printf("%c", (char)(cipher_key + 'a'));
            }
        }
        //If the character is not alphbetic, preserve it
        else
        {
            printf("%c", text[i]);
        }
    }
    //Print a new line
    printf("\n" );
}