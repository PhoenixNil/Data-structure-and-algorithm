#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct schoool
{
    int quota;
    vector<int> applicant;
};

struct student
{
    int id;
    int GE;
    int GI;
    int fin;
    vector<int> applications;
};
vector<schoool> University;
vector<student> students;
int index[50000];
int comp(student &A, student &B)
{
    if (A.fin != B.fin)
    {
        return A.fin > B.fin;
    }
    else
        return A.GE > B.GE;
}
int main()
{
    int quota[105], temp, temp2;
    int N, M, K, i, j;
    cin >> N >> M >> K;
    students.resize(N);
    University.resize(M);
    for (i = 0; i < M; i++)
    {
        cin >> quota[i];
        University[i].quota = quota[i];
    }
    for (i = 0; i < N; i++)
    {
        students[i].id = i;
        cin >> students[i].GE >> students[i].GI;
        students[i].fin = (students[i].GE + students[i].GI);
        for (j = 0; j < K; j++)
        {
            cin >> temp;
            students[i].applications.push_back(temp);
        }
    }
    sort(students.begin(), students.end(), comp);
    for (i = 0; i < students.size(); i++)
    {
        index[students[i].id] = i;
    }

    for (auto &&i : students)
    {
        for (auto it = i.applications.begin(); it != i.applications.end(); it++)
        {
            if (!University[*it].applicant.empty())
            {
                temp2 = index[University[*it].applicant.back()];
            }
            if (University[*it].applicant.size() < University[*it].quota || (i.fin == students[temp2].fin && i.GE == students[temp2].GE)) //排名跟录取的最后一个排名一样
            {
                University[*it].applicant.push_back(i.id);
                break;
            }
        }
    }

    for (auto &&i : University)
    {
        sort(i.applicant.begin(), i.applicant.end());
        if (!i.applicant.empty())
        {
            for (auto it = i.applicant.begin(); it != i.applicant.end(); it++)
            {
                if (it != i.applicant.begin())
                    cout << " ";
                cout << *it;
            }
        }
        cout << endl;
    }
    return 0;
}