#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    if (n <= 0)
        return;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;

    if (n <= 0)
        return;

    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void FreeList(struct Node *p)
{
    struct Node *q;

    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }

    first = NULL;
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
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
    int total = 0;

    while (p != NULL)
    {
        total += p->data;
        p = p->next;
    }

    return total;
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

    while (p)
    {
        if (p->data > max)
            max = p->data;

        p = p->next;
    }

    return max;
}

int RMax(struct Node *p)
{
    int x;

    if (p == NULL)
        return INT32_MIN;

    x = RMax(p->next);

    if (x > p->data)
        return x;
    else
        return p->data;
}

int Min(struct Node *p)
{
    int min = INT32_MAX;

    while (p)
    {
        if (p->data < min)
            min = p->data;

        p = p->next;
    }

    return min;
}

int RMin(struct Node *p)
{
    int x;

    if (p == NULL)
        return INT32_MAX;

    x = RMin(p->next);

    if (x < p->data)
        return x;
    else
        return p->data;
}

struct Node *LSearch(struct Node *p, int key)
{
    struct Node *q = NULL;

    while (p != NULL)
    {
        if (key == p->data)
        {
            /*
               Move to front only if the found node
               is not already the first node.
            */
            if (q != NULL)
            {
                q->next = p->next;
                p->next = first;
                first = p;
            }

            return p;
        }

        q = p;
        p = p->next;
    }

    return NULL;
}

struct Node *RSearch(struct Node *p, int key)
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

    t = (struct Node *)malloc(sizeof(struct Node));
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

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;

    if (index < 1 || index > count(p))
        return -1;

    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);

        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        free(p);

        return x;
    }
}

int isSorted(struct Node *p)
{
    int x = INT32_MIN;

    while (p != NULL)
    {
        if (p->data < x)
            return 0;

        x = p->data;
        p = p->next;
    }

    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q;

    if (p == NULL)
        return;

    q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void Reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;

    A = (int *)malloc(sizeof(int) * count(p));

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = p;
    i--;

    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }

    free(A);
}

void Reverse2(struct Node *p)
{
    struct Node *q = NULL;
    struct Node *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first = q;
}

void Reverse3(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void Concat(struct Node *p, struct Node *q)
{
    third = p;

    while (p->next != NULL)
        p = p->next;

    p->next = q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;

    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p)
        last->next = p;

    if (q)
        last->next = q;
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;

    p = q = first;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;

    } while (p && q && p != q);

    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    struct Node *t1, *t2;
    struct Node *temp;

    int A[] = {10, 20, 30, 40, 50};

    create(A, 5);

    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = NULL;

    printf("%d\n", isLoop(first));

    printf("Original list:\n");
    Display(first);

    printf("Recursive display:\n");
    RDisplay(first);
    printf("\n");

    printf("\nLength is %d", count(first));
    printf("\nRecursive length is %d", Rcount(first));

    printf("\nSum is %d", sum(first));
    printf("\nRecursive sum is %d", Rsum(first));

    printf("\nMax is %d", Max(first));
    printf("\nRecursive max is %d", RMax(first));

    printf("\nMin is %d", Min(first));
    printf("\nRecursive min is %d\n", RMin(first));

    temp = LSearch(first, 30);

    if (temp)
        printf("\nKey is Found: %d\n", temp->data);
    else
        printf("\nKey is not found\n");

    printf("List after move-to-front search:\n");
    Display(first);

    temp = RSearch(first, 40);

    if (temp)
        printf("\nKey is Found: %d\n", temp->data);
    else
        printf("\nKey is not found\n");

    printf("\nInsert examples:\n");

    Insert(first, 0, 5);
    Insert(first, 3, 25);

    Display(first);

    printf("\nSorted insert example:\n");

    SortedInsert(first, 35);

    Display(first);

    printf("\nDeleted Element: %d\n", Delete(first, 4));

    Display(first);

    if (isSorted(first))
        printf("\nSorted\n");
    else
        printf("\nNot Sorted\n");

    FreeList(first);

    /*
       Remove duplicates example.
       RemoveDuplicate() works correctly on a sorted linked list.
    */

    int B[] = {
        10, 10, 10,
        20, 20, 20,
        30,
        40, 40, 40,
        50
    };

    create(B, 11);

    printf("\nList with duplicates:\n");
    Display(first);

    RemoveDuplicate(first);

    printf("After removing duplicates:\n");
    Display(first);

    printf("\nReverse using array:\n");
    Reverse1(first);
    Display(first);

    printf("\nReverse using sliding pointers:\n");
    Reverse2(first);
    Display(first);

    printf("\nReverse using recursion:\n");
    Reverse3(NULL, first);
    Display(first);

    FreeList(first);

    /*
       Concatenation example

       first was set to NULL by FreeList(), so both
       lists must be created before calling Concat().
    */

    int C[] = {10, 20, 30, 40, 50};
    int D[] = {1, 2, 3, 4, 5};

    create(C, 5);
    create2(D, 5);

    printf("\nFirst list:\n");
    Display(first);

    printf("Second list:\n");
    Display(second);

    Concat(first, second);

    printf("Concatenated:\n");
    Display(third);

    printf("\n");

    return 0;
}