// 题目理解难
#include <iostream>
#include <queue>
using namespace std;
int M, N, L, T;
int G[1300][130][130];
int result = 0;
bool visit[1300][130][80];
int dx[6] = { 1, -1, 0, 0, 0, 0 }, dy[6] = { 0, 0, 1, -1, 0, 0 }, dz[6] = { 0, 0, 0, 0, 1, -1 }; //用这三个数组表示坐标移动的方向
struct node
{
	int x;
	int y;
	int z;
};
bool judge(int x, int y, int z)
{

	if (x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < L && G[x][y][z] == 1 && visit[x][y][z] == false)
		return true;
	else
		return false;
}
int bfs(int x, int y, int z)
{
	queue<struct node> Z;
	int i;
	int cnt = 0;
	struct node A, B;
	A.x = x;
	A.y = y;
	A.z = z;
	Z.push(A);
	if (visit[x][y][z])
	{
		return 0;
	}
	while (!Z.empty())
	{
		B = Z.front();
		visit[B.x][B.y][B.z] = true;
		Z.pop();
		cnt++;
		for (i = 0; i < 6; i++) //遍历这个点的相邻节点
		{
			A.x = B.x + dx[i];
			A.y = B.y + dy[i];
			A.z = B.z + dz[i];
			if (judge(A.x, A.y, A.z)) //满足条件就入队，计算值是不是大于T
			{
				visit[A.x][A.y][A.z] = true;
				Z.push(A);
			}
		}
	}
	if (cnt >= T)
	{
		return cnt;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int i, j, k;

	cin >> M >> N >> L >> T;
	for (i = 0; i < L; i++)
	{
		for (j = 0; j < M; j++)
		{
			for (k = 0; k < N; k++)
			{
				cin >> G[j][k][i];		//这里要注意，是j,k,i
			}
		}
	}
	for (i = 0; i < L; i++)
	{
		for (j = 0; j < M; j++)
		{
			for (k = 0; k < N; k++)
			{
				if (G[j][k][i] == 1)
					result += bfs(j, k, i);	
			}
		}
	}
	cout << result;
	return 0;
}