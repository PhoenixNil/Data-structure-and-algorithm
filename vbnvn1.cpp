#include <iostream>
#include <stdlib.h>
using namespace std;

struct edge //边
{
    int u, v, w;
} edges[11];    //边的数组
int parent[12]; //parent[i]为顶点i所在集合对应的树中的根结点
int n, m;        //顶点个数、边的个数
int i, j;        //循环变量
void E_ufset()   //初始化
{
    for (i = 1; i <= n; i++)
        parent[i] = -1;
}
int E_find(int x) //查找并返回结点x所属集合的根结点
{
    int s; //查找位置
    for (s = x; parent[s] >= 0; s = parent[s])
        ;
    while (s != x) //优化方案——压缩路径，使后续的查找操作加速
    {
        int tmp = parent[x];
        parent[x] = s;
        x = tmp;
    }
    return s;
}
//运用并查集，将两个不同集合的元素进行合并，使两个集合中任意两个元素都连通
void E_union(int R1, int R2)
{
    int r1 = E_find(R1), r2 = E_find(R2); //r1和r2分别为R1和R2的根结点
    int tmp = parent[r1] + parent[r2];    //两个集合结点数之和（负数）
    //如果R2所在树结点个数 > R1所在树结点个数（注意parent[r1]是负数）
    if (parent[r1] > parent[r2])
    {
        parent[r1] = r2;
        parent[r2] = tmp;
    }
    else
    {
        parent[r2] = r1;
        parent[r1] = tmp;
    }
}
int E_cmp(const void *a, const void *b) //实现从小到大的比较函数
{
    edge aa = *(const edge *)a, bb = *(const edge *)b;
    return aa.w - bb.w;
}
void E_kruskal()
{
    int sumweight = 0; //生成树的权值
    int num = 0;       //已选用的边的数目
    E_ufset();         //初始化parent数组
    for (i = 0; i < m; i++)
    {
        if (E_find(edges[i].u) != E_find(edges[i].v))
        {
            cout << edges[i].u <<' '<< edges[i].v <<' '<< edges[i].w << endl;
            sumweight += edges[i].w;
            num++;
            E_union(edges[i].u, edges[i].v);
        }
        if (num >= n - 1)
            break;
    }
    cout<<sumweight<<endl;
}
int main()
{
    cin >> n >> m; //读入顶点个数和边数
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w; //读入边的起点和终点
    cout << "The edges chosen are :" << endl;
    qsort(edges, m, sizeof(edges[0]), E_cmp); //对边按权值从小到大排序
    E_kruskal();
}