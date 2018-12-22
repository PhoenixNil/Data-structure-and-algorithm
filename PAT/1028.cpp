#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct student
{
    string ID;
    string name;
    int grade;
} learner;
vector<struct student> students;
int comp1(learner a, learner b)
{
    return a.ID < b.ID;
}
int comp2(learner a, learner b)
{

    if (a.name == b.name)
    {
        return a.ID < b.ID;
    }
    else
        return a.name < b.name;
}
int comp3(learner a, learner b)
{

    if (a.grade == b.grade)
        return a.ID < b.ID;
    else
        return a.grade < b.grade;
}
int main(int argc, char const *argv[])
{
    int N, C, i;
    cin >> N >> C;
    char name[10], ID[10];
    struct student temp;
    for (i = 0; i < N; i++)
    {
        cin >> temp.ID >> temp.name >> temp.grade;
        students.push_back(temp);
    }
    switch (C)
    {
    case 1:
        sort(students.begin(), students.end(), comp1); //comp1可以自定义
        break;
    case 2:
        sort(students.begin(), students.end(), comp2);
        break;
    case 3:
        sort(students.begin(), students.end(), comp3);
        break;
    default:
        break;
    }

    for (auto &&j : students)
    {
        strcpy(ID, j.ID.c_str());
        strcpy(name, j.name.c_str());
        printf("%s %s %d\n", ID, name, j.grade);
        // cout << j.ID << " " << j.name << " " << j.grade << endl;
    }
    return 0;
}