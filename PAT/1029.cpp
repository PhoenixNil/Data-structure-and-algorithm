// 这道题如果读入全部数据会内存超限
// 双指针的方法逐个比较
// 因为数据过多，使用排序会超时
#include <algorithm>
#include <cstdio>
#include <iostream>
#define INF 0X7FFFFFFF
using namespace std;
typedef long long LL;
const int Max = 200005;
int a[Max];
int main()
{
    int n1, n2, temp, mid, i, count = 0, result = 0, flag = 0;
    scanf("%d", &n1);
    a[n1 + 1] = Max;
    for (i = 1; i <= n1; i++) //从1开始输入，所以是小于等于
        scanf("%d", &a[i]);
    scanf("%d", &n2);
    mid = (n1 + n2 + 1) / 2;
    // count = n1;
    // i--;
    i = 1;
    for (int j = 1; j <= n2; j++)
    {
        scanf("%d", &temp); //在n1之后的元素插入
        // if (temp < a[i])
        // {
        //     if (count >= mid) //说明在插入这个数之后，原来的最后一个数已经超过了中位数的位置了
        //     {
        //         // a[i] = temp;
        //         // sort(a, a + i + 1);
        //     }
        //     else
        //         count++;
        // }

        while (temp >= a[i]) //temp是不是比前面所有数都要大
        {
            count++;
            if (count == mid)
            {
                printf("%d", a[i]); //此时的temp比a[i]大,后面的自然要比temp,前面的又比a[i]小，而a[i]又是Mid位置，所以输出
            }
            i++; //记录下temp在数组所在的位置，下一次从比temp大的数开始while
        }
        count++;
        // else
        // {
        if (count == mid && flag == 0) //判断第二个数组的这个数是不是Mid
        {
            // result = a[i];
            result = temp;
            printf("%d", temp);
            flag = 1;
        }

        // else //第二个数组的这个数还没到Mid，因为此时这个数已经比原来的数组的最大的数还要大了，所以接下来的数就会都在数组的后面，
        // mid自然也在接下来输入的后面
        // a[i] = temp;
        // count++;
    }
    // }
    while (i <= n1) //第二个数组元素太少，mid是第一个数组的元素，通过temp位置找到Mid位置就好了,不能直接找mid位置，mid位置肯定在count后面，因为，如果在count前面
    // 自然mid可以变成更前面的temp后面一个
    // 因为此时的mid相当于在原来的数组插入了第二个数组的值
    {
        count++; //第二个数组最后一个temp值所在位置，总数组的位置
        if (count == mid)
        {
            printf("%d", a[i]);
            // else
            //     printf("%d", result);
        }
        i++; //从count到n1找到mid
    }
    return 0;
}