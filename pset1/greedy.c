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

   //While quarters can be used ie 25 cents
   while(cents >= 25)
   {
       count++;
       cents = cents - 25;
   }

     //While dimes can be used ie 10 cents
   while(cents >= 10)
   {
       count++;
       cents = cents - 10;
   }

    //While 5 cents can be used
   while(cents >= 5)
   {
       count++;
       cents = cents - 5;
   }

    //While a cent can be used
   while(cents >= 1)
   {
       count++;
       cents = cents - 5;
   }

   printf("%i\n", count);
}