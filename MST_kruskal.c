//克鲁斯卡尔算法
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct Gnode *PtrToGnode;
typedef int Vertex;
typedef int SetType[MAX]; //每个节点的集合,每个数值为该节点的祖先
int rank[MAX];
/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex u, v; /*起点,终点 */
    int Weight;  /* 权重 */
};
typedef PtrToENode Edge;
typedef struct ENode edge[MAX]; //边数组

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;        /* 邻接点下标 */
    int Weight;         /* 边权重 */
    PtrToAdjVNode Next; /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode
{
    PtrToAdjVNode FirstEdge; /* 边表头指针 */
} AdjList[MAX];              /* AdjList是邻接表类型，表示元素类型为结构体，个数为Max的结构体数组类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;    /* 顶点数 */
    int Ne;    /* 边数   */
    AdjList G; /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */
//邻接表定义完成

LGraph CreateGraph(int V, int E)
{
    LGraph Graph;
    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = V;
    Graph->Ne = E;
    for (V = 0; V <= Graph->Nv; V++)
        Graph->G[V].FirstEdge = NULL;
    return Graph;
}
/*并查集定义开始*/
void make_set(int S[], int X) //每个节点的祖先是他自己，规模都为0
{
    int i;
    for (i = 1; i <= X; i++)
    {
        S[i] = i; //
        rank[i] = 0;
    }
}
int Find_set(SetType S, int X) //路径压缩，找到根节点
{
    if (S[X] == X) //找到集合的根
        return X;
    else
        return S[X] = Find_set(S, S[X]); //路径压缩
}

void Link(SetType S, int x, int y) //按秩归并的将 x 和 y的祖先变成一个
{
    if (rank[x] > rank[y]) //使节点y指向节点x
        S[y] = x;
    else
    {
        if (rank[x] == rank[y]) //规模相等默认并入y
            rank[y]++;
        S[x] = y; //将节点x 指向节点y
    }
}
void Union(SetType S, int x, int y) //将边（x,y)A节点和B节点联合
{
    Link(S, Find_set(S, x), Find_set(S, y));
}
/*并查集定义结束*/

void Insert(LGraph Graph, Edge E) //在图中插入边,使用头插法这样可以不用遍历整个链表将u,v这条边插入以v为表头的链表
{
    PtrToAdjVNode NewNode;
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode)); //新的邻接表
    NewNode->Weight = E->Weight;
    NewNode->AdjV = E->v; //将v插入到u的表头
    NewNode->Next = Graph->G[E->u].FirstEdge;
    Graph->G[E->u].FirstEdge = NewNode;
}

void Init_Eset(edge Eset, LGraph Graph) //将所有的边插入边集中
{

    int i, ECount = 0;
    PtrToAdjVNode W;
    for (i = 1; i <= Graph->Nv; i++) //对每个节点
    {
        W = Graph->G[i].FirstEdge;
        while (W) //对每个节点的邻接表
        {
            if (i < W->AdjV)
            { /* 避免重复录入无向图的边，只收V1<V2的边 */
                Eset[ECount].u = i;
                Eset[ECount].v = W->AdjV;
                Eset[ECount].Weight = W->Weight;
                ECount++;
            }
            W = W->Next;
        }
    }
}

int comp(const void *a, const void *b)
{
    Edge P1 = (struct ENode *)a;
    Edge P2 = (struct ENode *)b;
    return P1->Weight - P2->Weight;
}

void kruskal(LGraph Graph)
{
    edge Eset;          //边数组，是一个结构体数组;
    SetType Vset = {0}; //顶点数组
    int totalcost = 0;  //总权重
    int V1 = 0, V2 = 0;
    LGraph MST;
    int Ecount = 0;
    MST = CreateGraph(Graph->Nv, 0);                    //只有顶点没有边的邻接表,通过并查集，将边插入
    make_set(Vset, Graph->Nv);                          //初始化顶点并查集
    Init_Eset(Eset, Graph);                             //将所有边存进去
    qsort(Eset, Graph->Ne, sizeof(struct ENode), comp); //对所有边进行排序
    for (Ecount = 0; Ecount <= Graph->Ne; Ecount++)     //遍历每条边
    {
        V1 = Find_set(Vset, Eset[Ecount].u); //找到u的祖先
        V2 = Find_set(Vset, Eset[Ecount].v); //找到V的祖先
        if (V1 != V2)                        //u和v不是同一个树，也即不能成环
        {
            Insert(MST, Eset + Ecount);       //在最小生成树中插入该条边
            Union(Vset, V1, V2);              //u,v合并
            totalcost += Eset[Ecount].Weight; //计算总权重
            //printf("%d %d", Eset[Ecount].u, Eset[Ecount].v); //打印生成树的每一条边
        }
        if (Ecount == Graph->Nv - 1) //只有满足V-1条边时，才满足最小生成树的定义
        {
            break;
        }
    }
    if (Ecount < Graph->Nv - 1)
    {
        totalcost = -1;
        printf("MST no exist"); //输入错误，不存在最小生成树
    }
    else
        printf("Total weight of minimum spanning trees %d", totalcost);
}

int main()
{
    int V, E, i;
    LGraph Graph;
    Edge init_Edge; //原始的边集
    printf("vertices edges :\n");
    scanf("%d %d\n", &V, &E);
    Graph = CreateGraph(V, E);
    init_Edge = (Edge)malloc(sizeof(struct ENode));
    for (i = 1; i <= Graph->Ne; i++)
    {
        scanf("%d %d %d", &init_Edge->u, &init_Edge->v, &init_Edge->Weight);
        Insert(Graph, init_Edge);
    } //建立原始图
    kruskal(Graph);
    return 0;
}