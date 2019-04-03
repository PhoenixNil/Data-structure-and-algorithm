#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<int, string> result;
map<int, string> bits;
vector<string> output;
vector<string> output2;
int main()
{
	int A;
	int j, i;
	string temp;
	bool Y, W, flag = false;
	result[0] = "ling";
	result[1] = "yi";
	result[2] = "er";
	result[3] = "san";
	result[4] = "si";
	result[5] = "wu";
	result[6] = "liu";
	result[7] = "qi";
	result[8] = "ba";
	result[9] = "jiu";
	bits[2] = "Shi";
	bits[3] = "Bai";
	bits[0] = "Qian";
	bits[4] = "Wan";
	bits[5] = "Yi";
	cin >> temp;
	int temp2[9], temp3;
	A = stoi(temp);
	if (A < 0)
	{
		cout << "Fu"
			 << " ";
		temp.erase(0, 1);
	}
	for (i = temp.length() - 1, j = 8; i >= 0; i--, j--) //此时最前面的就全是0了
	{
		temp2[j] = temp[i] - '0';
	}
	if (A == 0)
	{
		cout << result[0];
	}
	else
	{
		if (temp2[1] || temp2[2] || temp2[3] || temp2[4]) //可能万位都是0
		{
			W = true;
		}
		if (j < 0)
		{
			Y = true;
		}
		temp3 = j + 1;
		for (j = j + 1; j < 9; j++)
		{
			if (temp2[j] == 0)
			{
				flag = true;
			}
			else
			{
				if (j != temp3 && flag) //前面是连续的0，这一位不是0
				{
					output.push_back(result[0]);
				}
				output.push_back(result[temp2[j]]);
				if (j != 0 || j != 4 || j != 8)
				{
					output.push_back(bits[(9 - j) % 4]);
					flag = false;
				}
			}

			if (Y == true && j == 0)
			{
				output.push_back(bits[5]);
			}
			if (j == 4 && W == true)
			{
				output.push_back(bits[4]);
			}
		}
		for (auto it = output.begin(); it != output.end(); it++)
		{
			if (*it != "")
			{
				output2.push_back(*it);
			}
		}
		for (auto it = output2.begin(); it != output2.end(); it++)
		{
			if (it == output2.end() - 1)
			{
				cout << *it;
			}
			else
				cout << *it << " ";
		}
	}
	return 0;
}