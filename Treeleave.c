#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BinTree;
BinTree construction()
{
    char cl,cr,ch;
    BinTree T;
    scanf("%c %c", &cl,&cr);
    if (ch != '-')
    {
        T = (BinTree)malloc(sizeof(BiTNode));
        (T)->data = ch;
        T->lchild = construction();
        T->rchild = construction();
    }
    else
        T = NULL;
    return T;
}
void Printleave(BinTree BT)
{
    if (BT)
    {
        if (!BT->lchild && !BT->rchild)
            printf("%d", BT->data);
        Printleave(BT->lchild);
        Printleave(BT->rchild);
    }
}

int main()
{
    BinTree T1;
    int N;
    scanf("%d\n", &N);
    T1 = construction();
    Printleave(T1);
    return 0;
}