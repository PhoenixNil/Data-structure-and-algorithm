// 动态规划
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    int LCS[1005][1005];
    string A, B;
    int i, j, longest = 1;
    getline(cin, A);
    B = A;
    reverse(A.begin(), A.end());
    for (i = 0; i < A.length(); i++)
    {
        LCS[i][0] = (A[i] == B[0] ? 1 : 0);
    }
    for (j = 1; j < B.length(); j++)
    {
        LCS[0][j] = (B[j] == A[0] ? 1 : 0);
    }
    // 初始化dp二维数组
    for (i = 1; i < A.length(); i++)
    {
        for (j = 1; j < B.length(); j++)
        {
            if (A[i] == B[j])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1; //这个问题可以分解为前面的问题+1
                if (LCS[i][j] > longest)
                {
                    longest = LCS[i][j];
                }
            }
        }
    }
    cout << longest;
    return 0;
}
