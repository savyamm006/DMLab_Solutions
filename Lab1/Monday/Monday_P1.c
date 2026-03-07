/*
Write a C program that:
-> Takes two positive integers as input
-> Calculates their Greatest Common Divisor (GCD) using loops
-> Calculates their Least Common Multiple (LCM)

Verify and print the results with the formula: LCM(a,b)  GCD (a,b) = a b
*/
#include <stdio.h>

int main()
{
    int n = 0, m = 0;
    printf("Enter two numbers: ");
    scanf("%d", &n);
    scanf("%d", &m);
    if(n < 0 || m < 0)
    {
        printf("Invalid input");
        return 0;
    }//Checking for positive input

    int max = (n>m)?n:m;
    int min = (n>m)?m:n;
    //Tertiary conditional operator to find max and min 

    int gcd = min;
    while(gcd > 0)
    {
        if(n%gcd == 0 && m%gcd == 0)
            break;
        gcd--;
    }
    //Logic: The *greatest* common divisor of two numbers possible can be the min of the numbers

    int lcm = max;
    while(lcm > 0)
    {
        if(lcm%n == 0 && lcm%n == 0)
            break;
        lcm += max; //Jumping steps to save computational time
    }
    //Logic: The *lowest* common multiple of two numbers possible can be the max of the numbers

    printf("GCD = %d\n", gcd);
    printf("LCM = %d\n", lcm);

    if((n*m) == (gcd*lcm)) //Checking for the equality
        printf("Equality holds: %d * %d = %d * %d", n, m, gcd, lcm);
    else
        printf("Error in calculation");
    return 0;
}