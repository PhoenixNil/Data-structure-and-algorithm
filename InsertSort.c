#include <stdio.h>
void InsertionSort(int A[], int N)
{
    int i, temp, j;
    for (i = 0; i < N; i++)
    {
        temp = A[i];
        for (j = i; j > 0 && temp < A[j - 1]; j--) //从0到i前一个元素插
            A[j] = A[j - 1];
        A[j] = temp;
    }
    printf("%d", A[0]);
    for (i = 1; i < N; i++)
        printf(" %d", A[i]);
}
int main()
{
    int N, A[100001] = {0}, i;
    scanf("%d\n", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    InsertionSort(A, N);
}   

//数据大会超时