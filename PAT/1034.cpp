// 对图的操作，尽量把图设为全局变量
#include <iostream>
#include <map>
#define max 2010
using namespace std;
map<string, int> ToInt;
map<int, string> ToStr; //将编号映射为名字
map<string, int> result;
int weight[max];
int id = 1;
bool visit[max];
int G[max][max];
int convert(string S) //将字母变成数字
{

    if (ToInt[S] == 0)
    { //原来的map这个值为空
        ToInt[S] = id;
        ToStr[id] = S;
        return id++;
    }
    else
    {
        return ToInt[S];
    }
}
void dfsvisit(int G[][max], int v, int &Tnumber, int &currentweight, int &gang)
{
    int i;
    visit[v] = true;
    Tnumber++;                    //这个团伙人数+1;
    if (weight[v] > weight[gang]) //找到权值最大的头目
    {
        gang = v;
    }
    for (i = 1; i < id; i++)
    {
        if (G[v][i] != 0)
        {
            currentweight += G[v][i];
            G[v][i] = G[i][v] = 0; //遍历过就把这个边变为0，防止死循环
            if (visit[i] == false)
            {
                dfsvisit(G, i, Tnumber, currentweight, gang);
            }
        }
    }
}
void dfs(int G[][max], int K)
{
    int Tnumber, i, totalWeight, gang;
    for (i = 1; i < id; i++)
    {
        if (visit[i] == false)
        {
            gang = i, Tnumber = 0, totalWeight = 0;
            dfsvisit(G, i, Tnumber, totalWeight, gang);
            if (Tnumber > 2 && totalWeight > K) //大于阈值，且人数大于等于3个,放入结果ma'p中
            {
                result[ToStr[gang]] = Tnumber;
            }
        }
    }
}
int main()
{
    int N, K, i, w, id1, id2;
    string v1, v2;
    cin >> N >> K; //K为阈值
    for (i = 0; i < N; i++)
    {
        cin >> v1 >> v2 >> w;
        id1 = convert(v1);
        id2 = convert(v2);
        G[id1][id2] += w; //可以a-b，也可以b-a
        G[id2][id1] += w;
        weight[id1] += w;
        weight[id2] += w;
    }
    dfs(G, K);
    cout << result.size() << endl;
    if (result.size() != 0)
        for (auto it = result.begin(); it != result.end(); it++)
        {
            cout << it->first << " " << it->second << endl;
        }
    return 0;
}