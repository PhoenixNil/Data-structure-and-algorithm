#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct record
{
	char ID[10];
	int time;
	int flag;
};
int comp1(record a, record b)
{
	if (strcmp(a.ID, b.ID) != 0)
		return strcmp(a.ID, b.ID) < 0;
	else
		return a.time < b.time;
}
int comp2(record a, record b)
{
	return a.time < b.time;
}
int main()
{
	int N, K, i, j;
	int hour, minute, second, index = 0, maxtime = 0;
	char tempflag[4];
	cin >> N >> K;
	vector<record> car(N), period;
	vector<int> cnt(N);
	map<string, int> parktime;
	for (i = 0; i < N; i++)
	{
		scanf("%s %d:%d:%d %s\n", car[i].ID, &hour, &minute, &second, tempflag);
		car[i].time = hour * 3600 + minute * 60 + second;
		car[i].flag = strcmp(tempflag, "in") == 0 ? 1 : -1; //flag==1是进入，flag==-1是出门
	}
	sort(car.begin(), car.end(), comp1);
	for (i = 0; i < car.size() - 1; i++) //对不满足条件的数据进行筛选
	{
		if (car[i].flag == 1 && car[i + 1].flag == -1 && strcmp(car[i].ID, car[i + 1].ID) == 0) //相等返回0
		{
			period.push_back(car[i]);
			period.push_back(car[i + 1]);
			parktime[car[i].ID] += car[i + 1].time - car[i].time; //记录停留时间的最长的编号
			if (maxtime < parktime[car[i].ID])
			{
				maxtime = parktime[car[i].ID];
			}
		}
	}
	sort(period.begin(), period.end(), comp2);
	//记录每个时间点的人数,后一个时间点的人数=等于前一个时间点的人数+flag
	for (i = 0; i < N - 1; i++)
	{
		if (i == 0)
		{
			cnt[i] = period[i].flag;
		}
		else
		{
			cnt[i] = cnt[i - 1] + period[i].flag;
		}
	}
	for (i = 0; i < K; i++)
	{
		scanf("%d:%d:%d", &hour, &minute, &second);
		int temptime = 3600 * hour + 60 * minute + second;
		for (j = index; j < period.size(); j++)
		{
			if (temptime < period[j].time) //temptime 的时间比period[j]的时间早，所以输出上一个时间段的人数
			{
				if (!j)
					printf("0\n");
				else
				{
					printf("%d\n", cnt[j - 1]);
					index = j;
				}
				break;
			}
			else if (j == period.size() - 1) //这一步不是很懂，需要复习
			{
				printf("%d\n", cnt[j]);
			}
		}
	}
	for (auto it = parktime.begin(); it != parktime.end(); it++)
	{
		if (it->second == maxtime)
			cout << it->first << ' ';
	}
	printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
	return 0;
}