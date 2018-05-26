#include <stdio.h>
#include <stdlib.h>
int W[10][10], inf = 9999;
void init(int v)
{
    int i, j;
    for (i = 1; i <= v; i++)
        for (j = 1; j <= v; j++)
        {
            W[i][j] = inf;
            if (i == j)
                W[i][j] = 0;
        }
}

int main()
{
    int i, j, v, e, t1, t2, t3, k;
    scanf("%d %d\n", &v, &e); //读入顶点和边
    init(v);
    for (i = 1; i <= e; i++)
    {
        scanf("%d %d %d", &t1, &t2, &t3);
        W[t1][t2] = t3;
    }
    for (k = 1; k <= v; k++)
        for (i = 1; i <= v; i++)
            for (j = 1; j <= v; j++)
                if (W[i][j] > W[i][k] + W[k][j])
                    W[i][j] = W[i][k] + W[k][j];
    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
            printf("%10d ", W[i][j]);
        printf("\n");
    }

    return 0;
}