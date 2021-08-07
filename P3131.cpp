#include <iostream>
#define ll long long
using namespace std;
int pre[50001]; //前缀和需要保留0
//int a[50001];不需要
int main(int argc, const char **argv)
{
#ifdef DEBUG
    freopen("./P3131_2.in", "rb", stdin);
    //freopen("./P4343/tmp.txt", "wb", stdout);
#endif
    int n, a;
    cin >> n;
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        pre[i] = (pre[i - 1] + a) % 7; //!
    }
    // for (L = n; L > 0;L--)//从最长的开始 O(n^2)
    // {
    //     for (int i = 1,j =i+L-1; j <= n;i++,j++)
    //         if((pre[j]-pre[i-1])%7==0)
    //         {
    //             cout << L;
    //             return 0;
    //         }
    // }

    //(pre[j]-pre[i-1])%7==0 等价于 pre[j]%7==pre[i-1]%7 由于已经取过余，所以pre[j]==pre[i-1]
    //但是仍然不应该用O(n^2)去搜索
    int first[7] = {0}, last[7] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (first[pre[i]])
            continue;
        else
            first[pre[i]] = i;
    }
    for (int i = n; i > 0; i--)
    {
        if (last[pre[i]])
            continue;
        else
            last[pre[i]] = i;
    }
#ifdef DEBUG
    for (int i = 0; i <=6 ; i++)
    {
        cout << first[i] << ' ' << last[i] << endl;
    }
#endif
    int lm = 0;
    for (int i = 0; i <= 6; i++)
    {
        //if(first[pre[i]]!=0)//! 逻辑不对
        int l = last[i] - first[i]; //! 这个是pre[j]-pre[i-1],只不过i-1写成了i。所以不需要加一
        if (l > lm)
            lm = l;
    }
    cout << lm;
    return 0;
}