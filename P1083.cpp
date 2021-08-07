#include <iostream>
#include <cstring>
using namespace std;
int r[1000001], delt[1000001], d[1000001], s[1000001], t[1000001];
long long need = 0;
int main1()
{
    int n, m,d,s,t;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
    {
        cin >> r[i];
    }
    for (int j = 1; j <= m;j++)
    {
        cin >> d >> s >> t;
        //O(m*n)
        for (int i = s; i <= t;i++)
        {
            r[i] -= d;
            if(r[i]<0)
            {
                cout << -1<<endl<<j;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}

int main2()
{
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    for (int j = 1; j <= m; j++)
    {
        cin >> d[j] >> s[j] >> t[j];
        delt[s[j]] += d[j];
        delt[t[j] + 1] -= d[j];
#ifdef m2 //绝对不行！与main1等价，所以无法利用m这个循环，只能单独把n的循环放在外面
        for (int i = s[j]; i <= t[j]; i++)
        {
            need += delt[i];
            if (need > r[i])
            {
                cout << -1 << endl << j;
                return 0;
            }
        }
#endif
    }

    /**撤回订单思路：
     * 按订单顺序分配，所以应该是第2个订单第三天不合要求。
     * 但是m1代码会按天的顺序判断，判断成第三个订单第二天（不管是正向还是逆向）
     * 2 5 4 3
     * 2 2 2
     *   3 3 3
     *   4 4 4
     * */
#ifdef m1 //!必须使用m的循环。。。注意错误后肯定只需要执行一次，所以O(nlogn)的复杂度即可
    for (int i = 1; i <= n; i++)
    {
        need+= delt[i];//need[i]=need[i-1]+delt[i]

        if(need>r[i])
        {
            int j = m+1;
            while(need>r[i])
            {
                j--;
                // delt[s[j]] -= d[j];
                // delt[t[j] + 1] += d[j];
                if(s[j]<=i&&t[j]>=i)
                    need -= d[j];
            }
            cout << -1 << endl
                 << j;
            return 0;
        }
    }
#endif
#ifdef m3 //最终效果：满足要求订单优化到O(n)，不满足的仍然是O(m*n)
    for (int i = 1; i <= n; i++)
    {
        need += delt[i]; //need[i]=need[i-1]+delt[i]

        if (need > r[i])
        {
            break;
        }
    }
    if(i!=n+1) //无法满足,单独进入m循环求解
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> d[j] >> s[j] >> t[j];
            delt[s[j]] += d[j];
            delt[t[j] + 1] -= d[j];
            for (int i = s[j]; i <= t[j]; i++)
            {
                need += delt[i];
                if (need > r[i])
                {
                    cout << -1 << endl
                        << j;
                    return 0;
                }
            }
        }
    }
#endif
    cout << 0;
    return 0;
}
int n;
int availible(int mid) //O(max(n,m))
{
    //! delt每次必须置零,还有need！
    memset(delt, 0, sizeof(delt));
    need = 0;
    for (int j = 1; j <= mid; j++)
    {
        delt[s[j]] += d[j];
        delt[t[j] + 1] -= d[j];
    }
    for (int i = 1; i <= n; i++)
    {
        need += delt[i]; 
        if (need > r[i])
            return 0;
    }
    return 1;
}
int main()
{
    int m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    for (int j = 1; j <= m; j++)
    {
        cin >> d[j] >> s[j] >> t[j];
        delt[s[j]] += d[j];
        delt[t[j] + 1] -= d[j];
    }
    int i;
    for (i = 1; i <= n; i++)
    {
        need += delt[i]; //need[i]=need[i-1]+delt[i]
        if (need > r[i])
            break;
    }
    if(i==n+1)
    {
        cout << 0;
        return 0;
    }
    //不满足的，使用二分法优化到O(nlogm)
    int l = 1, r = m;
    while(l<r)
    {
        int mid = (l+r) / 2;
        if(availible(mid))
            l = mid + 1;
        else
            r = mid;
        // cout << "[" << l << ' ' << r << "]" << endl;
    }
    cout << -1 << endl
         << l;
    return 0;
}