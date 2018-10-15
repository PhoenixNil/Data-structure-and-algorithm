// Student ID is 6 digit integer
// A > C > M > E,当各门分数相等的时候
// 输出4门成绩最好的排名
#include <iostream>
#define max 2001
using namespace std;

int main(int argc, char const *argv[])
{
    int N, M, i, student[max], j;
    int ID[max][5], flag;
    int check[max], rank[max], temp[max][4], temp2[max][4], min[max][4] = {0};
    char course[4] = {'C', 'M', 'E', 'A'};
    cin >> N >> M; //五个学生成绩，6个学生查阅

    for (i = 0; i < N; i++)
    {
        cin >> ID[i][0] >> ID[i][1] >> ID[i][2] >> ID[i][3];
        ID[i][4] = (ID[i][1] + ID[i][2] + ID[i][3]) / 3;
    }
    // for (i = 0; i < M; i++)
    // {
    //     cin >> check[i]; //输入M个人的数据
    // }
    for (i = 0; i < N; i++)

    {
        temp[i][0] = ID[i][1];
        temp[i][1] = ID[i][2];
        temp[i][2] = ID[i][3];
        temp[i][3] = ID[i][4];
    }

    // 对每门成绩进行排序
    for (j = 1; j < 5; j++) //对后四列进行升序排序
    {
        //对第j列进行排序
        int m, n;
        int t;
        for (m = 0; m < N - 1; m++)
        {
            for (n = m + 1; n < N; n++)
            {
                if (ID[m][j] < ID[n][j])
                {
                    t = ID[n][j];
                    ID[n][j] = ID[m][j];
                    ID[m][j] = t;
                }
            }
        }
    }

    //找到最好成绩
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (ID[j][1] == temp[i][0])
            {
                min[i][0] += 1;
                if (min[i][0] == 1)
                    temp2[i][0] = j + 1;
            }
            if (ID[j][2] == temp[i][1])
            {
                min[i][1] += 1;
                if (min[i][1] == 1)
                    temp2[i][1] = j + 1;
            }
            if (ID[j][3] == temp[i][2])
            {
                min[i][2] += 1;
                if (min[i][2] == 1)
                    temp2[i][2] = j + 1;
            }
            if (ID[j][4] == temp[i][3])
            {
                min[i][3] += 1;
                if (min[i][3] == 1)
                    temp2[i][3] = j + 1;
            }
        }
    }

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
            if (check[i] == ID[j][0])
            {
                cout << rank[i] << ' ' << course[student[i] - 1] << '\n';
                flag = 1;
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
        if (check[M - 1] == ID[j][0])
        {
            cout << rank[i] << ' ' << course[student[i] - 1];
        }
    }
    if (flag == 0)
        cout << "N/A";
    return 0;
}