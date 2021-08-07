#include <iostream>
#include <algorithm>
using namespace std;
int p[30000];
int main(int argc, const char** argv) 
{
    int w, n;
    cin >> w >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> p[i];
    }
    sort(p, p + n);
    int cnt = 0;
    for (int i = 0,j=n-1; i < j;)
    {  
        if(p[i]+p[j]<=w)
        {
            j--, i++;
        }
        else 
        {
            j--;
        }
        cnt++;
        if(i==j)
            cnt++;
    }

    cout << cnt;
    return 0;
}