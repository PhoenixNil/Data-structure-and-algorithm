#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define max 100005
using namespace std;
vector<int> coin;
map<int, int> result;
int main()
{
    int N, M, i, j, k;
    bool flag = false;
    int num[max];
    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        cin >> num[i];
        if (num[i] < M)
        {
            coin.push_back(num[i]);
        }
    }
    sort(coin.begin(), coin.end());
    for (i = 0; i < coin.size(); i++)
    {
        j = i + 1;
        k = coin.size() - 1;
        while (j <= k)
        {
            if (coin[i] + coin[(j + k) / 2] == M)
            {
                flag = true;
                result[coin[i]] = coin[(j + k) / 2];
                break;
            }
            if (coin[i] + coin[(j + k) / 2] < M)
                j = (j + k) / 2 + 1;
            if (coin[i] + coin[(j + k) / 2] > M)
                k = (j + k) / 2 - 1;
        }
        // if (coin[i] + coin[(j + k) / 2] == M)
        // {
        //     flag = true;
        //     result[i] = coin[(j + k) / 2];
        // }
    }
    if (flag == true)
    {
        auto it = result.begin();
        cout << it->first << " " << it->second;
    }
    else
    {
        cout << "No Solution";
    }
    return 0;
}