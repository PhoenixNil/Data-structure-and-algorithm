#include <iostream>
using namespace std;
template <int N>
struct Factorial
{
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0>
{
    static const int value = 1;
};

int main()
{
    // 计算5的阶乘
    const int factorial_of_5 = Factorial<5>::value;
    cout << "5! = " << factorial_of_5 << endl; // 输出120
    return 0;
}
