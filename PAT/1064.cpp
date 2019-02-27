#include <algorithm>
#include <iostream>
using namespace std;
int A[1005];
int result[1005], index = 1;
void buildTree(int root, int N)
{
    if (root > N)
    {
        return;
    }
    buildTree(2 * root, N);     //建立左子树
    result[root] = A[index++];  //把这个元素放到位置之后，再找到下一个元素的位置，按照左根右的顺序，
    buildTree(2 * root + 1, N); //建立右子树
}

int main()
{
    int N, i;
    cin >> N;
    for (i = 1; i < N + 1; i++) //如果是0-N的话，那2*i永远等于0
    {
        cin >> A[i];
    }
    sort(A + 1, A + N + 1); //BST中序遍历是升序的
    buildTree(1, N);
    for (i = 1; i < N; i++)
    {
        cout << result[i] << " ";
    }
    cout << result[N];
    return 0;
}