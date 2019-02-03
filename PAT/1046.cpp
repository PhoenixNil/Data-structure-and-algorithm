#include <iostream>
#include <vector>
using namespace std;
#define MAX 100010
vector<int> result;
int main()
{
    int N, M, i, j;
    int exit1, exit2, temp = 0, temp2;
    int d[MAX];
    cin >> N;
    for (i = 1; i < N + 1; i++)
    {
        cin >> d[i];
        temp += d[i];
    }
    cin >> M;
    for (j = 0; j < M; j++)
    {
        temp2 = 0;
        cin >> exit1 >> exit2;
        for (i = min(exit1, exit2); i < max(exit1, exit2); i++)
        {
            temp2 += d[i];
        }
        result.push_back(temp - temp2 > temp2 ? temp2 : temp - temp2);
    }
    for (auto it = result.begin(); it != result.end(); it++)
        cout << *it << endl;
    return 0;
}