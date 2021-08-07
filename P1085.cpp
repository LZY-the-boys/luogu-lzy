#include <iostream>
using namespace std;
int main()
{
    int st, ht,unhappy,tmax =8,im=0;
    for (int i = 0; i < 7;i++)
    {
        cin >> st >> ht; //津津在学校上课的时间和妈妈安排她上课的时间。
        int t = st + ht;
        if (t > tmax) //津津如果一天上课超过八个小时就会不高兴，而且上得越久0 0 就会越不高兴
        {
            tmax = t;
            im = i+1;
        }
    }
    cout << im; //不会不高兴则输出0
    return 0;
    
}