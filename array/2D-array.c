#include <stdio.h>
#include <stdlib.h>

int main()
{
    // create in stack
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};

    // array of pointers in stack
    int *B[3]; 
    int **C; // double pointer
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j <4; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    // create array in heap
    B[0] = (int *) malloc(4* sizeof(int)); 
    B[1] = (int *) malloc(4* sizeof(int));
    B[2] = (int *) malloc(4* sizeof(int));

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j <4; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }

    //
    C = (int **) malloc(3 * sizeof(int *)); // rows created in heap
    C[0] = (int *) malloc(4 * sizeof(int)); // columns created in heap
    C[1] = (int *) malloc(4 * sizeof(int));
    C[2] = (int *) malloc(4 * sizeof(int));

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j <4; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }



    return 0;
}