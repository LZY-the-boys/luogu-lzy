#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int p[5000], a[5000];
struct cow
{
    int p;
    int a;
} c[5000];
int cmpp(cow d, cow b)
{
    return (d.p == b.p) ? (d.a > b.a) : (d.p < b.p);
}

int main(int argc, const char **argv)
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> c[i].p >> c[i].a;
    }
    sort(c, c + m, cmpp);
    int sum = 0, num,money=0;
    for (int j = 0; j < m; j++)
    {
        if (sum + c[j].a <= n)
            num = c[j].a;
        else
            num = n - sum;
        money += num * c[j].p;
        sum += num;
        if(sum==n)
            break;
    }
    cout << money;
    return 0;
}