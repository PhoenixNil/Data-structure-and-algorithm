#include <stdio.h>
#define MaxTree 10
#define Null -1
#define ElementType char
#define Tree int

struct TreeNode
{
    ElementType Element;
    Tree left;
    Tree right;
} T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
    int N, j;
    scanf("%d\n", &N);
    int ROOT = Null;
    if (N)
    {
        int i;
        char cl, cr;
        int check[N];
        for (i = 0; i < N; i++)
            check[i] = 0;
        for (i = 0; i < N; i++)
        {
            scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
            if (cl != '-')
            {
                T[i].left = cl - '0';
                check[T[i].left] = 1;
            }
            else
                cl = Null;

            if (cr != '-')
            {
                T[i].right = cr - '0';
                check[T[i].right] = 1;
            }
            else
                cr = Null;
        }

        for (j = 0; j < N; j++)
        {
            if (check[j] == 0)
            {
                ROOT = j;
                break;
            }
        }
        return ROOT;
    }
}

Tree Isomerphic(Tree R1, Tree R2)
{
    if (R1 == Null && R2 == Null)
        return 1;
    if ((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null))
        return 0;
    if (T1[R1].Element != T2[R2].Element)
        return 0;
    if ((T1[R1].Element == T2[R2].Element) &&
        (T1[T1[R1].left].Element == T2[T2[R2].left].Element))
        return Isomerphic(T1[R1].left, T2[R2].right);
    if ((T1[R1].Element == T2[R2].Element) &&
        (T1[T1[R1].left].Element == T2[T2[R2].right].Element))
        return Isomerphic(T1[R1].left, T2[R2].right);
    if ((T1[R1].Element == T2[R2].Element) &&
        (T1[T1[R1].right].Element == T2[T2[R2].left].Element))
        return Isomerphic(T1[R1].right, T2[R2].left);
    if ((T1[R1].Element == T2[R2].Element) &&
        (T1[T1[R1].right].Element == T2[T2[R2].right].Element))
        return Isomerphic(T1[R1].right, T2[R2].right);
}
int main()
{
    int R1 = BuildTree(T1);

    int R2 = BuildTree(T2);

    if (Isomerphic(R1, R2))
        printf("YES");
    else
        printf("No");
    return 0;
}