/*
*Count inversions*
An inversion in an array is a pair of elements (a[i], a[j]) such that a[i] < a[j] and i > j. 

Write a C program that:
- Asks the user for the size of an array N.
- Takes N integers as input and stocount them in an array.
- Counts and returns the number of inversions in the array.
The brute force algorithm will only be rewarded partial credit. Give the optimal to gain full credit.  
Hint: Recall the Mergesort algorithm.

Solution: 
Total number of inversions in context of MergeSort:
The number of elements remaining in the Left subarray everytime an element from the Right subarray is put in front of them.

The naive approach would be to run a nested loop, where the outer loop iterates as i = 0 to n-2 
and the inner loop iterates as j = i+1 to n-1 and everytime a[j] < a[i], inversion count is updated. 

MergeSort takes O(n log n) whereas a nested loop is of O(n^2).
*/
#include <stdio.h>

// This function merges two sorted subarrays arr[l..m] and arr[m+1..r] 
// and also counts inversions in the whole subarray arr[l..r]
int countAndMerge(int arr[], int l, int m, int r) {
  
    // Counts in two subarrays
    int n1 = m - l + 1, n2 = r - m;

    // Set up two arrays for left and right halves
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Initialize inversion count and merge two halves
    int count = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {

        // No increment in inversion count if left[] has a smaller or equal element
        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
      
        // If right is smaller, then it is smaller than n1-i elements because left[] is sorted
        else {
            arr[k++] = right[j++];
            count += (n1 - i);
        }
    }

    // Merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return count;
}

// Function to count inversions in the array
int countInv(int arr[], int l, int r) {
    int count = 0;
    if (l < r) {
        int m = (r + l) / 2;

        // Recursively count inversions in the left and right halves
        count += countInv(arr, l, m);
        count += countInv(arr, m + 1, r);

        // Count inversions such that greater element is in the left half and smaller in the right half
        count += countAndMerge(arr, l, m, r);
    }
    return count;
}

// Driver Code
int main() 
{
    int n = 0;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements of the array: \n", n);
    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    int inv_count = countInv(arr, 0, n-1);
    printf("Number of inversions = %d\n", inv_count);
    return 0;
}