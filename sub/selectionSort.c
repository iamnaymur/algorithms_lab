#include <stdio.h>

int main()
{
    int A[] = {20, 50, 5, 2, 40, 60, 10, 55, 25, 46, 89, 90, 100};
    int n = sizeof(A) / sizeof(A[0]);
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }

    //! Result printing
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}