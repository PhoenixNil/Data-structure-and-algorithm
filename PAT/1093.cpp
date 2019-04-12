#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int K[100005];
int L[100005];
int main()
{
	string s;
	int i, j, cnt = 0;
	int start = -1, finish = -1;
	long int result = 0, count = 0;
	cin >> s;
	if (s.find_first_of('P') != s.npos)
	{
		start = s.find_first_of('P');
	}
	if (s.find_last_of('T') != s.npos)
	{
		finish = s.find_last_of('T');
	}
	if (start == -1 || finish == -1)
	{
		cout << 0;
	}
	else
	{
		for (i = start, j = 0; i <= finish; i++)
		{
			if (s[i] == 'A')
			{
				K[j] = cnt;   //每个A钱前面的P
				L[j] = count; //每个A前面的T
				j++;
			}
			if (s[i] == 'P')
			{
				cnt++;
			}
			if (s[i] == 'T')
			{
				count++;
			}
		}
		for (i = 0; i < j; i++)
		{
			result += K[i] * (count - L[i]); //每个A前面的P乘以每个A后面的T就是结果
		}

		cout << result % 1000000007;
	}
	return 0;
}