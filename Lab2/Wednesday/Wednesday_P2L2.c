/*
*Taylor Series*

Write a C program that approximates the value of ex  using the Taylor series:
e^x= 1 + x/1!+ x^2/2!+x^3/3!+ ... + x^n/n!

The program should:
- Ask the user for a real number x and the number of terms N (>1) and return the sum of the first N terms.
- Implement the solution using both recursion and iteration(memoization), and display the results from both methods.

Hint: You can use the formula to calculate the value of the next term: 
Term(n)= Term(n-1) * (x/n) 
Maintain a running sum of the terms while memoising to get the final result up to the n-th term.

Solution: Sum(n) = Sum(n-1) + Term(n)
Since the series starts with x^0/0! (= 1), to evaluate the sum of N terms it goes from 0 to N-1, i.e
you need to pass sum(N-1) when you call it in the main function

Note: Incase <math.h> was included for the code, you have to use:
"gcc -o out1 <prog_name>.c -lm" instead of the standard compiling statement. 
However, the problem can be solved without the use of pow(x, i) as well, as illustrated in this solution.
*/

#include <stdio.h>

//Calulating the N-th term
// Can use the pow function to calculate term(x, n), though a fact(n) function will be needed instead
float term(float x, int n)
{
    if(n == 0) return 1.0; // Base Case

    return term(x, n-1) * (x/n);
}

//Calculating the sum of N terms (It starts from term(n-1))
float taylor_rec(float x, int n)
{
    if(n == 0) return 0.0; // Base Case: Sum of zero terms is zero

    return term(x, n-1) + taylor_rec(x, n-1);
}

float taylor_memo(float x, int n)
{
    if(n == 0) return 0.0;// If the loop starts from 0, there will be a 'Division by Zero' error

    float term = 1.0;
    float sum = 1.0;// The sum starts from 1 + x + ...

    for(int i = 1; i < n; i++)
    {
        term = term * (x/n);
        sum = sum + term;
    }
    //Updating the term and the sum simultaneously

    return sum;
}

int main()
{
    int n = 0;
    float x = 0.0;
    
    printf("Enter x: ");
    scanf("%f", &x);

    printf("Enter number of terms: ");
    scanf("%d", &n);

    float ty_rec = taylor_rec(x, n);
    float ty_itr = taylor_iter(x, n);

    printf("Result(Recursive): %f\n", ty_rec);
    printf("Result(Iterative): %f\n", ty_itr);

    return 0;
}