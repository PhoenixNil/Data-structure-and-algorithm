#include <iostream>
#include <stack>
#include <vector>
#define max 1010
using namespace std;
stack<int> OP;
vector<int> result;
int main()
{
    int number[max];
    int M, N, K, i, j, postion = 1;
    bool flag;
    cin >> M >> N >> K;
    for (i = 0; i < K; i++)
    {
        for (j = 1; j <= N; j++)
        {
            cin >> number[j];
        }
        postion = 1;
        flag = false;
        while (!OP.empty())
            OP.pop();
        for (j = 1; j <= N; j++)
        {
            OP.push(j);
            if (OP.size() > M) //如果发现从1-M都没发现等于栈顶的，那就说明这个序列不存在，因为第一个数大于M，而这个栈无法插入M个数
            {
                break;
            }
            while (!OP.empty() && number[postion] == OP.top()) //和栈顶相等，就出栈，然后一直比较栈顶
            {
                OP.pop();
                postion++; //比较输入序列的下一个
            }
            if (OP.empty() && postion == N + 1)
                flag = true;
        }
        if (flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}