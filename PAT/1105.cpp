#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
//要让M和N尽量接近，m-n取最小值
int cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int N, i, j;
	int m = 0, n = 0;
	int level, t2 = 0;
	cin >> N;
	vector<int> A(N);
	for (i = 0; i < N; i++)
		cin >> A[i];
	float temp = sqrt(N);
	sort(A.begin(), A.end(), cmp);
	for (i = temp; i >= 1; i--)
	{
		n = i;
		if (N % i == 0)
		{
			m = N / i;
			break;
		}
	}
	//满足j+，i+,j-,i-,这个循环，下一次的这个循环每次迭代都少1
	//计算螺旋矩阵的层数level，如果m的值为偶数，层数为m / 2，如果m为奇数，层数为m / 2 + 1，所以level = m / 2 + m % 2；
	vector<vector<int>> result(m, vector<int>(n));
	level = n / 2 + n % 2;
	for (i = 0; i < level; i++)
	{
		for (j = i; j < n - i && t2 <= N - 1; j++) //j+
			result[i][j] = A[t2++];
		for (j = i + 1; j < m - 1 - i && t2 <= N - 1; j++) //i+
			result[j][n - 1 - i] = A[t2++];
		for (j = n - i - 1; j >= i && t2 <= N - 1; j--) //j
			result[m - 1 - i][j] = A[t2++];
		for (j = m - i - 2; j > i && t2 <= N - 1; j--) //i-
			result[j][i] = A[t2++];
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << result[i][j];
			if (j != n - 1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}