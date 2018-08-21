// Nge城市，M条路，C1你所在的城市，C2你需要营救的城市。
//第二行是每个城市的营救队数量
// 接会给你M行，和3个整数 C1 C2 L，L是C1和C2之间的路径长度
//输出C1和C2不同的最短的路径数，你该派的最大营救队伍
#include <iostream>
#include <vector>
#define inf 0x3f3f3f3f
#define MaxSize 505
using namespace std;
typedef struct Graph *LGraph;
struct Graph
{
    int NV;
    int NE;
    int L[MaxSize][MaxSize];
};
int PathCount[MaxSize] = {0}; //路径条数
int people[MaxSize] = {0};    //救援队伍人数
// int EXTRACT_Min(LGraph G, int dist[], bool collect[])
// {
//     int u, i, Mindist = inf;

//     for (i = 0; i < G->NV; i++)
//     {

//         if (dist[i] < Mindist && collect[i] == false) //i未被收录，且i的距离更小
//         {
//             Mindist = dist[i];
//             u = i;
//         }
//     }

//     if (Mindist < inf)
//         return u;
//     else
//         return -1; //这样的点不存在
// }

void dijkstra(LGraph G, int dist[], int PathCount[], int C1, int team[]) //dist是离C1各下标最近距离,PathCount则为路径数
{
    int j, u, i, Mindist;
    bool collect[MaxSize];
    for (i = 0; i < G->NE; i++)
        //  {
        //      dist[i] = G->L[C1][i];
        collect[i] = false;
    //  }

    dist[C1] = 0;
    people[C1] = team[C1];
    PathCount[C1] = 1;

    while (1)
    {
        Mindist = inf;
        for (i = 0; i < G->NV; i++)
        {
            if (dist[i] < Mindist && collect[i] == false) //i未被收录，且i的距离更小
            {
                Mindist = dist[i];
                u = i;
            }
        }
        // u = EXTRACT_Min(G, dist, collect);
        if (Mindist == inf)
            break;
        collect[u] = true;
        for (j = 0; j < G->NV; j++)
        {
            if (collect[j] == false && G->L[u][j] < inf) //未被收录
            {
                if (dist[j] > dist[u] + G->L[u][j])
                {
                    dist[j] = dist[u] + G->L[u][j]; //relax
                    PathCount[j] = PathCount[u];    //路径数
                    people[j] = people[u] + team[j];
                }
                else if (dist[j] == dist[u] + G->L[u][j]) //权值相等，路径数相加
                {
                    PathCount[j] += PathCount[u];
                    if (people[j] < team[u] + team[j])
                        people[j] = people[u] + team[j];
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int dist[MaxSize] = {0};
    int C1, C2, i, j, team[MaxSize] = {0}, c1, c2, L;

    LGraph G;
    G = new (struct Graph);
    cin >> G->NV >> G->NE >> C1 >> C2;
    for (i = 0; i < G->NV; i++)
    {
        dist[i] = inf;
        for (j = 0; j < G->NV; j++)
        {
            // if (i == j)
            //     G->L[i][j] = 0;
            // else
            G->L[i][j] = inf;
        }
    }

    for (i = 0; i < G->NV; i++)
    {

        cin >> team[i]; //输入每个城市的救援队人数
    }

    for (i = 0; i < G->NE; i++)
    {
        cin >> c1 >> c2 >> L;
        G->L[c2][c1] = G->L[c1][c2] = L;
    }
    dijkstra(G, dist, PathCount, C1, team);
    cout << PathCount[C2] << " " << people[C2];
}