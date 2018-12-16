//对给定的数字找到回文数
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> temp1;
vector<int> temp2;

string ADD(vector<int> A, vector<int> B)
{
    int i, j, carry = 0, temp;
    char K;
    string result;
    for (i = A.size() - 1, j = B.size() - 1; i > 0; i--, j--)
    {
        temp = A[i] + B[j] + carry;
        K = (temp % 10) + '0';
        result.insert(result.begin(), K);
        carry = temp / 10;
    }
    if (i == 0)
    {
        temp = (A.back() + B.back() + carry) / 10;
        K = ((A.back() + B.back() + carry) % 10) + '0';
        result.insert(result.begin(), K);

        if (temp > 0)
        {
            K = temp + '0';
            result.insert(result.begin(), K);
        }
    }

    result.reserve();
    return result;
}
bool huiwen(string result)
{
    int i, j;
    for (i = 0, j = result.size() - 1; i <= j; i++, j--)
        if (result[i] != result[j])
            return false;
    return true;
}
int main()
{
    string N, RN, result;
    int K, i;
    cin >> N >> K;
    if (huiwen(N))
    {
        i = 0;
        result = N;
    }
    else
    {
        for (i = 1; i < K + 1; i++) //对这个数+上他的回文数 ，是否能成为一个真正的回文数
        {
            reverse_copy(N.begin(), N.end(), back_insert_iterator(RN));
            temp1.clear();
            temp2.clear();
            for (auto &&j : N)
                temp1.push_back(j - '0');
            for (auto &&j : RN)
                temp2.push_back(j - '0');
            result = ADD(temp1, temp2);
            if (huiwen(result))
            {
                result = ADD(temp1, temp2);
                break;
            }
            else
            {
                N.clear();
                N = ADD(temp1, temp2);
            }
        }
        if (i > K)
        {
            result = ADD(temp1, temp2);
            i = K;
        }
    }
    cout << result << "\n";
    cout << i;
    return 0;
}