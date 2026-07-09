#include <stdio.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void perm(char S[], int low, int high)
{
    int i;

    if (low == high)
        printf("%s\n", S);
    else {
        for (i = low; i <= high; i++) {
            swap(&S[low], &S[i]);
            perm(S, low + 1, high);
            swap(&S[low], &S[i]);
        }
    }
}

int main()
{
    char S[] = "ABC";
    perm(S, 0, 2);

    return 0;
}