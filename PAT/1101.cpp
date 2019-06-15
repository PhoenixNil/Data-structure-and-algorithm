#include <iostream>
#include<algorithm>
using namespace std;
int A[100005];
int B[100005];
int cnt[100005];
int main()
//找到主元，满足前面的都比他小，后面的都比他大
{
	int N, i, max;
	int prvot = 0;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> A[i];
		B[i] = A[i];
	}
	sort(B, B + N);
	max = A[0];
	for (i = 0; i < N; i++)
	{
		if (A[i] > max)
			max = A[i];
		if (A[i] == B[i])		//如果排完序之后的这个数所在的位置就是原来数组所在的位置，并且比他前面所有元素都要大，那他就满足主元
		{
			//cnt[prvot++] = A[i];
			if (B[i] >= max)
			{
				max = B[i];
				cnt[prvot++] = B[i];
			}
		}
	}
	cout << prvot << endl;

	for (i = 0; i < prvot; i++)
	{
		if (i == 0)
			cout << cnt[i];

		else
			cout << " " << cnt[i];
	}
	cout << endl;
	return 0;
}