#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef struct element
{
    int data;
    string next;
    string address;
} elements;
vector<struct element> result;
map<string, int> datas;
map<string, string> nexts;
int main()
{
    int N, K, i, Data;
    elements temp;
    string firstnode, Address, Next, index;
    cin >> firstnode >> N >> K;
    for (i = 0; i < N; i++)
    {
        cin >> Address >> Data >> Next;
        datas[Address] = Data;
        nexts[Address] = Next;
    }
    for (index = firstnode; index != "-1"; index = nexts[index])
    {
        temp.address = index;
        temp.data = datas[index];
        temp.next = nexts[index];
        result.push_back(temp);
    }
    for (i = 0; i + K <= result.size(); i += K) //反转之后的next要变
    {
        reverse(result.begin() + i, result.begin() + i + K);
    }
    for (auto it = result.begin(); it != result.end(); it++)
    {
        if (it == result.end() - 1)
        {
            it->next = "-1";
        }
        else
            it->next = (it + 1)->address;
        cout << it->address << " " << it->data << " " << it->next << endl;
    }
    return 0;
}