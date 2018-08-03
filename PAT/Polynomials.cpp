#include <iostream>
#define MaxSize 21
using namespace std;
int main(int argc, char const *argv[])
{
    int i, j, n, m, k = 0, z;
    int S[MaxSize][3] = {{0}};   //A和B的多项式指数
    float C[MaxSize][3] = {{0}}; //A和B的多项式系数
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> S[i][0] >> C[i][0];
    }
    cin >> m;
    for (j = 0; j < m; j++)
    {
        cin >> S[j][1] >> C[j][1];
    }
    i = j = 0;
    for (i = 0; i < MaxSize && (C[i][0] != 0 || C[j][1] != 0); i++)
    {
        for (j = 0; j < MaxSize && (C[j][1] != 0 || C[i][0] != 0);)
        {
            if (S[i][0] < S[j][1]) //Ai的指数数比Bj的小,指数则为Bj，系数为Bj的系数
            {
                S[k][2] = S[j][1];
                C[k][2] = C[j][1];
                j++;
            }
            else if (S[i][0] == S[j][1]) //相等时，系数相加
            {
                C[k][2] = C[i][0] + C[j][1];
                S[k][2] = S[j][1];
                i++;
                j++;
            }
            else //Ai系数大于Bi系数
            {
                S[k][2] = S[i][0];
                C[k][2] = C[i][0];
                i++;
            }
            k++;
        }
    }
    z = k;
    for (i = 0; i < k; i++)
    {
        if (C[i][2] == 0)
            z--;
    }
    cout << z;
    for (i = 0; i < k; i++)
    {
        if (C[i][2] == 0)
            continue;
        cout << " " << S[i][2];
        cout.precision(1);
        cout << fixed << " " << C[i][2];
    }
    return 0;
}
//这道题要记住需要小数点后1位输出