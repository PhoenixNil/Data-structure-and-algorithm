// All the numbers in the input are less than 100.
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int N, floor, time = 0, i, now = 0;
    cin >> N;

    for (i = 0; i < N; i++)
    {
        cin >> floor;
        if (floor > now)
        {
            time += (floor - now) * 6 + 5;
            now = floor;
        }
        else if (floor < now)
        {
            time += (now - floor) * 4 + 5;
            now = floor;
        }
        else
            time += 5;
    }
    cout << time;
    return 0;
}
