// 并查集看图是否连通,不连通就计算连通分量，连通就计算最深的根
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define max 10000
#define inf 99999
using namespace std;
int Set[max] = {inf};
int Rank[max];
bool visited[max]; //节点是否访问数组
int deepest[max];
vector<int> Gnode[max];
int maxheight = 0;
vector<int> Root;
int FindSet(int X)
{
    if (Set[X] == X)
        return X;
    else
        return FindSet(Set[X]);
}

void Link(int X, int Y)
{
    if (Rank[X] < Rank[Y]) //小树并入大树，深度不会变
        Set[X] = Y;
    else
    {
        if (Rank[X] == Rank[Y]) //两树规模相等，深度会加1
            Rank[X]++;
        Set[Y] = X;
    }
}

void UnionSet(int X, int Y)
{
    if (FindSet(X) == FindSet(Y))
        ;
    else
        Link(FindSet(X), FindSet(Y));
}

int dfs(int v, int N, int Height)
{
    int i;
    visited[v] = true;
    if (Height > maxheight)
        maxheight = Height;
    for (i = 0; i < Gnode[v].size(); i++)
    {
        if (visited[Gnode[v][i]] == false)
            dfs(Gnode[v][i], N, Height + 1);
    }
    return maxheight;
}

int main(int argc, char const *argv[])
{
    int N, i, K = 1, temp;
    int V1, V2;
    cin >> N;
    for (i = 1; i < N + 1; i++) //make set
    {
        Set[i] = i;
        Rank[i] = 0;
    }
    for (i = 0; i < N - 1; i++) // 1-N
    {
        cin >> V1 >> V2;
        Gnode[V1].push_back(V2);
        Gnode[V2].push_back(V1);
        UnionSet(V1, V2);
    }
    sort(Set, Set + N + 1);
    temp = Set[0];
    for (i = 0; i < N; i++)
    {
        if (Set[i] != temp)
        {
            temp = Set[i];
            K++;
        }
    }
    if (K != 1)
        printf("Error: %d components", K);

    else
    {
        for (i = 1; i < N + 1; i++)
        {
            deepest[i] = dfs(i, N, 0); //对这个图dfs，找到最深的根
            maxheight = 0;
            fill(visited, visited + N + 1, false);
        }
        for (i = 0; i < N + 1; i++)
        {
            if (deepest[i] == *max_element(deepest, deepest + N))
            {
                cout << i << endl;
            }
        }
    }
    return 0;
}