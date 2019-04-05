#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
vector<int>InOrder;
vector<int>PreOrder;
stack<int>sum;
vector<int>postorder;
void topostorder(int start, int end, int root)
{
	int i;
	if (start > end)
	{
		return;
	}
	for (i = start; i < end; i++)
	{
		if (InOrder[i] == PreOrder[root])
		{
			break;
		}
	}
	topostorder(start, i - 1, root + 1);
	topostorder(i + 1, end, root + i + 1 - start);		//右根=root+左子树长度,左子树长度为i-start，因为在前序中，
		//root也占一个位置，所以应该还要+1
	postorder.push_back(PreOrder[root]);				//左=root+1
}


int main()
{
	int N, i;
	string temp;
	int a, b;
	cin >> N;		//节点的数字从1-N
	for (i = 0; i < 2 * N; i++)		//入栈顺序是前序，出战顺序是中序
	{
		cin >> temp;
		if (temp == "Push")
		{
			cin >> a;
			PreOrder.push_back(a);
			sum.push(a);
		}
		if (temp == "Pop")
		{
			b = sum.top();
			InOrder.push_back(b);
			sum.pop();
		}
	}
	a = PreOrder.front();
	topostorder(0, N - 1, 0);
	cout << postorder[0];
	for (i = 1; i < N; i++)
	{
		cout << " " << postorder[i];
	}
	return 0;
}