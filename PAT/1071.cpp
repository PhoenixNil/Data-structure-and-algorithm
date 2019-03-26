#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> result;
int main()
{
    int K = 1;
    string s, t;
    getline(cin, s);
    for (auto &&i : s)
    {
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))
        {
            t.push_back(tolower(i));
        }
        else //遇到空格了,j记录已保存的字符串
        {
            if (!t.empty()) //t不为空才放入map里面记录
            {
                if (result[t] != 0)
                {
                    result[t]++;
                }
                else
                {
                    result[t] = K;
                }
                t.clear(); //清空
                K = 1;
            }
        }
    }
    if (t.length()) //如果最后一个i是字母或者数字，因为根本没有执行else(一直满足if的条件)那么他就没有加入map里面，所以最后再把它放入map里面
    {
        result[t]++;
    }

    auto max = result.begin();
    for (auto it = result.begin(); it != result.end(); it++) //找到值最大的
    {
        if (it->second > max->second)
        {
            max = it;
        }
    }
    cout << max->first << " " << max->second;
    return 0;
}