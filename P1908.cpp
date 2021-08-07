#include <iostream>
#include <algorithm>
using namespace std;
int a[500000], c[500000];
long long sum = 0;
void mergesort(int l,int r)//r:最后一个数
{
    if(l==r)
        return;
    int i = l, mid = (l + r) / 2;
    int j = mid + 1,k=l;
    mergesort(i, mid);
    mergesort(j, r);
    while (i <= mid && j <= r)
    {
        if(a[i]<=a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++],sum+=mid-i+1;
    }
    while(i<=mid)
        c[k++] = a[i++];
    while(j<=r)
        c[k++] = a[j++];
    for (int i = l; i <= r;i++)
    {
        a[i] = c[i];
    }
}

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergesort(0,n-1);
    cout << sum;
    return 0;
}
