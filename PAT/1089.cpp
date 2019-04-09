#include <algorithm>
#include <iostream>
using namespace std;
int A[105], B[105];
int main()
{
	int N, i, j, k;
	cin >> N;
	bool flag = false;
	for (i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	for (i = 0; i < N - 1; i++)
	{
		if (B[i] > B[i + 1]) //找到第一个比前面小的数
		{
			j = i;
			break;
		}
	}
	for (i = i + 1; i < N; i++)
	{
		if (A[i] != B[i])
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "Insertion Sort" << endl;
		sort(A, A + j + 2); //插入排序每次排序只会保证前i个有序,j是最后前面有序的最后一个属，而接下来插入排序会对前i+1个数排序，就是 j+2
		cout << A[0];
		for (i = 1; i < N; i++)
		{
			cout << ' ' << A[i];
		}
	}
	else
	{
		cout << "Merge Sort" << endl; //直接对A归并，然后比较A和B是否相同，因为归并是递归的，无法知道B的下一次
		flag = false;
		k = 1;
		while (!flag)
		{
			flag = true;
			for (i = 0; i < N; i++)
			{
				if (A[i] != B[i]) //对数组每次进行归并之后进行比较，如果不相等，则继续归并
				{
					flag = false;
				}
			}
			k = k * 2;
			for (i = 0; i < N / k; i++)
				sort(A + i * k, A + (i + 1) * k);
			sort(A + N / k * k, A + N);
		}
		cout << A[0];
		for (i = 1; i < N; i++)
		{
			cout << ' ' << A[i];
		}
	}
	return 0;
}