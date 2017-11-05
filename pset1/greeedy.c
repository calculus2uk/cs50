#include <stdio.h>
#include <cs50.h>
#include <math.h>

float amount;
int count = 0;
void do_change(float amountEntered);

int main(void)
{
    do{
        printf("O hai! How much change is owed? \n");
        amount = get_float();
    } while(amount < 0);
    //printf("%.55f", amount);
    do_change(amount);


}

void do_change(float amountEntered)
{
   int cents = round (amountEntered * 100);
   //printf("%i\n", cents);

    while(cents > 0)
    {
        if(cents >= 25)
        {
            count++;
            cents = cents -25;
        }

        else if(cents >= 10 && cents < 25)
        {
            count++;
            cents = cents -10;
        }
        else if(cents >= 5 && cents < 10)
        {
            count++;
            cents = cents -5;
        }
        else if(cents >= 1 && cents < 5)
        {
            count++;
            cents = cents -1;
        }
    }


   printf("%i\n", count);
}