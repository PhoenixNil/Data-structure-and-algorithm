#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#define max 10005
using namespace std;
string queries[max] = {};
struct Book
{
    string ID; //ID可能是012345这种类型的
    string title;
    string author;
    string keyword;
    string publisher;
    string year;
};
struct Book library[max];
vector<string> result;
void Find_book(int &number, string &query)
{
    int A = number, i;
    switch (A)
    {
    case 1:
        for (i = 0; i < max; i++)
        {
            if (query == library[i].title)
                result.push_back(library[i].ID);
        }
        if (result.empty())
        {
            cout << "Not Found\n";
            return;
        }
        sort(result.begin(), result.end());
        for (auto &&i : result)
            cout << i << endl;
        break;
    case 2:
        for (i = 0; i < max; i++)
        {
            if (query == library[i].author)
                result.push_back(library[i].ID);
        }
        if (result.empty())
        {
            cout << "Not Found\n";
            return;
        }
        sort(result.begin(), result.end());
        for (auto &&i : result)
            cout << i << endl;
        break;
    case 3:
        for (i = 0; i < max; i++)
        {
            if (library[i].keyword.find(query) != string ::npos)
                result.push_back(library[i].ID);
        }
        if (result.empty())
        {

            cout << "Not Found\n";
            return;
        }
        sort(result.begin(), result.end());
        for (auto &&i : result)
            cout << i << endl;
        break;
    case 4:
        for (i = 0; i < max; i++)
        {
            if (query == library[i].publisher)
                result.push_back(library[i].ID);
        }
        if (result.empty())
        {
            cout << "Not Found\n";
            return;
        }
        sort(result.begin(), result.end());
        for (auto &&i : result)
            cout << i << endl;
        break;
    case 5:
        for (i = 0; i < max; i++)
        {
            if (query == library[i].year)
                result.push_back(library[i].ID);
        }
        if (result.empty())
        {
            cout << "Not Found\n";
            return;
        }
        sort(result.begin(), result.end());
        for (auto &&i : result)
            cout << i << endl;
        break;
    default:
        break;
    }
    return;
}

int main(int argc, char const *argv[])
{
    int serialnumber[max];
    int N, i, M, NO, number;
    string query;
    scanf("%d\n", &N);
    for (i = 0; i < N; i++) //记住这样处理，不然输入错误！需要使用getline函数，输入的ID也可能是012345
    {
        getline(cin, library[i].ID);
        getline(cin, library[i].title);
        getline(cin, library[i].author);
        getline(cin, library[i].keyword);
        getline(cin, library[i].publisher);
        getline(cin, library[i].year);
    }
    cin >> M;
    for (i = 0; i < M; i++)
    {
        scanf("%d: ", &NO);
        getline(cin, query);
        queries[i] = query;
        serialnumber[i] = NO;
    }

    for (i = 0; i < M; i++)
    {
        printf("%d: ", serialnumber[i]);
        cout << queries[i] << endl;
        query = queries[i];
        number = serialnumber[i];
        Find_book(number, query);
        result.clear();
    }
    return 0;
}