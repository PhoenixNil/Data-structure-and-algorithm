#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef struct student
{
    int registration;
    string rnumber;
    int grade;
    int frank;
    int lrank;
} people;
vector<people> temp;
vector<people> result;
int comp(people a, people b) //降序
{
    if (a.grade == b.grade)
    {
        return a.rnumber < b.rnumber;
    }
    else
        return a.grade > b.grade;
}
int main()
{
    int N, K, i, j;
    string rnumber;
    people Participant;
    int grade;
    cin >> N;
    for (i = 1; i < N + 1; i++)
    {
        temp.clear();
        cin >> K;
        for (j = 0; j < K; j++)
        {
            Participant.registration = i;
            cin >> rnumber >> grade;
            Participant.rnumber = rnumber;
            Participant.grade = grade;
            temp.push_back(Participant);
        }
        sort(temp.begin(), temp.end(), comp);
        temp[0].lrank = 1;
        result.push_back(temp[0]);
        for (j = 1; j < temp.size(); j++)
        {
            temp[j].lrank = temp[j].grade < temp[j - 1].grade ? j + 1 : temp[j - 1].lrank;
            result.push_back(temp[j]);
        }
    }
    sort(result.begin(), result.end(), comp);
    result[0].frank = 1;
    for (i = 1; i < result.size(); i++)
    {
        result[i].frank = result[i].grade < result[i - 1].grade ? i + 1 : result[i - 1].frank;
    }
    cout << result.size() << endl;
    for (auto &&i : result)
    {
        cout << i.rnumber << " " << i.frank << " " << i.registration << " " << i.lrank << endl;
    }
    return 0;
}