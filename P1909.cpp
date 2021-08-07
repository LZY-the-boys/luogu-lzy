#include <iostream>
using namespace std;
int main()
{
    int num[3], value[3],cost,lastcost=2147383647,n; //3种包装
    cin >> n;
    for (int i = 0; i < 3;i++)
    {
        cin>>num[i]>>value[i];
        if(num[i]==0)
            continue;
        //!直接使用std::ceil(n*1.0/a)*b;
        if (n % num[i] == 0)
            cost = n / num[i] * value[i];
        else if(n%num[i])
            cost = (n / num[i] + 1) * value[i];
        if(lastcost>cost) lastcost = cost;
    }
    cout << lastcost;
    //只买同一种包装的铅笔
    return 0;
}