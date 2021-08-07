#include <iostream>
#include <cstring>
using namespace std;
int p[1000] = {0};
int a[1000][1000] = {0};
int f[1000] = {0};

int main()
{
    //memset(p, 0, sizeof(p));//也可以
    int n, m, k;//n-oier,m-training_day,k-days
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j]; //ith-oier jth-training_day
    }
    int cnt = 0;
    //jth列,即为jth卷子的出现时间,去除重复即可
    for (int j = 0; j < m; j++)
    {
        memset(f, 0, 1000 * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            if (f[a[i][j] - 1] == 0) //列去重
            {
                p[a[i][j]-1]++;
                f[a[i][j]-1] = 1;
            }
        }
    }
    
    for (int i = 0; i < k; i++)
        cout << p[i] << " ";
    //ith day diff paper for training
    return 0;
}

int main1()
{
    bool a[1005][1005];
    int ans;
    int n, m, k;
    memset(a, 0, sizeof(a));
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            a[x][j] = 1;//xth day 需要jth 卷子(去重)
        }
    }
    for (int i = 1; i <= k; i++)
    {
        ans = 0;
        for (int j = 1; j <= m; j++) //按day求和
        {
            if (a[i][j])
                ans++;
        }
        cout << ans << " ";
    }
}