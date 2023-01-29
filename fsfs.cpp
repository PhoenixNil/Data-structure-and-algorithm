#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
vector<int> result;
int main()
{
    auto a = 1, n = 4, i = 0;
    for (i = 0; i < n; i++)
    {
        a += i;
    }

    int A;
    printf("Enter a number: ");
    scanf("%d", &A);
    cout << "Hello World";
    printf("%d%d", A, a);
    return 0;
}