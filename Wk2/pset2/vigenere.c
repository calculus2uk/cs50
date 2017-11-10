#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    string text = " ";
    int j, q = 0;

    // check to see if the number of arguments is exactly 2
    if (argc == 2)
    {
        // create a variable called key and assign it to second argument
        string key = argv[1];

        // create a variable called key_length as the length of the second argument
        int key_length = strlen(key);

        // create a variable, count to keep track of plaintext index count
        int count = 0;

        //Iterate over the key given
        for (int i = 0, n = strlen(key); i < n; i ++)
        {
            // Check to make sure the key is alphabetic
            if (isalpha(key[i]))
            {
                count++; // increase count by 1
            }
            else
            {
                // Print an error message out and return 1
                printf("Invalid Keyword\n");
                return 1;
            }
        }
        // If the key length equals count
        // implies that all key characters are alphabetic
        if (key_length == count)
        {
            printf("plaintext: ");

            // Get the plaintext from the user
            text = get_string();
            printf("ciphertext: ");

            // Iterate over the plaintext provided
            for (int i = 0, n = strlen(text); i < n; i++)
            {
                // Check that the charcater is alphabetic
                if (isalpha(text[i]))
                {
                    // Grouping the key characters, by making sure i dont
                    // exceed the length of the key
                    j = q % (key_length);

                    // Check that its upper case letters
                    if (isupper(text[i]))
                    {
                        // Encipher the character with its corresponding key character
                        int a = (((int)text[i] - 'A') + ((int)toupper(key[j]) - 'A')) % 26;
                        printf("%c", (char)(a + 'A'));

                    }
                    else
                    {
                        // Encipher the character with its corresponding key character
                        int a = (((int)text[i] - 'a') + ((int)tolower(key[j]) - 'a')) % 26;
                        printf("%c", (char)(a + 'a'));

                    }
                    q++;
                }
                else
                {
                    printf("%c", text[i]);
                    j = q;

                }
            }
        }

    }
    // If the argc is not exactly 2
    else
    {
        printf("Usage: vigenere ABC \n");
        return 1;
    }

    //Print a new line
    printf("\n");
}