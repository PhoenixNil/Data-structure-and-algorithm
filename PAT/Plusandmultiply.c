#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct PolyNode *Polynormial; //定义结构体变量
struct PolyNode
{
    float coef;       //多项式的系数
    int expon;        //多项式的指数
    Polynormial Next; //指针域
};
typedef Polynormial List;

void Free(List L)
{
    free(L);
}

List ReadPoly() //读取多项式，需要使用尾指针来创建链表
{
    int N, e, i;
    float c;
    List P, tail, temp;
    P = (List)malloc(sizeof(struct PolyNode)); //链表头空接点
    P->Next = NULL;
    tail = P; //尾指针
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d %f", &e, &c);
        List L = (List)malloc(sizeof(struct PolyNode)); //每次输入数据都需要空间
        L->coef = c;
        L->expon = e;
        L->Next = NULL;
        tail->Next = L;
        tail = L;
    }
    temp = P;
    P = P->Next;
    free(temp); //删除临时删除的节点
    return P;
}

List add(List R1, List R2)
{
    List head, R3, L1, L2;
    L1 = R1->Next;
    L2 = R2->Next;
    R3 = (List)malloc(sizeof(struct PolyNode));
    R3->Next = NULL;
    head = R3;
    while (L1 && L2)
    {
        if (L1->expon > L2->expon)
        {
            R3->Next = L1;
            R3 = R3->Next;
            L1 = L1->Next;
        }
        else if (L1->expon == L2->expon)
        {
            L1->coef = L1->coef + L2->coef;
            R3->Next = L1;
            R3 = R3->Next;
            L1 = L1->Next;
            L2 = L2->Next;
        }
        else
        {
            R3->Next = L2;
            R3 = R3->Next;
            L2 = L2->Next;
        }
    }
    while (L1)
    {
        R3->Next = L1;
        R3 = R3->Next;
        L1 = L1->Next;
    }
    while (L2)
    {
        R3->Next = L2;
        R3 = R3->Next;
        L2 = L2->Next;
    }
    R1 = NULL;
    R2 = NULL;
    return head;
}

List mult(List T1, List T2) //先相乘，建链表，然后再排序，排序后再删除
{
    List R3, head, R1, R2, tail, result = NULL;
    result = (List)malloc(sizeof(struct PolyNode));
    result->Next = NULL;

    for (R1 = T1; R1 != NULL; R1 = R1->Next)
    {
        head = (List)malloc(sizeof(struct PolyNode));
        head->Next = NULL;
        tail = head; //开始时，尾指针=头指针
        for (R2 = T2; R2 != NULL; R2 = R2->Next)
        {
            R3 = (List)malloc(sizeof(struct PolyNode)); //申请内存空间
            R3->expon = R1->expon + R2->expon;
            R3->coef = R1->coef * R2->coef;
            R3->Next = NULL;
            tail->Next = R3; //将R3插入到链表末尾
            tail = R3;       //每插入一个数据，将尾指针向后移
        }
        result = add(result, head);
        // 可以通过加来进行排序
    }
    return result;
}

void PrintPoly(List f1) //打印链表
{
    int flag = 0, count = -1;
    List t1 = f1;
    if (!f1)
    {
        printf("0 0\n");
        return;
    }
    while (t1)
    {
      count = count + 1;
      t1 = t1->Next;
    }
    printf("%d", count);
    while (f1)
    {
        if (!flag)
            flag = 1;
        else
        {
            printf(" ");
            printf("%d %.1f", f1->expon, f1->coef);
        }
        f1 = f1->Next;
    }
}

int main() //需要定义mult函数、ReadPolu函数、PrintfPoly函数、add函数
{
    List P1, P2, PP, PS;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PS = mult(P1, P2); //P1和P2的乘
    // PP = add(P1, P2); //P1和P2的加
    PrintPoly(PS);
    // PrintPoly(PP);
    Free(PS);
    return 0;
}