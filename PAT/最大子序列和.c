// real_sum是关键，为-1的情况是为了只有0其他的值为负的
#include <stdio.h>
#define MAX 100000
int main(int argc, char const *argv[])
{
    int a[10001] = {0};
    int maxSum = 0, sequence = 0;
    int i, N, realsum = -1, temp_sum = 0, K = 0, start = 0, flag;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < N; i++) //数组的数全为负数的情况
    {
        if (a[i] < 0)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    for (i = 0; i < N; i++)
    {
        temp_sum += a[i];
        if (temp_sum < 0)
        {
            temp_sum = 0;
            continue;
        }
        else
        {
            sequence = (temp_sum > realsum ? temp_sum : realsum);
            if (temp_sum > realsum)
                K = i;
            maxSum = temp_sum + a[i + 1];
            if (sequence >= maxSum) /*a1和a1+a2比*/
                realsum = sequence; //a1大于a1+a2
            else
            {
                realsum = maxSum;
                K = i + 1;
            }
        }
    }
    for (i = K, temp_sum = realsum; i >= 0; i--)
    {
        if (temp_sum - a[i] == 0)
        {
            start = i;
            break;
        }
        temp_sum -= a[i];
    }
    for (i = start - 1; i >= 0; i--)
    {

        if (a[i] != 0)
        {
            break;
        }
        start = i;
    }

    if (realsum == -1 && flag == 1)
    {
        printf("0 %d %d", a[0], a[N - 1]);
    }
    else
        printf("%d %d %d", realsum, a[start], a[K]);
    return 0;
}