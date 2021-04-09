#include <iostream>
#include <string>
using namespace std;

int *compute_prefix(string P) //计算模式P的前缀，下一步的偏移量存在pi数组中
{
    int m, k, q;
    m = P.length();
    int *pi = new int[m]; //需要内存申请
    pi[0] = 0;
    k = 0;
    for (q = 1; q < m; q++)
    {
        while (k > 0 && (P[k] != P[q])) //不匹配。精髓！！！，自己拿笔动一动，才能有感受
            k = pi[k];
        if (P[k] == P[q]) //匹配
            k = k + 1;
        pi[q] = k; //这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给pi[q]
    }
    //找到最长公共子串的目的，什么是最长公共子串呢？就是类似于 ABCBA这种，从前往后，和从后往前都是ABC或者ABEAEE,对于最后一个E来说，他前面的串
    //是ABEAE，从前往后，和从后往前没有一个相同的，因为第一个就不同了，所以他的最长公共子串为0
    return pi;
}

void KMP(string T, string P) //string在c++是类
{
    int n, m, q, i;
    int *pi;
    int flag;
    n = T.length();
    m = P.length();
    pi = compute_prefix(P); //计算前缀函数，即接下来的偏移量
    q = 0;                  //已匹配的字符
    for (i = 0; i < n; i++)
    {
        while (q > 0 && (P[q] != T[i])) //不匹配，同上
            q = pi[q];
        if (P[q] == T[i]) //下个字符匹配
            q = q + 1;
        if (q == m) //全部匹配
        {
            flag = 1;
            cout << "shift " << i - m + 1 << endl;
            q = pi[q - 1]; //找下一个匹配值(不能大于m)
        }
    }
    if (!flag)
    {
        cout << "no find";
    }

    delete (pi);
}

int main(int argc, char const *argv[])
{
    string T, P;
    cout << "please input text T:" << endl;
    getline(cin, T);
    cout << "please input pattern" << endl;
    getline(cin, P);
    KMP(T, P);
    return 0;
}