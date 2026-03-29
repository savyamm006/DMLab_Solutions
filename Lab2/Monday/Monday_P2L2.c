/*
*Climbing Stairs*

Write a C program that:
- Asks the user for the number of steps N in a staircase.
- Calculates the number of distinct ways to climb to the top, where in each move you can take 1, 2, or 3 steps.
The number of ways for N steps depends on the number of ways for the three previous step counts.
Implement the solution using both recursion and iteration(memoization), and display the results from both methods.

Hint: The sequence begins with 1, 1, 2, …
(For 0 stairs there is only one way to climb – not climbing it!)

Solution:
The problem statement essentially asks what the Nth Tribonacci number is. At the last step, you are taking 1, 2 or 3 steps. 
Hence, number of ways to climb N steps is the sum of :
Ways(n-1)[Then you'll take 1 step], Ways(n-2)[Then you'll take 2 steps] and Ways(n-3)[Then you'll take 3 steps], i.e.
T(n) = T(n-1) + T(n-2) + T(n-3) aka Tribonacci series   
*/
#include <stdio.h>

int stairs_rec(int n)
{
    //Base Case
    if(n<=1) return 1; 
    if(n == 2) return 2;

    //Recursive Case
    return stairs_rec(n-1) + stairs_rec(n-2) + stairs_rec(n-3);
}

int stairs_iter(int n)
{
    //Base Case
    if(n<=1) return 1; 
    if(n == 2) return 2;
    
    int a = 1;
    int b = 1;
    int c = 2;
    //Memoization using variables to store last 3 values
    int next = 0;
    for (int i = 3; i <= n; i++) 
    {
        next = a + b + c;
        a = b;
        b = c;
        c = next;
        //Updating each variable
    }
    
    return next;
}

int main()
{
    int n = 0;
    printf("Enter the number of stairs: ");
    scanf("%d", &n);

    if(n<0)
    {
        printf("Invalid Input");
        return -1;
    }

    int str_rec = stairs_rec(n);
    int str_itr = stairs_iter(n);

    printf("Number of ways to climb(Recursive): %d\n", str_rec);
    printf("Number of ways to climb(Iterative): %d\n", str_itr);

    return 0;
}