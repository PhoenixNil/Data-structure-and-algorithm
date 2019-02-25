#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<char> resultA(1000, '0');
vector<char> resultB(1000, '0');
int main()
{
    int N, i, exp1 = 0, dot1 = 0, dot2 = 0, exp2 = 0, temp, j;
    int p = 0, q = 0;
    cin >> N;
    temp = N;
    string A, B;
    cin >> A >> B;
    while (A[p] == '0' || A[p] == '.') //找到第一个有效数字
    {
        p++;
    }
    while (B[q] == '0' || B[q] == '.') //同上
    {
        q++;
    }

    for (i = 0; i < A.length(); i++)
    {
        if (A[i] == '.')
        {
            dot1 = i;
        }
    }
    for (i = 0; i < B.length(); i++)
    {
        if (B[i] == '.')
        {
            dot2 = i;
        }
    }
    for (i = dot1 > N ? N + p : N + (p + 1); i < A.length(); i++)
    {
        if (A[i] == '.')
            continue;
        A[i] = '0'; //补充位数，N之后的位数都为0
    }
    for (i = dot2 > N ? N + q : N + (q + 1); i < B.length(); i++)
    {
        if (B[i] == '.')
            continue;
        B[i] = '0';
    }
    for (i = p, j = 0; i < N + p && i < A.length(); i++, j++)
    {
        if (A[i] == '.')
        {
            N++;
            continue;
        }
        resultA[j] = A[i]; //得到系数
        if (dot1 == 0)
            dot1 = A.length();
        if (p == A.length()) //这个字符串就是0
        {
            exp1 = 0;
        }
        else
        {
            if (dot1 < p)
                exp1 = dot1 - p + 1;
            else
                exp1 = dot1 - p; //得到指数
        }
    }
    N = temp;
    for (i = q, j = 0; i < N + q && i < B.length(); i++, j++)
    {
        if (B[i] == '.')
        {
            N++;
            continue;
        }
        resultB[j] = B[i]; //得到系数
        if (dot2 == 0)
        {
            dot2 = B.length();
        }
        if (q == B.length())
        {
            exp2 = 0;
        }
        else
        {
            if (dot2 < q)
                exp2 = dot2 - q + 1;
            else
                exp2 = dot2 - q; //得到指数
        }
    }
    if (resultA == resultB && exp1 == exp2)
    {
        cout << "YES"
             << " "
             << "0.";
        for (i = 0; i < N; i++)
        {
            cout << resultA[i];
        }

        // 从开始到N，输出result里面的数for(0toN)
        cout << '*' << 10 << '^' << exp1;
    }
    else
    {
        cout << "NO" << ' ' << "0.";
        for (i = 0; i < N; i++)
        {
            cout << resultA[i];
        }
        cout << '*' << 10 << '^' << exp1 << " "
             << "0.";
        for (i = 0; i < N; i++)
        {
            cout << resultB[i];
        }
        cout << '*' << 10 << '^' << exp2;
    }
    return 0;
}