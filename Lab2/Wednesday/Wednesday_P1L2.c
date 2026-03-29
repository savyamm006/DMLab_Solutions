/*
*Kth largest element of an Array*

Write a C program that:
- Asks the user for the size of an array N.
- Takes N integers as input and stores them in an array.
- Asks the user for an integer K (where 1 < K <N).
- Sorts the array in descending order and prints it.
- Finds and prints the Kth largest element in the array.
    * If K=1, it is the maximum element.
    * If K=N, it is the minimum element.

Note: The Sorting algorithm chosen must have a time complexity of O(n log n).

Solution: 
Both MergeSort and QuickSort are valid solutions for this question.
(Though QuickSort has a worst case complexity of O(n^2)) 
Any other valid sorting algorithm will be accepted, but full marks will not be given.
Note: the code for the Quick Sort algorithm is already given in "Monday_P1(2)L2.c", so I am not rewriting it. 
The condition must be reversed as you are required to sort it in descending order.
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
        if (leftArr[i] >= rightArr[j]) {
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
    int k = 0;
    printf("Enter K: ");
    scanf("%d", &n);
    if(k>n || k<1)
    {
        printf("Invalid Input");
        return -1;
    }
    int arr[n];
    printf("Enter %d elements of the array: \n", n);
    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array:");
    printArray(arr, n);

    printf("%d-th largest element of the Array: %d\n", arr[k-1]);
    return 0;
}