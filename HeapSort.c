#include <stdio.h>
int A[100001];
void BulidHeap(int A[], int i, int N) //建立最大堆 ,i是对该元素建堆，N是堆的规模
{
    int right, left, temp, largest;
    right = 2 * i + 1;
    left = 2 * i;
    if (right <= N && A[i] < A[right]) //小于右边
        largest = right;
    else
        largest = i;
    if (left <= N && A[largest] < A[left]) //左边更大一些
        largest = left;
    if (i != largest) //把最大的数放到根节点
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        BulidHeap(A, largest, N); // 对堆的调整,根据largest这个节点来调整，使新堆满足规则
    }
}
void HeapSort(int A[], int N)
{
    int i, temp, Root;
    Root = 1; //根节点就是第一个节点
    for (i = N / 2; i > 0; i--)
    {
        BulidHeap(A, i, N); //从N到1建堆,找到N/2的节点，然后一直到1建立堆，一共N个元素
    }
    for (i = N; i > 1; i--)
    {
        temp = A[i];
        A[i] = A[Root];
        A[Root] = temp; //A[n]和Root交换
        N -= 1;
        BulidHeap(A, 1, N); //每次对根重新建堆
    }
}
int main(void)
{
    int N, i;
    scanf("%d\n", &N);
    for (i = 1; i < N + 1; i++)
        scanf("%d", &A[i]);
    HeapSort(A, N);
    printf("%d", A[1]);
    for (i = 2; i < N + 1; i++)
        printf(" %d", A[i]);
    return 0;
}