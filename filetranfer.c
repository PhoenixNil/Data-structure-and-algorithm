#include <stdio.h>
#define MaxSize 100001
typedef int ElementType;
typedef int SetName; //用根节点的下标为集合名称
typedef ElementType SetType[MaxSize];
SetType S;

void Union(SetName Root1, SetName Root2) //按秩归并，应该把矮树贴到高树上面！
{
    if (S[Root1] < S[Root2]) //即Root2是个高树，要把矮树Root2贴到高树上面去
        S[Root2] = Root1;
    else if (S[Root1] > S[Root2]) //即Root1是个高树，要把矮树Root1贴到高树上
        S[Root1] = Root2;
    else
    {
        S[Root1] = Root2;
        S[Root2]--;
    }
}
SetName Find(ElementType X) //路径压缩
{
    if (S[X] < 0) //找到了根，根才小于零
        return X;
    else
        return S[X] = Find(S[X]); //先用递归找到根节点，然后把根节点作为每个子节点的根节点了
}
void Input_connection()
{
    ElementType u, v;
    SetName Root1, Root2;
    scanf("%d %d\n", &u, &v);
    Root1 = Find(u - 1);
    Root2 = Find(v - 1);
    if (Root1 != Root2)
        Union(Root1, Root2);
}
void Check_connection()
{
    ElementType u, v;
    SetName Root1, Root2;
    scanf("%d %d", &u, &v);
    Root1 = Find(u - 1);
    Root2 = Find(v - 1);
    if (Root1 == Root2)
        printf("yes\n");
    else
        printf("no\n");
}
void Check_network(int n)
{
    int i, counter = 0;
    for (i = 0; i < n; i++) //数有多少个根节点
        if (S[i] < 0)
            counter++;
    if (counter == 1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n", counter);
}
int main()
{
    int n, i;
    char in;
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
        S[i] = -1;
    do
    {
        scanf("%c", &in);
        switch (in)
        {
        case 'I':
            Input_connection();
            break; //输入一条网络
        case 'C':
            Check_connection();
            break; //查询是否连通
        case 'S':
            Check_network(n);
            break; //输入结束，判断整个连通集合
        }
    } while (in != 'S');
    return 0;
}