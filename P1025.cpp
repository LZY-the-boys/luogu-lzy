#include <iostream>
using namespace std;
int f(int i,int n, int k);//dfs
int main()
{
    int N, K;
    cin >> N >> K;
    cout << f(1,N, K);
    return 0;
}
int f(int j,int n,int k)
{
    if(k==1)
    {
        return 1;
    }
    int fn = 0;
    for (int i = j; i <= n/k;i++)
        fn += f(i,n - i, k - 1);
    return fn;
}