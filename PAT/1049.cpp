// 好难呀，复习！
#include <iostream>
using namespace std;
int main()
{
    // 计算每一位的1各种情况，然后相加
    // 这种研究方法是科学的，因为每一位都考虑了自己的1，那么合起来对于多个1的问题就自然考虑进来了
    int now, left, right, a = 1;
    int ones = 0;
    int N;
    cin >> N;
    while (N / a)
    {
        now = N / a % 10;
        left = N / a / 10;
        right = N % a;
        if (now == 0) //这一位为0，那么只有在他左边变才会产生1，而左边每次变的时候，0-a右边a个数字不断地变换,然后相乘
        {
            ones += left * a;
        }
        else if (now == 1)
        {
            ones += left * a + right + 1;
        }
        else
        {
            ones += (left + 1) * a;
        }
        a *= 10;
    }
    cout << ones;
    return 0;
}