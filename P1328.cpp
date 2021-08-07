#include <iostream>
using namespace std;
int a[200], b[200];
int result[5][5] = {{0,-1,1,1,-1}, 
                    {1,0,-1,1,-1}, 
                    {-1,1,0,-1,1}, 
                    {-1,-1,1,0,1}, 
                    {1,1,-1,-1,0}};//i的结果
int main()
{
    int n, na, nb,cnta=0,cntb=0;
    cin >> n >> na >> nb;
    for (int i = 0; i < na;i++)
        cin >> a[i];
    for (int i = 0; i < nb;i++)
        cin >> b[i];
    for (int i = 0; i < n;i++)
    {
        if (result[ a[i % na] ][ b[i % nb] ] == 1)
            cnta++;
        else if (result[ a[i % na] ][ b[i % nb] ] == -1)
            cntb++;
    }
    cout << cnta << " " << cntb;
    return 0;
}