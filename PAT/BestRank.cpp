// Student ID is 6 digit integer
// A > C > M > E,当各门分数相等的时候
// 输出4门成绩最好的排名
#include <iostream>
#define max 2001
using namespace std;
int main(int argc, char const *argv[])
{
    int N, M, i, student[max], j;
    int score[max][4], flag;
    string check[max], ID[max];
    int rank[max], temp[max][4], temp2[max][4], min[max][4] = {0}; //temp2存放的是每个ID的每个科目的名次
    char course[4] = {'C', 'M', 'E', 'A'};
    cin >> N >> M; //五个学生成绩，6个学生查阅

    for (i = 0; i < N; i++)
    {
        cin >> ID[i] >> score[i][0] >> score[i][1] >> score[i][2];
        score[i][3] = (score[i][0] + score[i][1] + score[i][2]) / 3;
    }
    // for (i = 0; i < M; i++)
    // {
    //     cin >> check[i]; //输入M个人的数据
    // }
    for (i = 0; i < N; i++)

    {
        temp[i][0] = score[i][0];
        temp[i][1] = score[i][1];
        temp[i][2] = score[i][2];
        temp[i][3] = score[i][3];
    }

    // 对每门成绩进行排序
    for (j = 0; j < 4; j++) //对后四列进行升序排序
    {
        //对第j列进行排序
        int m, n;
        int t;
        for (m = 0; m < N - 1; m++)
        {
            for (n = m + 1; n < N; n++)
            {
                if (score[m][j] < score[n][j])
                {
                    t = score[n][j];
                    score[n][j] = score[m][j];
                    score[m][j] = t;
                }
            }
        }
    }
    // 原来的成绩
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (score[j][0] == temp[i][0])
            {
                min[i][0] += 1;
                if (min[i][0] == 1)
                    temp2[i][0] = j + 1;
            }
            if (score[j][1] == temp[i][1])
            {
                min[i][1] += 1;
                if (min[i][1] == 1)
                    temp2[i][1] = j + 1;
            }
            if (score[j][2] == temp[i][2])
            {
                min[i][2] += 1;
                if (min[i][2] == 1)
                    temp2[i][2] = j + 1;
            }
            if (score[j][3] == temp[i][3])
            {
                min[i][3] += 1;
                if (min[i][3] == 1)
                    temp2[i][3] = j + 1;
            }
        }
    }
    //找到最好成绩
    for (i = 0; i < N; i++)
    {
        rank[i] = temp2[i][3];
        student[i] = 4;
        if (rank[i] > temp2[i][0])
        {
            rank[i] = temp2[i][0];
            student[i] = 1;
        }
        if (rank[i] > temp2[i][1])
        {
            rank[i] = temp2[i][1];
            student[i] = 2;
        }
        if (rank[i] > temp2[i][2])
        {
            rank[i] = temp2[i][2];
            student[i] = 3;
        }
    }
    for (i = 0; i < M - 1; i++)
    {
        cin >> check[i];
        flag = 0;
        for (j = 0; j < N; j++)
        {
            if (check[i] == ID[i])
            {
                cout << rank[i] << ' ' << course[student[i] - 1] << '\n';
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "N/A" << '\n';
        }
    }
    flag = 0;
    cin >> check[M - 1];
    for (j = 0; j < N; j++)
    {
        if (check[M - 1] == ID[i])
        {
            cout << rank[i] << ' ' << course[student[i] - 1];
        }
    }
    if (flag == 0)
        cout << "N/A";
    return 0;
}