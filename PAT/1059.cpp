//建立素数表
#include <cmath>
#include <iostream>
using namespace std;
#define max 500000
int main()
{
    long int N, temp, cnt = 0, cnt2 = 1;
    bool flag, first = false;
    int i, j;
    int Prime[max];
    for (i = 2; i < max; i++) //建立素数表
    {
        temp = sqrt(i);
        for (j = 2; j <= temp; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j == temp + 1)
        {
            Prime[cnt] = i;
            cnt++;
        }
    }
    cin >> N; //N必须是合数
    if (N == 1)
        cout << "1=1";
    else
    {
        temp = sqrt(N); //找到从1-sqrt(N)的所有因子
        cout << N << "=";
        for (i = 0; Prime[i] <= temp && N >=2; i++)
        {
            flag = false;
            cnt2 = 0;                 //指数
            while (N % Prime[i] == 0) //除以素数表的每一个数，找到对应的因子和指数
            {
                N = N / Prime[i];
                cnt2++;
                flag = true; //找到素数就输出
            }
            if (first == true && flag == true)
            {
                cout << '*';
            }
            if (flag)
            {
                cout << Prime[i];
                first = true;
            }
            if (cnt2 >= 2)
                cout << '^' << cnt2;
        }
    }
    return 0;
}