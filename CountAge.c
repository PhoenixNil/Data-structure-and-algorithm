#include <stdio.h>
#include <stdlib.h>
int main()
{
    int A[100001] = {0}, i, N, k;
    scanf("%d\n", &N);
    if (N == 0)
        return 0;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &k); //给每个桶输入数据
        A[k]++;
    }
    for (i = 0; i <= 50; i++)
        if (A[i] == 0)
            ;
        else
            printf("%d:%d\n", i, A[i]);
    return 0;
}
//建50个桶，输入一个数据就给每个桶+1,遍历每个桶就行了