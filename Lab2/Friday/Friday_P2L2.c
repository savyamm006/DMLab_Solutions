/*
*Two-sum*

Write a C program to:
- Asks the user for the size of an array N, and the target sum K
- Takes N integers as input and stores them in an array.
- Counts and returns the number of  pairs (i, j) i<j such that a[i] + a[j] = K
The brute algorithm will be rewarded credit. Give the optimal (using memoisation) to gain full credit.

Brute Force solution:
Using nested loops, the outer loop goes from i = 0 to n-2, the inner loop goes from j = i+1 to n-1
(so i < j is guaranteed), and we increment the count whenever the two sum to K.
This approach will be of O(n^2).

Solution:
The optimised solution involves maintaining a frequency array of size [MAX ELEM] + 1. 
For every arr[i], there must exist a complement = K - arr[i] that must be under the size of MAX ELEM. 
If that complement exists in the frequency array, then increase the count by the frequency of the complement. 
At the same time, increase the frequency of arr[i] 
(So that if the complement exists later, its complement will be arr[i] and count increases accordingly)

This approach will be of O(n).
Note: This will work for non-negative numbers only. 
Incase negative numbers exist, you take the [MIN ELEM] as well and make an array of size [MAX ELEM] - [MIN ELEM] + 1 
Then find the index where zero would exist, as the offset.


The brute force algorithm of using nested loops has been accepted as a valid answer and full credit given. 
*/
#include <stdio.h>

//Brute Force approach
int main() 
{
    int n, k;

    printf("Enter the size of the array (N): ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the target sum (K): ");
    scanf("%d", &k);

    int count = 0;

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == k)
                count++;

    printf("Number of pairs: %d\n", count);

    return 0;
}

/*
Frequency Array method (Non-negative numbers only)
int main() 
{
    int n, K;

    printf("Enter the size of the array (N): ");
    scanf("%d", &n);

    int arr[n];
    int max = 0;
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] > max)
            max = arr[i];
    }
    printf("Enter the target sum (K): ");
    scanf("%d", &K);

    max++;
    int freq[max] = {0};// This is your memo array, storing the frequency
    int count = 0;

    for (int i = 0; i < n; i++) 
    {
        int complement = K - arr[i];
        if (complement >= 0 && complement < max)
            count += freq[complement];
        // If the complement is in the range, then count will be increased by the freq of the complement
        freq[arr[i]]++;
    }
    
    printf("Number of pairs: %d\n", count);

    return 0;
}*/