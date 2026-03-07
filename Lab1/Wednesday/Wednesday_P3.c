/*
Arrays allow us to store multiple values of the same type and process them using loops.

Write a C program that:
-> Declare an array of length N, taken from the user. 
-> Store N numbers taken from the user in the array. 
-> Calculates and prints the Average and Range of all elements in the array.

Average = Sum of elements/N
Range = Max(arr) - Min(arr)
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

    int sum = 0, max = arr[0], min = arr[0];
    for(int i = 0; i<n; i++)
    {
        sum += arr[i];
        //Calculating the sum of the elements

        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
        //Calculating the max and min 
    }

    double avg = sum/n;
    int range = max - min;
    //Calculating average and range
    printf("Average = %dd", avg);
    printf("Range = %d", range);
    return 0;
}