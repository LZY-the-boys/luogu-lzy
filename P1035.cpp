#include <iostream>
using namespace std;
int main()
{
    int k,i;
    cin >> k;
    double s=0.0;
    for (i = 1;s<=k;i++)
    {
        s += 1.0 / i;
    }
    cout << i-1;//注意！
    return 0;
}