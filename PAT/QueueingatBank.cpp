#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define max 10001
using namespace std;

typedef struct customer
{
    int arrivingtime; //时分秒
    int processtime;  //分钟
} customers;

int comp(const void *a, const void *b)
{
    customers *aa = (customer *)a;
    customer *bb = (customer *)b;
    return (aa->arrivingtime > bb->arrivingtime) ? 1 : -1;
}

int main(int argc, char const *argv[]) //精确到小数点后一位
{
    int N, K, i, j, hour, minute, second, Processtime, first_endtime, first_window = 0, count;
    float averagetime = 0.0;
    int windows[101];
    fill(windows, windows + 101, 8 * 3600);
    // vector<struct customer> people[max];
    customers people[max];
    cin >> N >> K;
    count = N;
    for (i = 0; i < N; i++)
    {
        scanf("%d:%d:%d", &hour, &minute, &second);
        scanf("%d", &Processtime);
        people[i].arrivingtime = hour * 3600 + minute * 60 + second;
        people[i].processtime = Processtime;
    }
    qsort(people, N, sizeof(struct customer), comp); //根据每个人来的时间排序

    for (i = 0; i < N; i++) //队列
    {
        first_window = 0;
        first_endtime = windows[0];
        for (j = 0; j < K; j++) //找到最早结束的窗口
        {

            if (first_endtime > windows[j])
            {
                first_endtime = windows[j];
                first_window = j;
            }
        }

        if (people[i].arrivingtime < first_endtime) //如果等待的顾客比最早结束时间还来的早的话
        {

            if (people[i].arrivingtime > 17 * 3600)
                count--;
            else
            {
                averagetime += first_endtime - people[i].arrivingtime;
                first_endtime = first_endtime + people[i].processtime * 60;
                windows[first_window] = first_endtime; //更新这个柜台的结束时间
            }
        }

        else //有空窗口，选择最前面的窗口并更改该窗口的时间
        {
            if (people[i].arrivingtime > 17 * 3600)
            {
                count--;
                continue;
            }
            windows[first_window] = people[i].arrivingtime + people[i].processtime * 60;
        }
    }
    printf("%.1f", averagetime / (count * 60));

    return 0;
}