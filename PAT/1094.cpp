#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int N, M;
vector<vector<int>> G(100);
int layer[100] = {0};
int people[100];
bool flag[100];
void bfs(int S)
{
    int T, i;
    layer[S] = 1;
    queue<int> R;
    R.push(S);
    while (!R.empty())
    {
        T = R.front();
        R.pop();
        people[layer[T]]++;
        for (i = 0; i < G[T].size(); i++)
        {
            layer[G[T][i]] = layer[T] + 1; //他的层数是上一层+1
            R.push(G[T][i]);
        }
    }
}

int main()
{
    int i, temp, K, j, number, biggest = 0, index = 1;
    cin >> N >> M;
    for (i = 0; i < M; i++)
    {
        cin >> temp >> K;
        for (j = 0; j < K; j++)
        {
            cin >> number;
            G[temp].push_back(number);
        }
    }
    bfs(1);
    for (i = 1; i < 100; i++)
    {
        if (people[i] > biggest)
        {
            index = i;
            biggest = people[i];
        }
    }
    cout << biggest << " " << index;
    return 0;
}