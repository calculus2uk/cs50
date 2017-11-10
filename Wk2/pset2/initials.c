#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
    {
        // Get name from the user
       string name = get_string();

        // Check to see if the string given is not NULL
        if (name != NULL)
            {
                //Iterate over the string given(Name)
                for(int i = 0, n = strlen(name); i < n; i++)
                    {
                        //Checking if the its the first charcater of the string(Name)
                        // If it is capiatlize it and print it out
                        if(i == 0)
                            {
                              printf("%c", toupper(name[i]));
                            }
                        else if (name[i] == ' ') // If there is a space typed in the string(name), capitalzed the next character
                            {
                                printf("%c", toupper(name[i + 1]));
                            }

                    }
                    //Print out a new line
                printf("\n");
            }



    }