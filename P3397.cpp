#include <iostream>
using namespace std;
#define M2
int f[1002][1002]={0};

int main1(int argc, const char **argv)
{
#ifdef DEBUG
    freopen("./P3397_1.in", "rb", stdin);
    //freopen("./P4343/tmp.txt", "wb", stdout);
#endif
    int n, m, x1, x2, y1, y2;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) //O(mn)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j <= x2; j++) //O(n)
            f[j][y1]++, f[j][y2+1]--;//!
    }
    for (int i = 1; i <= n; i++) //O(n^2)
    {
        int sum = 0;

        for (int j = 1; j <= n; j++)
        {
            sum += f[i][j];
            cout << sum << ' ';
        }
        cout << endl;
    }
    return 0;
}

int main(int argc, const char **argv)
{
#ifdef DEBUG
    freopen("./P3397_1.in", "rb", stdin);
    //freopen("./P4343/tmp.txt", "wb", stdout);
#endif
    int n, m, x1, x2, y1, y2;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) //O(m)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        f[x1][y1]++;
        f[x1][y2+1]--;
        f[x2+1][y1]--;
        f[x2+1][y2+1]++;
    }
    for (int i = 1; i <= n; i++) //O(n^2)
    {
        for (int j = 1; j <= n;j++)
        {
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];//注意必须更新f[i][j]
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}