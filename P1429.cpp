#include<iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define f(i,n) for(; i < n; i++)
#define ff(i,l,r) for(int i=l; i <= r; i++)
struct point {
    int x;
    int y;
} p[200000];
int tmp[200000];
int cmpx(point a,point b)
{
    return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
} 
int cmpy(int a, int b)
{
    return (p[a].y < p[b].y);
}
double distance(int l,int r)
{
    return sqrt((double)(p[l].x - p[r].x) * (p[l].x - p[r].x) + (double)(p[l].y - p[r].y)*(p[l].y - p[r].y));
}
double distance1(int l, int r)
{
    return ((double)(p[l].x - p[r].x) * (p[l].x - p[r].x) + (double)(p[l].y - p[r].y) * (p[l].y - p[r].y));
}

double mergefun(int l,int r)//返回l-r的最小距离
{
    double d;
    //printf("[%d %d]\n", l, r);
    if(l==r)
        return 1e15;//同一个点,最小距离不存在
    if(l+1==r)
        return distance(l,r);
    int mid = (l + r) / 2;
    double d1 = mergefun(l, mid);
    double d2 = mergefun(mid+1, r);
    d = min(d1, d2);
    int tc = 0;
    for (int i = l; i <= r; i++)
    {
        if(abs(p[mid].x-p[i].x)<d)//优化1
            tmp[tc++] = i;
    }
    sort(tmp, tmp + tc, cmpy);//按y排序
    for (int i = 0; i < tc; i++)
    {
        for (int j = i + 1; j < tc && (p[tmp[j]].x - p[tmp[i]].x) < d; j++)//优化2
        {
            double d3 = distance(tmp[i], tmp[j]);
            if (d > d3)
                d = d3;
        }
    }
    return d;
}
int main(int argc, char const *argv[])
{
#ifdef DEBUG
    freopen("./P1429_4.in", "rb", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i=0; i < n; i++)
    {
        scanf("%d%d", &p[i].x, & p[i].y);
    }
    sort(p, p + n, cmpx);
    printf("%.4lf\n",(mergefun(0, n - 1)));
    return 0;
}
