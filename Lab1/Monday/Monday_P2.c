/*
A positive integer is called a Strong Number if the sum of the factorials of its digits is equal to the number itself.
Example:
145 → 1! + 4! + 5! = 1 + 24 + 120 = 145

Write a C program that:
-> Takes a positive integer as input
-> Computes the sum of factorials of its digits
-> Prints whether the number is a Strong Number or not
*/ 
#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(n < 0)
    {
        printf("Invalid input");
        return 0;
    }//Checking for positive input
    int n_copy = n; //Saving the value of n 
    
    int sum = 0, fact;
    while (n > 0)
    {
        int digit = n%10; //Extracting digit
        
        fact = 1;
        for(int i = 1;i<=digit;i++)
            fact = fact * i;
        //Calculating factorial

        sum += fact;
        n = n/10;
    }

    //Checking for Strong number
    if(n_copy == sum)
        printf("%d is a Strong number", n_copy);
    else
        printf("%d is not a Strong number", n_copy);
    return 0;
}