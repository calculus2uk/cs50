#include <stdio.h>
#include <cs50.h>

int height;
void draw_pyramid(int number);

int main (void)
{
    do{
        printf("Height: ");
        height = get_int();
    } while(height < 0 || height > 23);
    draw_pyramid(height);

}

void draw_pyramid(int number)
{
    for(int row = 1; row <= number; row++)
    {
        //spaces
        for(int space = 1; space <= (number - row); space++)
        {
            printf(" ");
        }

        //Hashes
        for(int hash = 1; hash <=  (row + 1); hash++)
        {
            printf("#");
        }

        //New Line
        printf("\n");

    }
}
k