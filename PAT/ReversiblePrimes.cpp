#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isPrime(int number)
{
    int i, K;
    if (number <= 1)
        return false;
    K = sqrt(number);
    for (i = 2; i <= K; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}
int main()
{
    vector<int> reverse;
    int N, D, remainer, diver, i, H;
    int result = 0;
    while (1)
    {
        cin >> N;
        if (N < 0)
            break;
        cin >> D;
        if (!isPrime(N))
            cout << "No" << endl;
        else
        {
            diver = N;
            reverse.clear();
            while (diver != 0)
            {
                remainer = diver % D;
                reverse.push_back(remainer);
                diver /= D;
            }
            for (i = reverse.size() - 1, H = 1, result = 0; i >= 0; i--)
            {
                result += H * reverse[i];
                H *= D;
            }
            if (isPrime(result))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}