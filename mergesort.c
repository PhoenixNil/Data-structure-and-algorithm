#include <stdio.h>
#include<stdlib.h>
void merge(int A[], int TempA[], int start, int mid, int last) /*合并两个序列,
从start到左边界，从mid到终点*/
{
    int temp, leftEnd, number, i; //从start开始传入
    number = last - start + 1;
    temp = start;
    leftEnd = mid - 1; //左边界是Mid-1
    while (start <= leftEnd && mid <= last)
    {
        if (A[start] <= A[mid])
            TempA[temp++] = A[start++];
        else
            TempA[temp++] = A[mid++];
    }
    while (start <= leftEnd)
        TempA[temp++] = A[start++];
    while (mid <= last)
        TempA[temp++] = A[mid++];
    for (i = 0; i < number; i++, last--)
        A[last] = TempA[last]; //将有序的TempA[]返回给A里面去
}

void Merge_pass(int A[], int TempA[], int N, int length)
{
    int i, j = 0;
    for (i = 0; i < N - 2 * length; i += 2 * length)
        merge(A, TempA, i, i + length, i + 2 * length - 1); //以间隔为length进行归并，先是间隔为1，然后2，然后4，直到N（单数要分情况讨论）
    if (i + length < N)
        merge(A, TempA, i, i + length, N - 1); //归并最后两个子列
    else
        for (j = i; j < N; j++) //最后只剩下一个子序列了
            TempA[j] = A[j];
}

void MergeSort(int A[], int N)
{
    int i, length = 1;
    int *TempA;
    TempA = malloc(N * sizeof(int));
    if (TempA != NULL)
    {
        while (length < N)
        {
            Merge_pass(A, TempA, N, length);
            length *= 2;
            Merge_pass(TempA, A, N, length);
            length *= 2;
        }
        printf("%d", A[0]);
        for (i = 1; i < N; i++)
            printf(" %d", A[i]);
        free(TempA);
    }
    else
        printf("空间不足");
}
int main(void)
{
    int A[10001], N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    MergeSort(A, N);
    return 0;
}