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
    // struct Rectangle r = {10, 5};
    // cout<<r.length<<endl;
    // cout<<r.breadth<<endl;

    // // print length / bread using pointer
    // Rectangle *p = &r;
    // cout<<p->length<<endl;
    // cout<<p->breadth<<endl;


    // Create object in heap
    struct Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->length = 15;
    p->breadth = 7;
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;

    return 0;
}