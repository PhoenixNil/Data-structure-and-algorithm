#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *AVLTree;
struct TreeNode
{
    int data;
    AVLTree lchild, rchild;
    int height;
};
//定义AVL树的结构
int Height(AVLTree T)
{
    if (T == NULL)
        return 0;
    else
        return T->height;
}
//计算平衡因子需要树的高度
int max(int a, int b)
{
    return a > b ? a : b;
}
//A和B中子树最大的
AVLTree leftleft(AVLTree A)
{
    AVLTree B = A->lchild;
    A->lchild = B->rchild;
    B->rchild = A;
    A->height = max(Height(A->lchild), Height(A->rchild)) + 1;
    B->height = max(Height(B->lchild), A->height) + 1;
    return B;
}
//左左旋转
AVLTree rightright(AVLTree A)
{
    AVLTree B = A->rchild;
    A->rchild = B->lchild;
    B->lchild = A;
    A->height = max(Height(A->lchild), Height(A->rchild)) + 1;
    B->height = max(Height(B->rchild), A->height) + 1;
    return B;
}
//右右旋转
AVLTree leftright(AVLTree A)
{
    AVLTree B = A->lchild;
    AVLTree C = B->rchild;
    A->lchild = rightright(A->lchild);
    return leftleft(A);
}
//左右旋转
AVLTree rightleft(AVLTree A)
{
    AVLTree B = A->rchild;
    AVLTree C = B->lchild;
    A->rchild = leftleft(A->rchild);
    return rightright(A);
}
//右左旋转
AVLTree Insert(int DATA, AVLTree T)
{
    if (!T)
    {
        T = (AVLTree)malloc(sizeof(struct TreeNode));
        T->data = DATA;
        T->lchild = T->rchild = NULL;
        T->height = 0;
    }
    else if (DATA < T->data)
    {
        T->lchild = Insert(DATA, T->lchild);
        if (Height(T->lchild) - Height(T->rchild) == 2) //需要旋转
        {
            if (DATA < T->lchild->data) //数据大于左子树的数据
                T = leftleft(T);
            else
                T = leftright(T);
        }
    }
    else if (DATA > T->data)
    {
        T->rchild = Insert(DATA, T->rchild);
        if (Height(T->lchild) - Height(T->rchild) == -2) //需要旋转
        {
            if (DATA > T->rchild->data)
                T = rightright(T);
            else
                T = rightleft(T);
        }
    }
    T->height = max(Height(T->lchild), Height(T->rchild)) + 1;
    return T;
}
//插入
AVLTree AVLCreate(int N)
{
    int DATA, i;
    AVLTree T;
    scanf("%d", &DATA);
    T = (AVLTree)malloc(sizeof(struct TreeNode));
    T->data = DATA;
    T->lchild = T->rchild = NULL;
    T->height = 0;

    for (i = 1; i < N; i++)
    {
        scanf("%d", &DATA);
        T = Insert(DATA, T);
    }
    return T;
}
//创建AVL树
void PrintRoot(AVLTree T)
{
    printf("%d", T->data);
}
void Free(AVLTree T)
{
    if (T->lchild)
        Free(T->lchild);
    if (T->rchild)
        Free(T->rchild);
    free(T);
}
int main()
{
    int N;
    AVLTree T;
    scanf("%d", &N);
    T = AVLCreate(N);
    PrintRoot(T);
    Free(T);
    return 0;
}