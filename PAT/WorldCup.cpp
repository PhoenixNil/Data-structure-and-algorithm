// 精确到两位小数
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int i;
    vector<float> bet;
    float win[3], tie[3], lose[3];
    float profit;
    cin >> win[0] >> tie[0] >> lose[0];
    profit = max(max(win[0], tie[0]), lose[0]);
    bet.push_back(max(max(win[0], tie[0]), lose[0]));
    for (i = 1; i < 3; i++)
    {
        cin >> win[i] >> tie[i] >> lose[i];
        profit *= max(max(win[i], tie[i]), lose[i]);
        bet.push_back(max(max(win[i], tie[i]), lose[i]));
    }
    profit = (profit * 0.65 - 1) * 2;
    for (i = 0; i < 3; i++)
    {

        if (bet[i] == win[i])
            cout << 'W'<<' ';
        else if (bet[i] == lose[i])
            cout << 'L'<<' ';
        else
            cout << 'T'<<' ';
    }
    printf("%.2f", profit);
    return 0;
}