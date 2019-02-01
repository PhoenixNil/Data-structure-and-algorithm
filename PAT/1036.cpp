#include <iostream>
#include <vector>
using namespace std;
struct student
{
    string name;
    string ID;
    char gender;
    int grade;
};
int main()
{
    int N, i;
    struct student temp;
    struct student maxgirl, minboy;
    maxgirl.grade = -1;
    minboy.grade = 101;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> temp.name >> temp.gender >> temp.ID >> temp.grade;
        if (temp.gender == 'F')
        {
            if (temp.grade > maxgirl.grade)
            {
                maxgirl = temp;
            }
        }
        if (temp.gender == 'M')
        {
            if (temp.grade < minboy.grade)
            {
                minboy = temp;
            }
        }
    }
    if (maxgirl.grade != -1)
    {
        cout << maxgirl.name << " " << maxgirl.ID << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    if (minboy.grade != 101)
    {
        cout << minboy.name << " " << minboy.ID << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    if (maxgirl.grade != -1 && minboy.grade != 101)
    {
        cout << maxgirl.grade - minboy.grade;
    }
    else
    {
        cout << "NA";
    }
    return 0;
}