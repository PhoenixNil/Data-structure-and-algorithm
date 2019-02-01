#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<struct account> result;
struct account
{
    string user;
    string password; //不超过10个字符
} accounts[1005];
int M;
bool modify(string &password)
{
    int i;
    bool flag = false;
    for (i = 0; i < password.length(); i++)
    {
        switch (password[i])
        {
        case '1':
            password[i] = '@';
            flag = true;
            break;
        case '0':
            password[i] = '%';
            flag = true;
            break;
        case 'l':
            password[i] = 'L';
            flag = true;
            break;
        case 'O':
            password[i] = 'o';
            flag = true;
            break;
        default:
            break;
        }
    }
    return flag;
}
int main(int argc, char const *argv[])
{
    int N, i;
    bool flag;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> accounts[i].user >> accounts[i].password;
        flag = modify(accounts[i].password);
        if (flag)
            result.push_back(accounts[i]);
    }
    if (result.empty())
    {
        if (N == 1)
            printf("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified", N);
    }
    else
    {
        cout << result.size() << endl;
        for (auto it = result.begin(); it != result.end(); it++)
            cout << it->user << ' ' << it->password << endl;
    }
    return 0;
}