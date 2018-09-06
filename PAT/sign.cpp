// 每个人进来的时间都不相同，而且进来的肯定比出去的要先输入
#include <iostream>
#include <string>
#include <vector>
#define MAX 13107200
using namespace std;
struct people
{
    string ID_number;
    string Sign_in_time;
    string Sign_out_time;
    int K;
};
int main(int argc, char const *argv[])
{
    people 单个, sign_in, sign_out;
    vector<people> person;
    int i, M, earlist = MAX, latest = 0;
    cin >> M;
    for (i = 0; i < M; i++)
    {
        cin >> 单个.ID_number >> 单个.Sign_in_time >> 单个.Sign_out_time;
        person.push_back(单个);
    }
    vector<people>::iterator it;
    for (it = person.begin(); it != person.end(); it++)
    {
        if (it->Sign_in_time[0] * 36000 + it->Sign_in_time[1] * 3600 + it->Sign_in_time[3] * 600 + it->Sign_in_time[4] * 60 + it->Sign_in_time[6] * 10 + it->Sign_in_time[7] < earlist)
        {
            earlist = it->Sign_in_time[0] * 36000 + it->Sign_in_time[1] * 3600 + it->Sign_in_time[3] * 600 + it->Sign_in_time[4] * 60 + it->Sign_in_time[6] * 10 + it->Sign_in_time[7];
            sign_in = *it;
        }
        if (it->Sign_out_time[0] * 36000 + it->Sign_out_time[1] * 3600 + it->Sign_out_time[3] * 600 + it->Sign_out_time[4] * 60 + it->Sign_out_time[6] * 10 + it->Sign_out_time[7] > latest)
        {
            latest = it->Sign_out_time[0] * 36000 + it->Sign_out_time[1] * 3600 + it->Sign_out_time[3] * 600 + it->Sign_out_time[4] * 60 + it->Sign_out_time[6] * 10 + it->Sign_out_time[7];
            sign_out = *it;
        }
    }
    cout << sign_in.ID_number << ' ' << sign_out.ID_number;
    return 0;
}
// 可以优化，在输入的时候就进行比较，这样不需要迭代器，也不需要别的变量了