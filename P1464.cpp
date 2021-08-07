#include <iostream>
using namespace std;
#define ll long long 
ll wa[21][21][21];
int flag[21][21][21]={0};
ll w(ll a, ll b, ll c);
int main()
{
    ll a, b, c;
    while(1)
    {
        cin >> a >> b >> c;
        if(a==-1&&b==-1&&c==-1)
            break;
        cout << "w("<<a<<", "<<b<<", "<<c<<") = "<< w(a, b, c)<<endl;
    }
    return 0;
}
ll w(ll a,ll b,ll c)
{
    //负数和大于20的数直接特判，就不会影响数组
    if(a<=0||b<=0||c<=0)
        return 1;
    if(a>20||b>20||c>20)
        return w(20, 20, 20);
    if(flag[a][b][c]==0)
    {
        if(a<b&&b<c)
        {
            wa[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        }
        else
        {
            wa[a][b][c] = w(a-1, b, c) + w(a-1, b - 1, c) + w(a-1,b,c-1)- w(a-1, b - 1, c-1);
        }
        flag[a][b][c] = 1;
    }
    return wa[a][b][c];
}