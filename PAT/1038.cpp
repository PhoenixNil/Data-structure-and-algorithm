// 需要复习
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool comp(string a, string b)
{
    return a + b < b + a; //只有这样，他才能确定哪个数排在前面是最小
}
int main()
{
    int N, i;
    string result[10005];
    string temp;
    string minnum;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> temp;
        result[i] = temp;
    }
    sort(result, result + N, comp); //这道题使用字符串排序就行了对于两个字符串a和b，比较ab和ba的大小，为了让数字最小，也就是ab < ba是我们所期望的，因此只需要把所有字符串按照这个规则排序即可。
    for (i = 0; i < N; i++)
    {
        minnum += result[i];
    }
    if ((minnum.front() - '0' + minnum.back() - '0') * N == 0)
    {
        cout << 0;
    }
    else
    {
        minnum.erase(0, minnum.find_first_not_of('0'));
        cout << minnum;
    }
    return 0;
}