/*
This is the QuickSort solution for the same problem(Refer to "Monday_P1L2.c" for the Problem Statement)
*/
#include <stdio.h>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}//Helper function for swapping

int partition(int arr[], int low, int high) {

    // Initialize pivot to be the first element
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // Find the first element greater than the pivot (from starting)
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }

        // Find the first element smaller than the pivot (from last)
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {

        // call partition function to find Partition Index
        int pi = partition(arr, low, high);

        // Recursively call quickSort() for left and right half based on Partition Index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, n - 1);

    printf("Sorted Array:");
    printArray(arr, n);

    printf("Median of the Array: %f\n", median(arr, n));
    return 0;
}