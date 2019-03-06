#include <iostream>
using namespace std;
int main()
{
    int N;
    int A[100005], i, temp;
    int count = 0;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> temp;
        A[temp] = i; //数组保存的是temp在数组所在的位置
    }
    for (i = 1; i < N; i++)
    {
        if (i != A[i]) //如果i没有占着自己的位置
        {
            while (A[0] != 0) //如果0没有占着他自己的位置
            {
                swap(A[0], A[A[0]]); //就是把0所在的位置和A[0]这个数所在的位置交换，交换后（A[0]）这个数所在的位置就是原来的0所在的位置
                count++;
            }
            if (i != A[i]) //此时0回到了0的位置，但是i还没有回到i的位置，所以先让i暂时到0的位置上来，下一轮会交换回来的
            {
                swap(A[0], A[i]);
                count++;
            }
        }
    }
    cout << count;
    //只能用0和别的数交换
    return 0;
}