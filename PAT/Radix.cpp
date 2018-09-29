// 就是给你两个数，已知其中一个数的进制，然后求另外一个数是多少进制就可以让两个数相等。
// 这两个数小于10位，但是基数无限制，tag==1 基数是N1的基数，tag ==2 ，基数是N2的基数
// 这道题很多坑，第一 基数没有限制，所有两个数字都要用字符串类型
// 使用二分查找来确定基数，上下界的确定具体看serach函数
#include <iostream>
#include <string>
using namespace std;

long long convert(string N, long long radix) //将字符串转换成以radix为进制的数字
{
    int i = 0;
    long long number, result = 0, M = 1;

    for (i = N.length() - 1; i >= 0; i--)
    {

        if (N[i] >= 'a' && N[i] <= 'z')
        {
            number = N[i] - 'a' + 10; //a-z等于10-35 x-a的ascii值加上9则一一对应上了
        }

        else if (N[i] >= '0' && N[i] <= '9')
        {
            number = N[i] - '0';
        }
        result += number * M;
        M *= radix;
    }
    return result;
}
long long binary_search(string another, long long number) //二分查找基数值，第二个参数是tag选定的数字
{
    long long mid = 0, k = 1;
    int i;
    long long minradix = 0, maxradix = 0; //找到下界和上界

    for (i = 0; i < another.length(); i++)
    {
        if (another[i] >= 'a' && another[i] <= 'z')
        {
            k = another[i] - 'a' + 10;
        }
        else if (another[i] >= '0' && another[i] <= '9')
        {
            k = another[i] - '0';
        }
        minradix = minradix > k ? minradix : k;
    }              //找到各位数字最大的
    minradix += 1; //下界是各位数字上最大的+1
    maxradix = number;
    maxradix = max(minradix, maxradix); //有可能下界比另外一个数字还要大！

    while (minradix <= maxradix)
    {
        mid = (minradix + maxradix) / 2;
        long long t = convert(another, mid); //将another转换成mid进制

        if (t == number) //在这个进制下相等
        {
            return mid;
        }
        else if (t > number || t < 0) //转换之后比N1大，因为不是unsigned long  所以如果很大的话，溢出值就为负了
        {
            maxradix = mid - 1;
        }
        else //转换后比N1小
        {
            minradix = mid + 1;
        }
    }
    return -1; //不存在
}

int main(int argc, char const *argv[])
{
    string N1, N2;
    int tag;
    long long radix, result; //因为 N1 和 N2 都可以是10位数，所以用 longlong int比较好
    long long number1, number2;
    cin >> N1 >> N2 >> tag >> radix;
    if (tag == 1)
    {
        number1 = convert(N1, radix);
        if (binary_search(N2, number1) == -1)
        {
            cout << "Impossible";
        }

        else
        {
            result = binary_search(N2, number1);
            cout << result;
        }
    }
    else if (tag == 2)
    {
        number2 = convert(N2, radix);
        if (binary_search(N1, number2) == -1)
        {
            cout << "Impossible";
        }
        else
        {
            result = binary_search(N1, number2);
            cout << result;
        }
    }
    return 0;
}