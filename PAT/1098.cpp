#include <algorithm>
#include <iostream>
using namespace std;
int A[105], B[105], C[105];
void downAdjust(int low, int high) //就是不断比较当前结点和自己的孩子结点哪个大，如果孩子大就把孩子结点和自己交换，
// 然后再不断调整直到到达区间的最大值不能再继续了为止
{
    int i = 1, j = i * 2;
    while (j <= high)
    {
        if (j + 1 <= high && C[j] < C[j + 1]) //比较左节点和右节点，找到较大者
            j = j + 1;
        if (C[i] >= C[j])
            break;
        swap(C[i], C[j]); //交换自己和孩子
        i = j;
        j = i * 2;
    }
}
int main()
{
    int N, i, j = 0, p;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (i = 0; i < N; i++)
    {
        cin >> B[i];
        C[i + 1] = B[i];
    }
    for (i = 0; i < N - 1; i++)
    {
        if (B[i] > B[i + 1])
        {
            j = i;
            break;
        }
    }
    for (j = i + 1; j < N; j++) //i+1是第一个不满足大于A[i]的数
    {
        if (A[j] != B[j])
        {
            break;
        }
    }
    if (j == N)
    {
        cout << "Insertion Sort" << endl;
        sort(A, A + i + 2);
        cout << A[0];
        for (i = 1; i < N; i++)
        {
            cout << " " << A[i];
        }
    }
    else
    {
        cout << "Heap Sort" << endl;
        p = N;
        while (p > 2 && C[p] >= C[1])
            p--;
        swap(C[1], C[p]); //下一次交换堆顶和最后一个元素
        downAdjust(1, p - 1);
        cout << C[1];
        for (i = 2; i <= N; i++)
        {
            cout << " " << C[i];
        }
    }
}