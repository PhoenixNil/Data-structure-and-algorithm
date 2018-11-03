// 最后一个测试点未通过
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define max 1000 + 5

void PrintTime(int i, int endtime[], bool Sorry[])
{

    if (Sorry[i] == false)
    {
        printf("%02d:%02d\n", (endtime[i] + 480) / 60, (endtime[i] + 480) % 60);
    }

    else
    {
        cout << "Sorry" << endl;
    }
}

int main(int argc, char const *argv[])
{
    int people, leavetime, min, time, index = 1, windowstime[21];
    fill(windowstime, windowstime + 21, 0);
    vector<queue<int>> windows(21);         //20个柜台，每个柜台是一个队列
    int Time[max] = {0}, endtime[20] = {0}; //人是从1开始记录的
    bool Sorry[max] = {false};
    int i, j, N, M, K, Q;    //M是黄线内的人数
    cin >> N >> M >> K >> Q; //N是窗口数
    for (i = 1; i < K + 1; i++)
    {
        cin >> time; //每个人的处理时间
        Time[i] = time;
    }

    for (i = 1; i <= M; i++) //黄线内
    {
        for (j = 1; j <= N; j++)
        {
            if (index <= K) //所有柜台黄线内的人数可能大于查询的总人数
            {
                if ((!windows[j].empty()) && (endtime[windows[j].back()] >= 540))
                    Sorry[index] = true;
                windows[j].push(index);
                windowstime[j] += Time[index];
                endtime[index] = windowstime[j];
                index++;
            }
        }
    }

    for (i = index; i <= K; i++) //黄线外
    {
        leavetime = endtime[windows[1].front()];
        for (j = 2; j <= N; j++)
        {
            if (endtime[windows[j].front()] < leavetime) //找到最先出来的一个窗口
            {
                leavetime = endtime[windows[j].front()];
                min = j;
            }
        }
        if (leavetime == endtime[windows[1].front()]) //相同出队时间，选编号最小的
        {
            min = 1;
        }
        windows[min].pop(); //这个窗口的首位已经处理完毕，出队列
        if (windowstime[min] >= 540)
            Sorry[i] = true;
        windows[min].push(i);                    //黄线外的人选择了该窗口
        endtime[i] = windowstime[min] + Time[i]; // 这个人的结束时间=这个窗口黄线内最后一个人的时间+这个人的处理时间
        windowstime[min] = endtime[i];           //该窗口的最后结束时间变成刚刚进入的那个人的结束时间
    }

    for (i = 0; i < Q; i++)
    {
        cin >> people;
        PrintTime(people, endtime, Sorry);
    }
    return 0;
}