#include <iostream>
using namespace std;
#define ll long long
int l1;
ll k,n,sum,cnt;
int x[100000];
ll ac(ll mid)
{
    sum=0,cnt=0;
    for (ll i = 0; i < l1;i++)
    {
        sum += x[i];
        if(sum>=mid)
        {
            sum = 0;
            cnt++;
        }
        else if(sum<0)
            sum = 0;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
#ifdef DEBUG
    freopen("./P4343/autoac19.in", "rb", stdin);
    freopen("./P4343/tmp.txt", "wb", stdout);
#endif
    cin >> l1 >> k;
    int xm = 0;
    for (int i = 0; i < l1;i++)
    {
        cin >> x[i];
        xm = max(xm, x[i]);
    }
    ll l = 1, r = 1e15;//!还是卡住了
    while (l < r) //最左边
    {
        ll mid = (l + r) / 2;
        if (ac(mid) > k) 
#ifdef M1                //[a a+1] 其中ac(a)>k,ac(a+1)=k;
            l = mid;
        else
            r = mid - 1;
#else//不会卡
            l = mid+1;
        else
            r = mid;
#endif
        // cout << "[" << l << ' ' << r << "]" << endl;
    }
    if(ac(l)<k)
    {
        cout << -1;
        return 0;
    }
    cout << l<<' ';
    l = 1, r = 1e15;
    while (l < r) //最右边
    {
        ll mid = (l + r) / 2;
        if (ac(mid) >= k)
            l = mid+1;
        else
            r = mid;
        // cout << "[" << l << ' ' << r << "]" << endl;
    }
    cout << l - 1;
    return 0;
}
