/*
A Palindrome number is an integer that remains the same when its digits are reversed.
Example: 12321 => Reversed = 12321

Write a C program that:
-> Takes a positive integer as input.
-> Uses a loop to reverse the digits.
-> Compare the reversed number with the original input.
-> Prints whether the number is a Palindrome.
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

    int rev = 0;
    while(n != 0)
    {
        int digit = n%10; //Extracting digit
        rev = rev*10 + digit;
        n = n/10;
    }//Reversing the number

    printf("Revered number = %d", rev);//Printing the reverse

    //Checking for Palindrome
    if(rev == n_copy)
        printf("%d is a Palindrome number", n_copy);
    else
        printf("%d is not a Palindrome number", n_copy);
    return 0;
}