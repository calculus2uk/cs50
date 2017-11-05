#include <stdio.h>
#include <cs50.h>

int minutes;
int main (void)
{
    do {
        printf("Minutes: ");
        minutes = get_int();
    }while(minutes < 0);
    printf("Bottles: %i \n", minutes * 12);

}

