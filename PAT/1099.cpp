#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
//输出层序遍历的结果
//先建树，然后按照中序遍历的结果插入
//最后再BFS
using namespace std;
typedef struct node *tree;
vector<vector<int>> K;
int index;
int A[105];
queue<tree> temp2;
tree T;
struct node
{
	int data;
	tree lchild;
	tree rchild;
	int height;
};
tree Create(tree T, int data, int height)
{
	if (data == -1)
	{
		return NULL;
	}
	else
	{
		T = new struct node;
		T->data = data;
		T->height = height;
		T->lchild = Create(T->lchild, K[data][0], height + 1);
		T->rchild = Create(T->rchild, K[data][1], height + 1);
	}
	return T;
}
void inorder(tree T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		inorder(T->lchild);
		T->data = A[index++];
		inorder(T->rchild);
	}
}
void leveltravel(tree T)
{
	temp2.push(T);
	while (!temp2.empty())
	{
		tree temp3 = temp2.front();
		temp2.pop();
		if (temp3->height == 0)
		{
			cout << temp3->data;
		}
		else
		{
			cout << " " << temp3->data;
		}
		if (temp3->lchild)
		{
			temp2.push(temp3->lchild);
		}
		if (temp3->rchild)
		{
			temp2.push(temp3->rchild);
		}
	}
}

int main()
{
	int N, i, left_index, right_index;
	cin >> N;
	K.resize(N);
	for (i = 0; i < N; i++)
	{
		cin >> left_index >> right_index;
		K[i].push_back(left_index);
		K[i].push_back(right_index);
	}
	for (i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	sort(A, A + N);
	T = Create(T, 0, 0);
	inorder(T);
	leveltravel(T);
}