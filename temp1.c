#include <stdio.h>
#define Null -1
#define MaxTree 10
struct TreeNode
{
    char Element;
    int left;
    int right;
} T1[MaxTree], T2[MaxTree];
int construction(struct TreeNode T[]) //构造树
{
    int N, Root, z, i, store[10];
    char cl, cr;
    printf("请输入数据");
    scanf(" %d\n", &N);
    for (i = 0; i < N; i++)
        store[i] = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
        if (cl != '-')
        {
            T[i].left = cl - '0';
            z = T[i].left;
            store[z] = 1;
        }
        else
            T[i].left = Null;
        if (cr != '-')
        {
            T[i].right = cr - '0';
            z = T[i].right;
            store[z] = 1;
        }
        else
            T[i].right = Null;
    }
    for (i = 0; i < N; i++)
        if (!store[i])
            break;
    Root = i;
    return Root;
}
int CompareTree(int R1, int R2)
{
    if (R1 == Null && R2 == Null)
        return 1;
    if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
        return 0;
    if (T1[R1].Element != T2[R2].Element)
        return 0;
    if ((T1[R1].left == Null) && (T2[R2].left == Null))
        return CompareTree(T1[R1].right, T2[R2].right);
    if ((T1[R1].left != Null) && (T2[R2].left != Null) &&
        ((T1[T1[R1].left].Element) == (T2[T2[R2].left].Element)))
        return (CompareTree(T1[R1].left, T2[R1].left) &&
                CompareTree(T1[R1].right, T2[R2].right));
    else
        return (CompareTree(T1[R1].left, T2[R1].right) &&
                CompareTree(T1[R1].right, T2[R2].left));
}
int main()
{
    int shu1, shu2;
    shu1 = construction(T1); //构造树,并且是根!
    shu2 = construction(T2);
    if (CompareTree(shu1, shu2)) //比较树
        printf("Yes\n");
    else
        printf("NO\n");
    return 0;
}