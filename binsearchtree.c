#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *Tree;
struct TreeNode
{
    int data;
    Tree lchild, rchild;
    int flag;
};

Tree NewNode(int DATA)
{
    Tree T = (Tree)malloc(sizeof(struct TreeNode));
    T->data = DATA;
    T->lchild = T->rchild = NULL;
    T->flag = 0;
    return T;
}

Tree InsertT(int DATA, Tree T)
{
    if (!T)
        T = NewNode(DATA); //当前节点是空的话
    else
    {
        if (DATA > T->data)
            T->rchild = InsertT(DATA, T->rchild);
        if (DATA < T->data)
            T->lchild = InsertT(DATA, T->lchild);
    }
    return T;
}
Tree BSTCreate(int N)
{
    int i, DATA;
    Tree T;
    scanf("%d", &DATA);
    T = NewNode(DATA);
    for (i = 1; i < N; i++)
    {
        scanf("%d", &DATA);
        T = InsertT(DATA, T);
    }
    return T;
}

int Check(Tree T, int DATA) //flag为1代表访问过了，为零就是还没访问
{
   if(T->flag)
   {
       if(DATA<T->data)
           return Check(T->lchild, DATA);
       else if(DATA>T->data)
           return Check(T->rchild, DATA);
        else 
            return 0;
   }
   else
   {
       if(DATA==T->data)
        {
            T->flag = 1;
            return 1;
        }
        else
            return 0;
   }
}

int Judge(Tree T, int N)
{
    int i, Flag = 0; /*0代表当前还一致，1代表不一致*/
    int DATA;
    scanf("%d", &DATA);
    if (T->data != DATA)
        Flag = 1;
    else
        T->flag = 1;
    for (i = 1; i < N; i++)
    {
        scanf("%d", &DATA);
        if ((!Flag) && (!Check(T, DATA)))
            Flag = 1;
    }
    if (Flag)
        return 0;
    else
        return 1;
}

void Free(Tree T)
{
    if (T->lchild)
        Free(T->lchild);
    if (T->rchild)
        Free(T->rchild);
    free(T);
}

void ResetT(Tree T)
{
    if (T->lchild)
        ResetT(T->lchild);
    if (T->rchild)
        ResetT(T->rchild);
    T->flag = 0;
}
int main()
{
    int N, L, i;
    Tree T;
    scanf("%d", &N);
    while (N) //需要一直输入序列
    {
        scanf("%d", &L); /*如果输入0那就不用输入L了*/
        T = BSTCreate(N);
        for (i = 0; i < L; i++)
        {
            if (Judge(T, N))
                printf("Yes\n");
            else
                printf("NO\n");
            ResetT(T);
        }
        Free(T);
        scanf("%d", &N); //判断完之后继续输入新一组的数据
    }
    return 0;
}