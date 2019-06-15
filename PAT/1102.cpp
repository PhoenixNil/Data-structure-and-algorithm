#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct node
{
	int index, level, left, right, number;
} A[100];
vector<node> v1, v2;
//反转二叉树就是存储的时候所有左右结点都交换
void push(int root, int index, int level) //先右后左
{
	if (A[root].right != -1)
		push(A[root].right, 2 * index + 1, level + 1);
	node temp2;
	temp2.index = root;
	temp2.level = level;
	temp2.number = index; //原来的左边的number要比右边的number大
	v1.push_back(temp2);
	if (A[root].left != -1)
		push(A[root].left, 2 * index + 2, level + 1);
}

int cmp(node a, node b)
{
	if (a.level != b.level)
		return a.level < b.level; //升序
	return a.number < b.number;   //同一层，排序根据number
}
int main()
{
	int N, i, childen[100] = {0};
	int root = 0;
	//从0-N-1节点的序号
	//每一行给左节点和右节点
	cin >> N;
	for (i = 0; i < N; i++)
	{
		string l, r;
		A[i].index = i;
		cin >> l >> r;
		if (l != "-")
		{
			childen[stoi(l)] = 1; //childens数组存放的使所有的子节点
			A[i].left = stoi(l);
		}
		else
			A[i].left = -1;
		if (r != "-")
		{
			childen[stoi(r)] = 1;
			A[i].right = stoi(r);
		}
		else
			A[i].right = -1;
	}
	while (childen[root] == 1)
		root++; //找到根节点
	push(root, 0, 0);
	vector<node> v2(v1);
	sort(v2.begin(), v2.end(), cmp);
	for (i = 0; i < v2.size(); i++) //层序
	{
		if (i == 0)
			cout << v2[i].index;
		else
			cout << " " << v2[i].index;
	}
	cout << endl;
	for (i = 0; i < v1.size(); i++) //中序
	{
		if (i == 0)
			cout << v1[i].index;
		else
			cout << " " << v1[i].index;
	}

	return 0;
}