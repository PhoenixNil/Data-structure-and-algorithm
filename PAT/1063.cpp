#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<set<int>> numbers(55);
set<int> S;
double comp(int a, int b)
{
    int nc = numbers[b].size(), nt = 0;
    double result;
    for (auto it = numbers[a].begin(); it != numbers[a].end(); it++)
    {
        if (numbers[b].find(*it) == numbers[b].end()) //如果在B中没有发现A中元素，nc++
        {
            nc++;
        }
    }
    nt = numbers[a].size() + numbers[b].size() - nc;
    result = (double)nt / nc * 100;
    return result;
}
int main()
{
    int N, M, K, i, j, a;
    double result;
    int temp1, temp2;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> M;
        for (j = 0; j < M; j++)
        {
            cin >> a;
            numbers[i].insert(a);
        }
    }
    cin >> K;
    for (i = 0; i < K; i++)
    {
        cin >> temp1 >> temp2;
        result = comp(temp1 - 1, temp2 - 1);
        printf("%.1f%\n", result);
    }
    return 0;
}