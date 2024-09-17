#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long cardNumber;
    do
    {
        cardNumber = get_long("Enter a Number: ");
    }
    while (cardNumber < 0);

    long cardCopy = cardNumber;
    int numCount = 0;

    while (cardCopy > 0)
    {
        cardCopy = cardCopy / 10;
        numCount++;
    }

    if (numCount != 13 && numCount != 15 && numCount != 16)
    {
        printf("Invalid (Length)\n");
        return 0;
    }

    int sum1 = 0;
    int sum2 = 0;
    long x = cardNumber;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;

    do
    {
        //get the last digit
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;
        //get the 2nd to last digit
        mod2 = x % 10;
        x = x / 10;

        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;

    }
    while (x > 0);

    total = sum1 + sum2;
    if (total % 10 != 0)
    {
        printf("Invalid (CheckSum)\n");
        return 0;
    }

    long start = cardNumber;
    do
    {
        start = start / 10;
    }
    while (start > 100);

    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}