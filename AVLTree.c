#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode *AVLTree;
struct TreeNode
{
    int data;
    AVLTree lchild, rchild;
    int height;
};
//定义输的结构
int Height(AVLTree T)
{
    if(T==NULL)
        return 0;
    else
        return T->height;
}
//计算平衡因子需要树的高度
int max(int a, int b)
{
    return a>b?a:b;
}
//A和B中子树最大的
AVLTree leftleft(AVLTree A)
{
    AVLTree B = A->lchild;
    A->lchild = B->rchild;
    B->rchild = A;
    A->height = max(Height(A->rchild), Height(A->lchild)) + !;
    B->height = max(Height(A->lchild), A->height) + 1;
    return B;
}
//左左旋转
AVLTree rightright(AVLTree A)
{
    AVLTree B = A->rchild;
    A->rchild = B->lchild;
    B->lchild = A;
    A->height = max(Height(A->lchild), Height(A->rchild)) + !;
    B->height = max(Height(A->rchild), A->height) + 1;
    return B;
}
//右右旋转
AVLTree leftright(AVLTree A)
{
    AVLTree B = A->lchild;
    AVLTree C = B->rchild;
    C->lchild = rightright(C->lchild);
    return LeftLeft(C);
}
//左右旋转
AVLTree rightleft(AVLTree A)
{
    AVLTree B = A->rchild;
    AVLTree C = B->lchild;
    C->rchild = leftleft(C->rchild);
    return rightleft(C);
}
//右左旋转
AVLTree  AVLCreate(int N,Tree T)
{
    int DATA;
    scanf("%d", &DATA);
    {
        if(!T)
        {
        T = (AVLTree)makloc(sizeof(struct TreeNode));
        T->data = DATA;
        T->lchild = T->rchild = NULL;
        T->height = 0;
        }

    }
        
}
//创建AVL树
AVLTree Insert(int DATA,AVLTree T)
{
    if(DATA<T->data)
    {
        T->lchild = Insert(DATA, T->lchild);
        if((Height(T->lchild))-(Height(T->rchild)>=2))      //需要旋转
        {
            if(DATA<T->lchild->data)    数据大于左子树的数据
                LeftLeft(T);
            else 
                leftright(T);
        }
    }
    else(DATA>T->data)
    {
        T->rchild = Insert(DATA, T->rchild);
        if(Height(T->lchild)-Height(rchild)>=2)
        {
            if(DATA>T->rchild->data)
                rightleft(T);
            else
                rightleft(T;)
        }
    }
    T->height = MAX(Height(T->lchild), Height(T->rchild)) + 1;
    return T;
}
//插入
int main()
{
    int N;
    scanf("% d", &N);
    AVLCreate(N);
    PrintRoot();
    return 0;
}