/*
Write a C program that:
-> Takes a positive decimal integer between 0 and 255 (to keep it at a 2-digit hex level for simplicity).
-> Converts it to its Hexadecimal (base 16) equivalent.

Hint: 
    Divide the number by 16 to get the first digit (Quotient) and the second digit (Remainder). 
    For digits between 10 and 15, print the corresponding letter (A-F).
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

    // array to store hexadecimal number
    char hexa_Number[100];
    //counter for Hexadecimal number
    int i = 0;
    while (n != 0) {
        int temp = n % 16;

        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        //If digit < 10, the ASCII value of the number is taken, otherwise ASCII value of [A-F] is taken 
        // A = 65, B = 66 and so on
        
        hexa_Number[i++] = temp;
        n = n / 16;
    }

    // printing the hexadecimal number in reverse order
    printf("Hexadecimal form: ");
    for (int j = i - 1; j > 0; j--)
        printf("%c", hexa_Number[j]);

    return 0;
}