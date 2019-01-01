#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define max 550
#define inf 9999
using namespace std;
//BFS
int M, N;
queue<int> temp;
vector<vector<int>> path(max);
bool visit[max];
int d[max],lost[max];
struct Gnode
{
    int length;
    int Cost;
} G[max][max];
void BFS(int S)
{
    int i,pre;
    d[S] = 0;
    temp.push(S);
    path[S].push_back(S);
    while (!temp.empty())
    {
        pre = temp.front();
        visit[pre] = true;
        temp.pop();
        for (i = 0; i < N; i++)
        {
            if (G[pre][i].length != 0)
            {
                if (visit[i] == false)
                {
                    temp.push(i);
                    if (d[pre] + G[pre][i].length < d[i])
                    {
                        lost[i] = lost[pre] + G[pre][i].Cost;
                        d[i] = d[pre] + G[pre][i].length;
                        path[i].assign(path[pre].begin(), path[pre].end()); //这个路径清空，换成更小的路径
                        path[i].push_back(i);
                    }

                    else if (d[pre] + G[pre][i].length == d[i]) //长度相等，比较cost
                    {
                        if (lost[i] > lost[pre] + G[pre][i].Cost)
                        {
                            lost[i] = lost[pre] + G[pre][i].Cost;
                            d[i] = d[pre] + G[pre][i].length;
                            path[i].assign(path[pre].begin(), path[pre].end()); //这个路径清空，换成更小的路径
                            path[i].push_back(i);
                        }
                    }
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int S, D, v1, v2, distance, cost, i;
    scanf("%d%d%d%d", &N, &M, &S, &D);
    fill(d, d + max, inf);
    for (i = 0; i < M; i++)
    {
        cin >> v1 >> v2 >> distance >> cost;
        G[v1][v2].length = G[v2][v1].length = distance;
        G[v1][v2].Cost = G[v2][v1].Cost = cost;
    }
    BFS(S);
    for (auto &&i : path[D])
        cout << i << " ";
    printf("%d %d", d[D], lost[D]);
    return 0;
}