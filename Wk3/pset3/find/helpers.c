/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Declare variable, check to keep track of number of items in the array
    int check = n;
    // Declare variable count and set to 0
    int count = 0;
    //Declare variable startIndex and set to 0
    int startIndex = 0;

    // Implement a searching algorithm
    // Check if the number of items in the array is more than 0
    while(n > 0)
    {
        //Index to search is middle of cuurent size
        startIndex = n / 2;

        // If middle value of the array equals value return true
        if (values[startIndex] == value )
        {
            return true;
        }
        // If the middle value of the array is greater than the value
        // search left by setting the tearing the other half away
        else if (values[startIndex] > value)
        {
            n = startIndex;
        }
        // If the middle value of the array is less than the value
        // search right by setting the tearing the other half away
        else if(values[startIndex] < value)
        {
            n = startIndex + n;

            // A check to see if the current index is greater than the initial array
            if (n > check)
            {
                count++;
            }
        }
        // If the count > 2, implies the else if(values[startIndex] < value)
        // has been runed twice
        if (count > 2)
        {
            return false;
        }


    }

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // implement a sorting algorithm
    // Iterate over the array
    for (int i = 0; i < n - 1; i++)
    {
        // Declare a temp variable to store
        int temp;

        // Iterate over the array
        for (int j = i + 1; j < n; j++)
        {
            // Swap if the next value is bigger than the previous one
            if (values[j] < values[i])
            {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }

    return;
}
