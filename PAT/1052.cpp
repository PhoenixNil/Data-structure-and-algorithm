#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define max 100010
using namespace std;
struct linklist
{
    int value;
    int address;
    int Next;
} number[100000];
vector<struct linklist> result;
int comp(struct linklist a, struct linklist b)
{
    return a.value < b.value;
}
int main()
{
    int N, i, tempaddress, count = 0;
    int headnode;
    cin >> N >> headnode; //可以变next,但是address不能变，前面的NEXT要是后面的address
    for (i = 0; i < N; i++)
    {
        cin >> tempaddress >> number[tempaddress].value >> number[tempaddress].Next;
        number[tempaddress].address = tempaddress;
    }
    for (i = headnode; i != -1; i = number[i].Next)
    {
        result.push_back(number[i]);
        count++;
    }
    if (count == 0)
    {
        cout << 0 << " " << -1;
    }
    else
    {
        sort(result.begin(), result.end(), comp);
        cout << result.size() << " " ;
        printf("%05d\n", result.begin()->address);
        for (auto K = result.begin(); K != result.end(); K++)
        {
            if (K != result.end() - 1)
            {
                K->Next = (K + 1)->address;
                printf("%05d %d %05d\n", K->address, K->value, K->Next);
            }
            else
                printf("%05d %d %d\n", K->address, K->value, -1);
        }
    }
    return 0;
}