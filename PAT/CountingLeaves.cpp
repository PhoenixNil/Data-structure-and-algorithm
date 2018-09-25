// BFS遍历每一层,找到叶子节点记录下来，需要一个记录层的信息，放在结构体中，所有子节点都放在一个vec中
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 101
// 输出叶节点
using namespace std;
struct TreeNode
{
    int childsum;
    vector<int> child;
    int layer;
} ID[MAX];
vector<int> result(MAX); //每层的叶节点存储在个vector
queue<int> temp;
int Travel(struct TreeNode ID[], int S)
{
    int u, layermax = 0;
    temp.push(S);
    result[0] = 0; //第一层的叶子节点为0
    ID[0].layer = 0;

    while (!temp.empty())
    {
        u = temp.front(); //出栈
        temp.pop();       //u  =dequeue()

        if (ID[u].child.empty())
        {
            result[ID[u].layer] += 1;
        }
        else
        {
            for (vector<int>::iterator j = ID[u].child.begin(); j != ID[u].child.end(); j++) //begin返回的是一个迭代器，j是一个指针
            {
                temp.push(*j); //入队
                ID[*j].layer = ID[u].layer + 1;
                layermax = max(layermax, ID[*j].layer); //获得最大层数
            }
        }
    }
    return layermax;
}

int main(int argc, char const *argv[])
{
    int N, M, i, j;
    int Data;
    int leave;
    int layermax;
    cin >> N >> M; //N节点数，M行，每行是一个非叶节点，然后是他的孩子数，然后再是他的孩子

    if (N == 0 || M == 0)
    {
        cout << 1;
    }

    for (i = 0; i < M; i++)
    {
        cin >> Data;
        cin >> ID[Data].childsum;

        for (j = 0; j < ID[Data].childsum; j++)
        {
            cin >> leave;
            ID[Data].child.push_back(leave);
        }
    }
    layermax = Travel(ID, 01);

    for (i = 0; i < layermax; i++)
    {
        cout << result[i] << ' ';
    }
    cout << result[i];
    return 0;
}