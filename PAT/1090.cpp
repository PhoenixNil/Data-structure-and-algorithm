#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> chain;
queue<int> temp2;
int depth[100005], people;
double P, r;
double result;
void BFS(int S)
{
	int i, temp3, temp4 = depth[S];
	temp2.push(S);
	while (!temp2.empty())
	{
		temp3 = temp2.front();
		temp2.pop();
		if (chain[temp3].empty())
		{
			if (depth[temp3] > temp4) //说明是子节点，并且深度比原来那个子节点要高，放入结果中
			{
				temp4 = depth[temp3];
				people = 1;
			}
			else if (depth[temp3] == temp4)
			{
				people++;
			}
			result = P * pow(1 + r / 100, depth[temp3]); //r是百分比
		}
		else
		{
			for (i = 0; i < chain[temp3].size(); i++)
			{
				temp2.push(chain[temp3][i]);
				depth[chain[temp3][i]] = depth[temp3] + 1;
			}
		}
	}
}
int main()
{
	int N, i, root = 0;
	int temp;
	cin >> N >> P >> r;
	chain.resize(N);
	for (i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp == -1)
		{
			root = i;
			continue;
		}
		chain[temp].push_back(i);
	}
	BFS(root);
	printf("%.2f %d", result, people);		//小数点后两位使用printf
	return 0;
}