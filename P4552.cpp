#include <iostream>
using namespace std;
int a[100000],d[100000];
int main(int argc, const char **argv)
{
#ifdef DEBUG
    freopen("./P4343/autoac19.in", "rb", stdin);
    freopen("./P4343/tmp.txt", "wb", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i>0) d[i-1] = a[i] - a[i - 1];
    }
    return 0;
}