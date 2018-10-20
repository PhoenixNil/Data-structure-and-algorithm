#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define max 1000 + 5
#define inf 5000
int city[max][max] = {{inf}};
int findsubgraph(int newgraph[max][max], int V, int E, int keycity) {
    vector<int> ancestor;
    int road = 1, key;
    int i, j;
    for (int j = 0; j < max; ++j) {
        newgraph[j][j] = j;
    }
    for (i = 1; i < V + 1; i++)
    {
        newgraph[keycity][i] = inf;
        newgraph[i][keycity] = inf;
    }

    for (i = 1; i < V + 1; i++)
    {
        for (j = 1; j < V + 1; j++)
        {
            if (i == j)
                continue;
            else
            {
                if (newgraph[i][j] == 1)
                {
                    if (newgraph[j][j] >= newgraph[i][i])
                        newgraph[j][j] = newgraph[i][i];
                    else
                        newgraph[i][i] = newgraph[j][j];
                }
            }
        }

        if (i == keycity)
            continue;
        ancestor.push_back(newgraph[i][i]);
    }
    sort(ancestor.begin(), ancestor.end());
    key = ancestor[0];
    for (i = 0; i < ancestor.size(); i++)
    {

        if (ancestor[i] != key)
        {
            key = ancestor[i];
            road++;
        }
    }

    return road;
}

int main(int argc, char const *argv[])
{
    int newgraph[max][max];
    int road = 0;
    int V, E, K, i;
    int city1, city2, keycity;
    //graph init
    fill((int*)city,(int *)city+max*max,inf);
    cin >> V >> E >> K;
    for (i = 0; i < max; i++)
        city[i][i] = i;
    for (i = 0; i < E; i++)
    {
        cin >> city1 >> city2;
        city[city1][city2] = 1;
        city[city2][city1] = 1;
    }

    for (i = 0; i < K; i++)
    {
        scanf("%d", &keycity);
        memcpy(newgraph, city, 4000000);
        road = findsubgraph(newgraph, V, E, keycity);
        cout << road-1 << endl;
    }
    return 0;
}