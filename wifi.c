#include <stdio.h>
int answer(char A, char B, char C, char D)
{

    if (A == 'T')
        return 1;
    if (B == 'T')
        return 2;
    if (C == 'T')
        return 3;
    if (D == 'T')
        return 4;
}
void password(int key)
{
    printf("%d", key);
}
int main(void)
{
    int N, i, number[10000];
    char A, B, C, D;
    scanf("%d", &N); //题目的个数
    getchar();       //吸收空格符号
    for (i = 0; i < N; i++)
    {
        scanf("A=%c B=%c C=%c D=%c", &A, &B, &C, &D);
        number[i] = answer(A, B, C, D);
    }
    for (i = 0; i < N; i++)
        password(number[i]);
    return 0;
}