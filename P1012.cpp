#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string in[20];
int cmp(const string &a, const string &b)
{
    return a + b > b + a;
}
int main1()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    sort(in , in  + n, cmp);
    for (int i = 0; i < n; i++)
        cout << in[i];
    cout << endl;
    return 0;
}

int main()
{
    main1();
}

struct num
{
    int a;
    int b;
} number[20];
int cmpt(int a, int b, int c)
{
    int x = a / pow(10, c - 1);
    int y = b / pow(10, c - 1);
    // cout << x << ' ' << y << endl;
    if (x == y)
    {
        if (c == 1)
            return 0;
        return cmpt(a - x * pow(10, c-1), b - y * pow(10, c-1), c - 1);
    }
    else
        return (x > y);
}
int cmps(num a1, num a2)
{
    return cmpt(a1.a, a2.a, max(a1.b, a2.b)); //降序
}
int main2()
{
    int n,x,y,t;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> x;
        number[i].a=x;
        int t = 0;
        while(x!=0) //log10x
        {
            t++;
            x = x / 10;
        }
        number[i].b = t;
    }
    sort(number,number+n,cmps);
    for (int i = 0; i < n;i++)
    {
        cout << number[i].a;
    }
    return 0;
}
