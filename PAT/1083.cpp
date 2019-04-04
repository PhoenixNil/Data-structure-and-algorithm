#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct student
{
	string name;
	int grade;
	string ID;
};
vector<struct student> students;
int comp(struct student A, struct student B)
{
	return A.grade > B.grade;
}
int main()
{
	int N, i;
	int grade1, grade2;
	bool flag = false;
	struct student temp;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> temp.name >> temp.ID >> temp.grade;
		students.push_back(temp);
	}
	cin >> grade1 >> grade2;
	sort(students.begin(), students.end(), comp);
	for (i = 0; i < students.size(); i++)
	{
		if (students[i].grade >= grade1 && students[i].grade <= grade2)
		{
			cout << students[i].name << " " << students[i].ID << endl;
			flag = true;
		}
	}
	if (!flag)
	{
		cout << "NONE";
	}
	return 0;
}