#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXD 5    //用电话号码的最后五位来计算哈希函数
#define length 11 //电话号码长度
#define MAXTABLESIZE 100000
typedef char ElementType[length + 1];
typedef struct LNode *PtrToLNode;
struct LNode //链表的表示（哈希表中每个里面都是一个链表）
{
    ElementType Data;
    PtrToLNode Next;
    int Count;
};
typedef PtrToLNode Position;
typedef struct TblNode *HashTable;
struct TblNode //散列表数据结构
{
    int TableSize;
    PtrToLNode heads; //指向每个key对应的值里面的列表的头节点
};
Position Find(HashTable H, ElementType Key)     //线性探测
{
    Position P;
    int Pos;
    Pos = Hash(atoi(Key + length - MAXD), H->TableSize); //atoi函数能够将字符串类型化成int类型
    P = H->heads[Pos].Next;                              //从该链表的第一个结点开始
    //未到表尾意味没有找到
    while (P && strcmp(P->Data, Key))
        P = P->Next;
    return P; //找到了，或者是NULL
}
bool Insert(HashTable H, ElementType Key)
{
    Position P, NewCell;
    int Pos;
    P = Find(H, Key); /* 先检查Key是否已经存在 */
    if (!P)           //关键词没找到，插入
    {
        NewCell = (Position)malloc(sizeof(struct LNode));
        strcpy(NewCell->Data, Key);
        NewCell->Count = 1;
        Pos = Hash(atoi(Key + length - MAXD), H->TableSize); //哈希函数确定位置
        NewCell->Next = H->heads[Pos].Next;                  /*将新的电话号码（也就是Newcell）
        插入H->Head[Pos]链表的第一个节点*/
        H->heads[Pos].Next = NewCell;
        return true;
    }
    else
    {
        P->Count++; //狂人人数增加
        return false;
    }
}
int Hash(int number, int P) //除留余数法,P是大于2N的一个素数，余数就是最后一位*/
{
    return number % P;
}
HashTable CreateTable(int TableSize) //创建哈希表
{
    HashTable H;
    int i;
    H = (HashTable)malloc(sizeof(struct TblNode));
    H->TableSize = NextPrime(TableSize);    //  确定哈希表规模
    H->heads = (PtrToLNode)malloc(H->TableSize * sizeof(struct LNode)); //分配链表头节点数组
    for (i = 0; i < H->TableSize; i++)
    {
        H->heads[i].Data[0] = '\0';
        H->heads[i].Next = NULL;
        H->heads[i].Count = 0;
    }
    return H;
} //分离链接法
int NextPrime(int N)                    //确定散列表的规模
{                                       /* 返回大于N且不超过MAXTABLESIZE的最小素数 */
    int i, p = (N % 2) ? N + 2 : N + 1; /*从大于N的下一个奇数开始 */
    while (p <= MAXTABLESIZE)
    {
        for (i = (int)sqrt(p); i > 2; i--)
            if (!(p % i))
                break; /* p不是素数 */
        if (i == 2)
            break; /* for正常结束，说明p是素数 */
        else
            p += 2; /* 否则试探下一个奇数 */
    }
    return p;
}
void MAXman(HashTable H)
{
    int i, peoplenumber = 0, max = 0; // 狂人中最小号码
    ElementType minphone;
    PtrToLNode Ptr;
    minphone[0] = '\0';
    for (i = 0; i < H->TableSize; i++) //扫描每一个链表
    {
        Ptr = H->heads[i].Next; //哈希表里每个key对应的值的头节点的next域
        while (Ptr)
        {
            if (Ptr->Count > max) //更新最大通话次数
            {
                max = Ptr->Count;
                strcpy(minphone, Ptr->Data); //将ptr存储的号码复制到minphone中
                peoplenumber = 1;
            }
            else if (Ptr->Count == max)
            {
                peoplenumber++;
                if (strcmp(minphone, Ptr->Data) > 0)
                    strcpy(minphone, Ptr->Data); //更新狂人的最小手机号
            }
            Ptr = Ptr->Next; //遍历链表
        }
    }
    printf("%s %d", minphone, max);
    if (peoplenumber > 1)
        printf(" %d", peoplenumber);
    printf("\n");
}
void DestroyTable(HashTable H)
{
    int i;
    Position P, Tmp;
    /* 释放每个链表的结点 */
    for (i = 0; i < H->TableSize; i++)
    {
        P = H->heads[i].Next;
        while (P)
        {
            Tmp = P->Next;
            free(P);
            P = Tmp;
        }
    }
    free(H->heads); /* 释放头结点数组 */
    free(H);        /* 释放散列表结点 */
}
int main(void)
{
    int i, N;
    ElementType number;
    HashTable H;
    scanf("%d", &N);
    H = CreateTable(N * 2);
    for (i = 0; i < N; i++)
    {
        scanf("%s", number);
        Insert(H, number);
        scanf("%s", number);
        Insert(H, number);
    }
    MAXman(H);
    DestroyTable(H);
    return 0;
}