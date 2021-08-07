#include <iostream>
using namespace std;
int main() //O(n*log10n)
{
    //1≤n≤1,000,000,0≤x≤9
    int n, x;
    cin >> n >> x;
    int cnt=0;
    for(int i = 1; i <= n; i++)
    {
        int tmp = i;
        while (tmp)
        {
            if (x == tmp % 10)
                cnt++;
            tmp /= 10;
            // cout << tmp<<endl;
        }
    }
    cout << cnt;
    return 0;
}

/* O(log10n)
n=728，x=7
个位7:73个 7,17,...,727
十位7:70个 70~79,170~179,...,670~679
百位7:29个 700~728
*/
int main1() //O(n*log10n)
{
    //1≤n≤1,000,000,0≤x≤9
    int n, x;
    cin >> n >> x;
    int cnt = 0,m=1;
    while(m<=n)
    {
        int a = n / (m * 10), b = n / m % 10, c = n % m; //a,b,c为n的三部分，求哪一位x的个数，b就为那一位数，a为b左边的数，c为b右边的数，如求1~728中十位7的个数，则a=7，b=2，c=8
        if (x)
        {
            if (b > x)
                cnt += (a + 1) * m; //如果b>x，说明有(a+1)*m个x（如求1~728中个位7的个数，则为（72+1）*1=73）
            if (b == x)
                cnt += a * m + c + 1; //如果b=x，说明有a*m+c+1个x（如求1~728中百位7的个数，则为0*100+28+1=29）
            if (b < x)
                cnt += a * m; //如果b<x，说明有a*m个x（如求1~728中十位7的个数，则为7*10个）
        }
        else
        { //x=0的情况和x！=0的情况有所不同
            if (b)
                ans += a * m;
            else
                ans += (a - 1) * m + c + 1;
        }
        m *= 10;
    }
    cout << cnt;
}
//	1.位数比b小的	很明显每个数码f[i]=f[i-1]*10+10^(i-1);（不考虑前导零）
// 2.枚举从高到低位 第一个比b小的位（同1） 3.最后别忘了统计b 4.一定要注意前导零。
#include <cstdio>
#define LL long long
#define Maxn 120
    using namespace std;
LL a, b, dight, sta[Maxn], stb[Maxn], num[Maxn], f[Maxn], powof[Maxn];
inline LL read()
{
    LL X = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        X = (X << 3) + (X << 1) + ch - '0';
        ch = getchar();
    }
    return X * w;
}
inline void Get(LL x, LL *st)
{
    if (x == 0)
        return;
    LL top = 0, res = x;
    while (x)
        num[++top] = x % 10, x /= 10;
    for (LL i = 1; i < top; i++)
    {
        st[0] += f[i - 1] * 9;
        for (LL j = 1; j < 10; j++)
            st[j] += f[i - 1] * 9 + powof[i - 1];
    }
    res -= num[top] * powof[top - 1];
    for (LL i = 1; i < num[top]; i++)
        st[i] += powof[top - 1];
    for (LL i = 0; i < 10; i++)
        st[i] += f[top - 1] * (num[top] - 1);
    st[num[top]] += res + 1;
    for (LL i = top - 1; i; i--)
    {
        res -= num[i] * powof[i - 1];
        for (LL j = 0; j < num[i]; j++)
            st[j] += powof[i - 1];
        for (LL j = 0; j < 10; j++)
            st[j] += f[i - 1] * num[i];
        st[num[i]] += res + 1;
    }
}
int main()
{
    a = 1;
    b = read();
    dight = read();
    powof[0] = 1;
    for (LL i = 1; i < 15; i++)
        powof[i] = powof[i - 1] * 10;
    for (LL i = 1; i < 15; i++)
        f[i] = f[i - 1] * 10 + powof[i - 1];
    Get(a - 1, sta);
    Get(b, stb);
    printf("%lld ", stb[dight] - sta[dight]);
    return 0;
}