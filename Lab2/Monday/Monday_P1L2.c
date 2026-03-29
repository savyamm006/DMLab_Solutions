/*
*Median of an Array*

Write a C program that:
- Asks the user for the size of an array N.
- Takes N integers as input and stores them in an array.
- Sorts the array in ascending order.
- Calculates and prints the median of the array:
    * If N is odd, the median is the middle element.
    * If N is even, the median is the average of the two middle elements (print as a floating-point value).

Note: The Sorting algorithm chosen should have a time complexity of  O(n log n)

Solution: 
Both MergeSort and QuickSort are valid solutions for this question.
(Though QuickSort has a worst case complexity of O(n^2)) 
Any other valid sorting algorithm will be accepted, but full marks will not be given.
*/

#include <stdio.h>

// Merges two subarrays of arr[].
// First subarray is arr[left..mid] and Second subarray is arr[mid+1..right]
// Note: You can use in-place implementation as well, though it can cause a worst case complexity of O(n^2)
void merge(int arr[], int left, int mid, int right) 
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) 
    {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) 
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) 
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r) 
    {
        // Same as (l + r) / 2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Returns the median of the sorted array
float median(int arr[], int n)
{
    if(n%2 != 0) return arr[n/2 + 1]; // If length of array is odd
    
    int sum = arr[n/2] + arr[n/2 + 1];
    float med = (float) sum/2; // If length of array is even
    return med;
}

/* HELPER FUNCTIONS */
// Function to print an array
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

//Driver code
int main()
{
    int n = 0;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements of the array: \n", n);
    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array:");
    printArray(arr, n);

    printf("Median of the Array: %f\n", median(arr, n));
    return 0;
}