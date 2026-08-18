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

struct Node * LSearch(struct Node *p, int key)
{
    struct Node *q;

    while (p != NULL)
    {
        if (key == p->data)
        {
            // move to front if found
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node * RSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RSearch(p->next, key);
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > count(p))
        return;
    t = (struct Node *) malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else 
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
    
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *) malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t-> next = first;
            first = t;
        }
        else 
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    struct Node *temp;
    int A[]= {10, 20, 30, 40, 50};

    create(A, 5);

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

    // recursive min
    printf("\nMin is %d", RMin(first)); 

    // linear search
    temp = LSearch(first, 25);
    temp = LSearch(first, 8);
    if (temp)
        printf("\nKey is Found %d\n", temp->data);
    else
        printf("\nKey is not found\n");

    // display
    Display(first);

    // recursive search
    temp = RSearch(first, 27);
    if (temp)
        printf("\nKey is Found %d\n", temp->data);
    else
        printf("\nKey is not found\n");

    // insert
    // Insert(first, 0, 10);
    // Insert(first, 3, 10);
    // Insert(first, 8, 10);
    // Display(first);

    // sorted insert
    SortedInsert(first, 35);
    Display(first);
    printf("\n\n");
    


    return 0 ;
}