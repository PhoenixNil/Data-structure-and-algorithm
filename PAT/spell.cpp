// 给出某数，然后计算个位之和，和也要分开计算，使用英文数字输出
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
map<char, int> Index;

string A[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main(int argc, char const *argv[])
{
    vector<string> part;
    int M = 0;
    int i;
    string Z;
    Index.insert(pair<char, int>('0', 0));
    Index['1'] = 1;
    Index['2'] = 2;
    Index['3'] = 3;
    Index['4'] = 4;
    Index['5'] = 5;
    Index['6'] = 6;
    Index['7'] = 7;
    Index['8'] = 8;
    Index['9'] = 9;

    vector<char> sum;
    string number;
    cin >> number;

    for (i = 0; i < number.length(); i++)
    {
        M += Index[number[i]];
    }
    Z = to_string(M);
    for (i = 0; i < Z.length(); i++)
    {
        part.push_back(A[Index[Z[i]]]);
    }
    for (i = 0; i < part.size() - 1; i++)
    {
        cout << part[i] << ' ';
    }
    cout << part[i];
    return 0;
}
