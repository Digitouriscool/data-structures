#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[210];
    int size;
    int length;
};

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *x;
    *y = temp;
}

void Display(struct Array arr) 
{
    int i;
    printf("\nElements are\n");
    for(i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr, int x) 
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    int i;

    if (index >= 0 && index <=arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;

    if (index >= 0 && index <= arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length --;
        return x;
    }
    return 0;
}

int LinearSearch(struct Array *arr, int key)
{
    int i;

    for (i = 0; i < arr->length; i++) {
        if (key == arr->A[i])
            {
                // swap(&arr->A[i], &arr->A[i-1]); // transposition
                swap(&arr->A[i], &arr->A[0]); // move to header / front
                return i;
            }
    }

    return -1;
}


int BinarySearch(struct Array arr, int key)
{
    int low, mid, high;
    low = 0;
    high = arr.length - 1;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;     
}

int RBinSearch(int a[], int low, int high, int key)
{
    int mid;

    if (low < high) {
        mid = (low + high) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinSearch(a, low, mid - 1, key);
        else 
            return RBinSearch(a, mid + 1, high, key);
    }
    
    return -1;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    int n, i;

    // Append function
    // Append(&arr, 10);

    //Insert function
    // Insert(&arr, 0, 10);

    // Delete function
    // printf("%d\n", Delete(&arr, 4));

    // Linear Search function
    // printf("%d\n", LinearSearch(&arr, 4));

    // Binary Search function
    printf("%d\n", BinarySearch(arr, 4));

    // Recursive Binary Search function
    printf("%d\n", RBinSearch(arr.A, 0, arr.length, 9));

    Display(arr);
        
    return 0;
}