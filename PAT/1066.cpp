#include <iostream>
using namespace std;
typedef struct TreeNode *AVLTree;
struct TreeNode
{
    int data;
    AVLTree lchild, rchild;
};
int getheight(AVLTree A)
{
    if (A == NULL)
        return 0;
    else
        return max(getheight(A->lchild), getheight(A->rchild)) + 1;
}
AVLTree leftleft(AVLTree A)
{
    AVLTree B = A->rchild;
    A->rchild = B->lchild;
    B->lchild = A;
    return B;
}

AVLTree rightright(AVLTree A)
{
    AVLTree B = A->lchild;
    A->lchild = B->rchild;
    B->rchild = A;
    return B;
}
AVLTree rightleft(AVLTree A)
{
    A->rchild = rightright(A->rchild);
    return leftleft(A);
}
AVLTree leftright(AVLTree A)
{
    A->lchild = leftleft(A->lchild);
    return rightright(A);
}
AVLTree insert(AVLTree A, int node)
{
    if (A == NULL)
    {
        A = new TreeNode();
        A->data = node;
        A->lchild = A->rchild = NULL;
    }
    else if (node < A->data)
    {
        A->lchild = insert(A->lchild, node);
        if (getheight(A->lchild) - getheight(A->rchild) > 1)
        {
            if (node < A->lchild->data)
                A = rightright(A);
            else
                A = leftright(A);
        }
    }
    else
    {
        A->rchild = insert(A->rchild, node);
        if (getheight(A->lchild) - getheight(A->rchild) < -1)
        {
            if (node > A->rchild->data)
            {
                A = leftleft(A);
            }
            else
                A = rightleft(A);
        }
    }
    return A;
}
int main()
{
    int N, i, x;
    AVLTree T = NULL;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> x;
        T = insert(T, x);
    }
    cout << T->data;
    return 0;
}