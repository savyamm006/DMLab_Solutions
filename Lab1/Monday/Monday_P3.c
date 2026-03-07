/*
Write a C program that:
-> Takes a positive decimal number as input
-> Converts it to its binary equivalent
-> Prints the binary representation

Hint: Binary conversion is based on repeated division by 2.
At each step:
-> Divide the number by 2
-> Store the remainder (0 or 1)
-> Continue with the quotient
The remainders form the binary number in reverse order.
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

   // array to store binary number
    int binaryNum[1000];

    // counter for binary array
    int i = 0;
    while (n > 0) {
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2; //Continuing with the quotient
        i++;
    }

    // printing binary array in reverse order
    printf("Binary form: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
    return 0;
}