#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> temp;
int N, L;
vector<vector<int>> v;
int compute(int source)
{
    int level[1005] = {0};
    bool visit[1005] = {false};
    int result = 0, i, pre;
    temp.push(source);
    visit[source] = true;
    while (!temp.empty())
    {
        pre = temp.front();
        temp.pop();
        for (i = 0; i < v[pre].size(); i++)
        {
            if (visit[v[pre][i]] == false && (level[pre] < L)) //该节点层数小于L
            {
                level[v[pre][i]] = level[pre] + 1;
                temp.push(v[pre][i]);
                visit[v[pre][i]] = true;
                result++;
            }
        }
    }
    return result;
}
int main()
{
    int i, j, K, temp2, result, m;
    int temp3;
    scanf("%d %d", &N, &L);
    v.resize(N + 1);
    for (i = 1; i < N + 1; i++)
    {
        scanf("%d", &m);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &temp3);
            v[temp3].push_back(i);
        }
    }
    cin >> K;
    for (i = 0; i < K; i++)
    {
        scanf("%d", &temp2);
        result = compute(temp2);
        cout << result << endl;
    }
    return 0;
}