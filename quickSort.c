#include <stdio.h>
int divide(int A[], int start, int last)
{
    int temp1, temp2, i, j, X;
    X = A[last]; //把主元选做最后一个
    i = start - 1;
    for (j = start; j < last; j++)
    {
        if (A[j] <= X)
        {
            i += 1;
            temp1 = A[j];
            A[j] = A[i];
            A[i] = temp1;
        }
    }
    temp2 = A[i + 1];
    A[i + 1] = A[last];
    A[last] = temp2;
    return i + 1;
}
void partition(int A[], int start, int last)
{
    int pivot;
    if (start < last)
    {
        pivot = divide(A, start, last);
        partition(A, start, pivot - 1);
        partition(A, pivot + 1, last);
    }
}
void QuickSort(int A[], int N)
{
    int zero = 0;
    partition(A, zero, N - 1);
}
int main(void)
{
    int N, A[100001], i;
    scanf("%d\n", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    QuickSort(A, N);
    printf("%d", A[0]);
    for (i = 1; i < N; i++)
        printf(" %d", A[i]);
    return 0;
}
