#include <math.h.>
#include <stdio.h>
#include <stdlib.h>
#define MAXTABLESIZE 10000
typedef int ElementType;
typedef struct LNode *HashTable;
/*在实际应用中，有的变量只有几种可能取值。如人的性别只有两种可能取值，
星期只有七种可能取值。在 C 语言中对这样取值比较特殊的变量可以定义为枚举类型。
所谓枚举是指将变量的值一一列举出来，变量只限于列举出来的值的范围内取值。 */
typedef enum { Legitimate,
               Empty,
               Deleted } EntryType;
/*开放定址法来解决冲突*/
typedef struct HashEntry status;
struct HashEntry
{
    ElementType Data;
    EntryType Info; //信息有3种形态
};
struct LNode
{
    int TableSize; //如果size不是素数，需要将size变成大于该数的最小素数
    status *set;   //存放数据的数组，数组元素可以是有数据，也可以是没有数据
};
int NextPrime(int M)
{
    int i, p = (M % 2) ? M : M + 1; /*从大于N的下一个奇数开始 */
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
HashTable CreateTable(int TableSize)
{
    int i;
    HashTable H;
    H = (HashTable)malloc(sizeof(struct LNode));
    H->TableSize = NextPrime(TableSize);
    H->set = (status *)malloc(H->TableSize * sizeof(status));
    for (i = 0; i < H->TableSize; i++)
        H->set[i].Info = Empty; //每个信息都是空的
    return H;
}
int Hashing(int key, int p)
{
    return key % p;
}
int Secondaryexploration(HashTable H, ElementType key) //平方探测
{
    int Position, NewPos, ConflictNum = 0;
    NewPos = Position = Hashing(key, H->TableSize); //初始化位置
    while (H->set[NewPos].Info != Empty && H->set[NewPos].Data != key)
    {

        if (++ConflictNum % 2) //基数次冲突
        {
            NewPos = Position + (ConflictNum + 1) * (ConflictNum + 1) / 4; /* 增量为+[(CNum+1)/2]^2 ,基数次是正的*/
            // if ( NewPos >= H->TableSize )
            //     NewPos = NewPos % H->TableSize; /* 调整为合法地址 */
        }
        if (NewPos > H->TableSize)
            break;
    }
    return NewPos;
}
void InsertAndPrint(ElementType Key, HashTable H)
{
    int Pos = Secondaryexploration(H, Key); /* 先检查Key是否已经存在 */
    if (Pos < H->TableSize)
    {
        H->set[Pos].Info = Legitimate;
        H->set[Pos].Data = Key;
        printf("%d ", Pos);
    }
    else
        printf("-");
}
void DestroyTable(HashTable H)
{
    free(H->set);
    free(H);
}

int main(void)
{
    int N, M, i;
    int number[MAXTABLESIZE];
    HashTable H;
    scanf("%d %d", &M, &N); //M是表的规模，也就是T-size，N是输入的个数
    H = CreateTable(M);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &number[i]);
    }
    for (i = 0; i < N; i++)
        InsertAndPrint(number[i], H);
    DestroyTable(H);
    return 0;
}