/*
Write a C program that:
-> Take two positive integers A and (a digit) B. 
-> Count how many times the digit B  appears in the number A. 
-> Print "Invalid input" if the user enters a non-integer for A/B and if B is not single digit. 

Example: 
    Input:
     Enter a  number: 70772
     Enter a digit: 7 
    Output:
     Frequency of 7 is: 3
*/
#include <stdio.h>

int main()
{
    int a = 0, b = 0;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter a digit: ");
    scanf("%d", &b);
    if(a<0 || b<0 || b>10)
    {
        printf("Invalid input");
        return 0;
    }//Checking for positive integer in A and digit in B
    
    int freq = 0;//Counter to check frequency of digit B
    while(a>0)
    {
        int dig = a%10;//Extracting digit
        if(dig == b)
            freq++;//Counter increases when digit is present
        a = a/10;
    }

    printf("Frequency of %d is: %d", b, freq);
    return 0;
}