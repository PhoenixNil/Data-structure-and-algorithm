#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> leaves[100005];
vector<int> node[100005];
double P, r, result;
void dfs(int S, int depth)
{
    int i;
    if (!leaves[S].empty())
    {
        result += leaves[S].front() * pow(1 + r, depth);
        return;
    }
    else
    {
        for (i = 0; i < node[S].size(); i++)
        {
            dfs(node[S][i], depth + 1);
        }
    }
}
int main()
{
    int N, i, j, child, K;
    cin >> N >> P >> r;
    r = r / 100;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &K);
        if (K == 0)
        {
            cin >> child;
            leaves[i].push_back(child);
        }
        else
        {
            for (j = 0; j < K; j++)
            {
                cin >> child;
                node[i].push_back(child);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f", result * P);
    return 0;
}