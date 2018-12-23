#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string result;
void convert(int number)
{
    int temp = number;
    char remainder;
    string temp2;

    if (temp == 0)
    {
        cout << "00";
    }
    else
    {
        while (temp)
        {

            if (temp % 13 > 9)
                remainder = '7' + temp % 13;
            else
                remainder = '0' + temp % 13;
            temp = temp / 13;
            temp2.push_back(remainder);
        }
        reverse(temp2.begin(), temp2.end());
        if (temp2.size() == 1) //只有一位需要在前面补0
            temp2.insert(temp2.begin(), '0');
        cout << temp2;
    }
}

int main(int argc, char const *argv[])
{
    int red, green, blue;
    scanf("%d %d %d", &red, &green, &blue);
    cout << '#';
    convert(red);
    convert(green);
    convert(blue);
    return 0;
}