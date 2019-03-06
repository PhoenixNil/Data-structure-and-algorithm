#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
struct mooncake
{
    double inventory;
    double prices;
    double average;
};
int comp(struct mooncake X, struct mooncake Y)
{
    return X.average > Y.average;
}
struct mooncake A[1005];
int main()
{
    int N, D, i;
    float profit = 0.00;
    cin >> N >> D;
    for (i = 0; i < N; i++)
    {
        cin >> A[i].inventory;
    }
    for (i = 0; i < N; i++)
    {
        cin >> A[i].prices;
        A[i].average = A[i].prices / A[i].inventory;
    }
    //计算每一个的平均价格，然后用平均价格买东西
    sort(A, A + N, comp);
    for (i = 0; i < N && D > 0; i++)
    {
        if (D < A[i].inventory)
            profit += A[i].average * D;
        else
            profit += A[i].prices;
        D -= A[i].inventory;
    }
    printf("%.2f", profit);
    return 0;
}