/*
Write a C program that converts a decimal (Base 10) integer into its Octal (Base 8) equivalent.

Hint: 
-> Take a positive integer input.
-> Perform repeated division by 8.
-> Store the remainders (which will be between 0 and 7) and print them in reverse order.
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

   // array to store octal number
    int octalNum[1000];

    // counter for octal array
    int i = 0;
    while (n > 0) {
        // storing remainder in octal array
        octalNum[i] = n % 8;
        n = n / 8; //Continuing with the quotient
        i++;
    }

    // printing octal array in reverse order
    printf("Octal form: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", octalNum[j]);
    return 0;
}