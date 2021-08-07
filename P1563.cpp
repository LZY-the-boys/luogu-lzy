#include <iostream>
using namespace std;
int dir[100000];
char name[100000][11];
int main()
{
    int n, m;
    cin >> n >> m; //玩具小人的个数和指令的条数
    for (int i = 0; i < n;i++)
    {
        cin >> dir[i] >> name[i];
    }
    int ind = 0,ai,si;
    for (int i = 0; i < m;i++)
    {
        cin >> ai >> si;
        if(dir[ind]^ai)
            ind = (ind + si+n) % n;
        else
            ind = (ind - si+n) % n;
        // cout << ind<<endl;
    }
    cout << name[ind];
    return 0;
}