#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node
{
    int data;
    struct Node *next;
} 
*first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

int count(struct Node *p)
{
    int length = 0;

    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

int Rcount(struct Node *p)
{
    if (p != NULL)
        return Rcount(p->next) + 1;
    else 
        return 0;
}

int sum(struct Node *p)
{
    int sum = 0;

    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int Rsum(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return Rsum(p->next) + p->data;
}

int Max(struct Node *p)
{
    int max = INT32_MIN;
    
    while(p)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int RMax(struct Node *p)
{
    int x = 0;
    
    if(p == 0)
        return INT32_MIN;
    x = RMax(p->next) ;
    if(x > p->data)
        return x;
    else return p->data;
}

int Min(struct Node *p)
{
    int min = INT32_MAX;
    
    while(p)
    {
        if(p->data < min)
            min = p->data;
        p = p->next;
    }
    return min;
}

int RMin(struct Node *p)
{
    int x = 0;
    
    if(p == 0)
        return INT32_MAX;
    x = RMin(p->next) ;
    if(x < p->data)
        return x;
    else return p->data;
}

int main()
{
    int A[]= {3, 5, 7, 10, 25, 8, 32, 2};

    create(A, 8);

    // iterative display
    Display(first);

    // recursive display
    RDisplay(first);

    // iterative count
    printf("\nLength is %d", count(first));

    // recursive count
    printf("\nLength is %d", Rcount(first)); 

    // iterative sum
    printf("\nSum is %d", sum(first)); 

    // recursive sum
    printf("\nSum is %d", Rsum(first)); 

    // iterative max
    printf("\nMax is %d", Max(first)); 

    // recursive max
    printf("\nMax is %d", RMax(first)); 

    // iterative min
    printf("\nMin is %d", Min(first)); 

    // recursive max
    printf("\nMin is %d", RMin(first)); 

    return 0 ;
}