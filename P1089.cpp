#include <iostream>
using namespace std;
int main()
{
    //12行数据，每行包含一个小于350的非负整数，分别表示11月到1212月津津的预算。
    //每个月的月初妈妈给津津300元钱
    int c,m=0,sm=0,a=0;
    for (int i = 0; i < 12;i++)
    {
        cin >> c;
        int lm = 300 - c + m;
        if(lm<0)
        {
            cout << -(i+1);return 0;
        }
        else
        {
            sm += (lm / 100) * 100;
            m = lm %100;
        }
    }
    cout << m + 1.2 * sm;
    return 0;
}