#include <iostream>
#include<algorithm>
using namespace std;
#define max 100100
int main()
{
	int N, i, j, result = 0, temp = 0;
	long int p;
	long int A[max];
	cin >> N >> p;
	for (i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	for (i = 0; i < N; i++)
	{
		for (j = i + result; j < N; j++)
		{
			if (A[j] <= A[i] * p)
			{
				temp = j - i + 1;		//temp存放当前为i为最小元素的序列的元素最大个数
			}
			else    //A[j]大于p*m
			{
				break;
			}
			if (temp > result)
			{
				result = temp;
			}
		}
	}
	cout << result;
	return 0;
}