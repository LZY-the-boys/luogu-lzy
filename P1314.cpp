#include <iostream>
#define ll long long
using namespace std;
int n, m, w[200000], v[200000], l[200000], rl[200000];
ll a[200000], b[200000];
ll s, rmin = 1e15;

ll y1(int W)
{
    ll c = 0;
    for (int i = 0; i < m; i++)
    {
        ll a = 0, b = 0; //!
        for (int j = l[i]; j <= rl[i]; j++)
        {
            if (w[j - 1] >= W) //!
            {
                a++;
                b += v[j - 1];
            }
        }
        c += a * b; //!
    }
    return c;
}
ll y(int W)
{
    //前缀和-减少了重复值的计算
    if (w[0] >= W)
        b[0] = 1, a[0] = v[0];
    else
        b[0] = 0, a[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (w[i] >= W)
            b[i] = b[i - 1] + 1, a[i] = a[i - 1] + v[i];
        else
            b[i] = b[i - 1], a[i] = a[i - 1];
    }

    ll c = 0;
    for (int i = 0; i < m; i++)
    {
        // ll a = 0, b = 0;//!
        //for (int j = l[i]; j <= rl[i]; j++)
        // {
        //     if (w[j-1] >= W)//!
        //     {
        //         a++;
        //         b += v[j-1];
        //     }
        // }
        if (l[i] == 1)
            c += (b[rl[i] - 1]) * (a[rl[i] - 1]);
        else
            c += (b[rl[i] - 1] - b[l[i] - 2]) * (a[rl[i] - 1] - a[l[i] - 2]); //!
    }
    return c;
}
//#define graph
int main(int argc, char const *argv[])
{
#ifdef DEBUG
    freopen("./P1314_5.in", "rb", stdin);
    freopen("./tmp2.txt", "wb", stdout);
#endif
    cin >> n >> m >> s;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
        r = max(r, w[i]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> rl[i];
    }
#ifdef graph
    for (int i = 0; i <= r; i++)
    {
        cout << i << ":" << abs(s - y(i)) << endl;
    }
#else
    int l = 0;
    while (l < r)
    {
        int mid = (r + l) / 2;
        if (y(mid) > s)
            l = mid + 1;
        else
            r = mid - 1;
        rmin = min(rmin, abs(s - y(mid)));
    }
    int mid = (r + l) / 2;
    rmin = min(rmin, abs(s - y(mid))); //! l==r的时候就退出了
    cout << rmin;
#endif
    return 0;
}
