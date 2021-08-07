#include <iostream>
using namespace std;
int a[39][39]={0};
int main(int argc, const char** argv) 
{
    int N;
    cin >> N;
    a[0][N / 2] = 1;
    int x = 0, y = N / 2;
    for (int i = 2; i <= N*N;i++)
    {
        if(x==0&&y!=N-1)
        {
            x = N - 1, y++;
        }
        else if(x!=0&&y==N-1)
        {
            x--, y = 0;
        }
        else if(x==0&&y==N-1)
        {
            x++;
        }
        else if(a[x-1][y+1]==0)
        {
            x--, y++;
        }
        else
        {
            x++;
        }
        a[x][y] = i;
    }
    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < N; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}