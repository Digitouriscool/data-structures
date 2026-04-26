#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

int main()
{
    // Integer Pointer
    int a = 10;
    int *p; // pointer declaration
    p = &a; // store address of a inside p

    cout<<a<<endl;
    printf("using pointer %d\n", *p); //dereferencing

    // Array Pointer
    // int A[5] {2, 4, 6, 8, 10};
    // int *p;
    // p = A; // an "&" is not needed storing address of an array
    // int *k; 
    // k = &A[0]; // stores the address of the first element of the array

        // // print elements of an array using the pointer
    // for (int i = 0; i < 5; i ++)
    //     cout<<A[i]<<endl;

    // Create array in heap memory
    // int *p;
    // // p = (int *) malloc(5 * sizeof(int)); // allocate memory in c 
    // p = new int[5]; // allocate memory in c++
    // p[0] = 10; p[1] = 15; p[2] = 14; p[3] = 21; p[4] = 31;

    // for (int i = 0; i < 5; i++)
    // cout<<p[i]<<endl;



    // Every pointer takes the same amount of memory (8 bytes in latest compilers on 64-bit machines)
    // Size of a pointer is independent of its data type
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;


    // delete [ ] p; // release memory in c++
    // // free(p); // release memory in c

    return 0;
}