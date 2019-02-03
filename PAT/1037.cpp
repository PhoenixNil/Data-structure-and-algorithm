#include <algorithm>
#include <iostream>
using namespace std;
#define max 100000
int main()
{
    int NC, i, NP, j, money = 0, temp1, temp2;
    bool flag;
    int coupon[max], products[max];
    cin >> NC;
    for (i = 0; i < NC; i++)
    {
        cin >> coupon[i];
    }
    cin >> NP;
    for (i = 0; i < NP; i++)
    {
        cin >> products[i];
    }
    sort(coupon, coupon + NC);
    sort(products, products + NP);
    i = NC - 1;
    j = NP - 1;
    while ((i >= 0) && (j >= 0))
    {
        if (coupon[i] < 0 || products[j] < 0)
        {
            flag = true; //出现负的优惠或者负的产品价格
            temp1 = i;
            temp2 = j;
            break;
        }
        money += coupon[i] * products[j];
        j--;
        i--;
    }
    if (flag)
    {
        for (i = 0, j = 0; (i <= temp1) && (j <= temp2); i++, j++)
        {
            if (coupon[i] * products[j] < 0)
            {
                break;
            }
            money += coupon[i] * products[j];
        }
    }
    cout << money;
    return 0;
}