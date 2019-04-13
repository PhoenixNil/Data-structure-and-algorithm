#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<int, int> Behind;
map<int, int> index;
struct node
{
    int data, address, next;
};
node A[100005];
vector<node> B;
vector<node> C;
vector<node> D;
int count1[100005];
int main()
{
    int s, temp2;
    node temp;
    int N, i, temp3;
    scanf("%d %d", &s, &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d", &temp.address, &temp.data, &temp.next);
        Behind[temp.address] = temp.next;
        index[temp.address] = i; //记录当前address在A数组的位置
        A[i] = temp;
    }
    for (temp2 = s; temp2 != -1; temp2 = Behind[temp2])
    {
        B.push_back(A[index[temp2]]);
        temp3 = abs(B.back().data);
        count1[temp3]++;
        if (count1[temp3] > 1)
        {
            C.push_back(B.back());
        }
        else
            D.push_back(B.back());
    }
    //然后对这个Vecto执行删除操作,next节点要变
    for (i = 0; i < D.size(); i++)
    {
        if (i == D.size() - 1)
        {
            // cout << D[i].address << " " << D[i].data << " " << -1 << endl;
            printf("%05d %d -1\n", D[i].address, D[i].data);
        }
        else
            // cout << D[i].address << " " << D[i].data << " " << D[i + 1].address << endl;
            printf("%05d %d %05d\n", D[i].address, D[i].data, D[i + 1].address);
    }
    for (i = 0; i < C.size(); i++)
    {
        if (i == C.size() - 1)
        {
            printf("%05d %d -1\n", C[i].address, C[i].data);
        }
        else
            printf("%05d %d %05d\n", C[i].address, C[i].data, C[i + 1].address);
    }
    return 0;
}