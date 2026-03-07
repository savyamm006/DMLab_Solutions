/*
Write a program in C that:
-> Asks the user for the size of an array N.
-> Takes N integers as input and stores them in an array.
-> Calculates the Alternating Sum where elements at even indices are added and elements at odd indices are subtracted.
    Result = arr[0] - arr[1] + arr[2] - arr[3]
*/

#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter the size: ");
    scanf("%d", &n);

    //array to store n numbers
    int arr[n];

    printf("Enter %d numbers: ", n);
    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);
    //Traversing the array to take input

    int altsum = arr[0];
    for(int i = 1; i<n; i++)
    {
        if(i%2 == 0)
            altsum += arr[i];
        else
            altsum -= arr[i];
    }//If even: add the element, else subtract the element 

    printf("Alternating sum = %d", altsum);
    return 0;
}