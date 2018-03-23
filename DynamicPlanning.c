//需要定义一个矩阵，还有两个辅助表，都要是二维数组
#include <stdio.h>
#include <stdlib.h>
int m[1000][1000] = {0};
int s[10][10] = {0};
void PRINT_OPTIMAL_PARENS(int s[10][10], int i, int j) //打印最后的矩阵括号顺序,s[i][j]存的是最好的分割方案
{
    if (i == j)
        printf("A%d", i-1);
    else
    {
        printf("(");
        PRINT_OPTIMAL_PARENS(s, i, s[i][j]);
        PRINT_OPTIMAL_PARENS(s, s[i][j] + 1, j);
        //s[i,j]记录了K值
        printf(")");
    }
}
void MATRIX_CHAIN_MULTIPLY(int *p, int s[10][10], int i, int j, int length) //全过程
{
    int n = length;
    //m的二维数组是从[i]到[j]的代价，s的二维数组是从[i][j]的最有划分位置
    int l, k, q;
    for (i = 1; i <= n; i++)
        m[i][i] = 0;
    for (l = 2; l <= n; l++) //计算长度为l的最优代价和长度为l的最优划分位置
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = 100000;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q; //最优解所花代价
                    s[i][j] = k; //每个问题的最优解位置
                }
            }
        }
    PRINT_OPTIMAL_PARENS(s, i, j); //打印最后的矩阵括号顺序,s[i][j]存的是最好的分割方案
}
int main(void)
{
    int N, p[10000], i;
    scanf("%d\n", &N);
    for (i = 1; i <= N; i++)
        scanf("%d", &p[i]);
    MATRIX_CHAIN_MULTIPLY(p, s, 1, N, N);
}