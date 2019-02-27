#include <algorithm>
#include <iostream>
#include <vector>
#define max 10005
// 最小的意思是，最开始的最小，意思前面相等才比较后面的，不然就选前面小的序列，不管序列长度
using namespace std;
vector<int> result;
int cmp(int a, int b) { return a > b; } //降序排列，这样新加入的就是小的
int main()
{
    int N, M, i, j;
    int coins[10005];
    int W[max][110];
    int temp;
    bool tag[max][101];
    cin >> N >> M;
    for (i = 1; i < N + 1; i++)
    {
        cin >> coins[i];
    }
    sort(coins + 1, coins + N + 1, cmp);
    for (i = 1; i < N + 1; i++) //W[i][j]代表前i个硬币，不大于j的最大总值
    {
        for (j = 1; j <= M; j++)
        {
            if (j - coins[i] < 0) //坐标不能小于0
            {
                temp = 0;
            }
            else
            {
                temp = W[i - 1][j - coins[i]] + coins[i];
            }

            if (temp < W[i - 1][j]) //如果放入第i枚硬币比没有放入第i枚硬币的值要大
            {
                W[i][j] = W[i - 1][j];
            }
            else
            {
                W[i][j] = temp;   //面值里面有i
                tag[i][j] = true; //记录i这个面值的硬币
            }
        }
    }
    if (W[N][M] != M) //如果给定的所有面值最接近M的值！=M，那就说明没有
    {
        cout << "No Solution";
    }
    else
    {
        while (W[N][M])
        {
            if (tag[N][M] == true)
            {
                result.push_back(coins[N]);
                M -= coins[N];
                N--;
            }
            else
            {
                N--;
            }
        }
        for (i = 0; i < result.size(); i++)
        {
            if (i == result.size() - 1)
            {
                cout << result[i];
            }
            else
                cout << result[i] << " ";
        }
    }
    return 0;
}