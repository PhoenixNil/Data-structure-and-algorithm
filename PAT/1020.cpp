#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> Inorder;
vector<int> Postorder;
typedef struct TreeNode *Tree;
struct TreeNode
{
    Tree lchild, rchild;
    int data;
};
queue<Tree> levelorder;
void CreateTree(Tree &tree, int start, int end, int root)
{
    int i;
    if (start > end)
        return;
    tree = new TreeNode;
    tree->data = Postorder[root];
    tree->rchild = tree->lchild = NULL;
    for (i = start; i < end; i++)
        if (Postorder[root] == Inorder[i])
            break;                                                //find root在中序里面的root位置即i,通过i来来确定左子树和右子树长度
    CreateTree(tree->lchild, start, i - 1, root - (end - i + 1)); /*左子树每次的end都会变化,每次减去右子树的长度也都会变化*/
    CreateTree(tree->rchild, i + 1, end, root - 1);               /*右子树每次的start都会变化*/
}

int main(int argc, char const *argv[])
{
    int N, i, temp;
    Tree binary_tree, Root;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> temp;
        Postorder.push_back(temp);
    }
    for (i = 0; i < N; i++)
    {
        cin >> temp;
        Inorder.push_back(temp);
    }
    CreateTree(binary_tree, 0, N - 1, N - 1);
    // 其实应该free的

    levelorder.push(binary_tree);
    i = 0;
    while (!levelorder.empty())
    {
        Root = levelorder.front();
        if (i == 0)
            printf("%d", Root->data);
        else
            printf(" %d", Root->data);
        levelorder.pop();
        if (Root->lchild)
            levelorder.push(Root->lchild);
        if (Root->rchild)
            levelorder.push(Root->rchild);
        i++;
    }
    return 0;
}