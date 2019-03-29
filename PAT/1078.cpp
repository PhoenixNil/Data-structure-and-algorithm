#include <cmath>
#include <iostream>
using namespace std;
int hashtable[10100];
bool isprime(int A)
{
    int i;
    if (A == 1)
    {
        return false;
    }

    for (i = 2; i <= sqrt(A); i++)
    {
        if (A % i == 0)
        {
            return false;
        }
    }
    return true;
}

int closest_prime(int A)
{

    while (!isprime(A))
    {
        A++;
    }
    return A;
}
void insert(int key, int M)
{
    int j, index;
    for (j = 0; j < M; j++)
    {
        index = (key + j * j) % M;
        if (hashtable[index] == 0)
        {
            hashtable[index] = 1;
            cout << index;
            return;
        }
    }
    cout << "-"; //发现从0-M-1的坐标都被人占了，所以输出-
}
int main()
{
    int N, M, i;
    int key;
    cin >> M >> N;        //判断M是否是素数
    M = closest_prime(M); //解决冲突使用二次探方法
    for (i = 0; i < N; i++)
    {
        cin >> key;
        if (i != 0)
            cout << " ";
        insert(key, M);
    }
}