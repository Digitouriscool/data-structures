#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create array in stack
    int A[5] = {2, 4, 6, 8, 10};
    int i;

    // Create array in heap
    int *p; // declare pointer
    p = (int *) malloc(5 * sizeof(int)); // create array of size 5 in heap
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    for(i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");

    for(i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
    return 0;
}