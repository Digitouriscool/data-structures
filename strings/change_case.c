#include <stdio.h>

int main()
{
    char A[] = "WELCOME";
    char B[] = "wElCome";
    int i, j;

    // Upper to Lower
    for (i = 0; A[i] != '\0'; i++) {
        A[i] = A[i] + 32;
    }

    // Toggle mixed cases
    for (j = 0; B[j] != '\0'; j++) {
        if (B[j] >= 65 && B[j] <= 90)
            B[j] += 32;
        else if (B[j] >= 'a' && B[j] <= 122)
            B[j] -= 32;
    }

    printf("%s\n", A);
    printf("%s", B);
    return 0;
}