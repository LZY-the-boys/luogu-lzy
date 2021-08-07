#include <iostream>
using namespace std;
int main()
{
    int h[10],tth;
    for (int i = 0; i < 10;i++)
    {
        cin >> h[i];
    }
    cin >> tth;
    int cnt = 0;
    for (int i = 0; i < 10;i++)
    {
        if(tth+30>=h[i])
            cnt++;
    }
    cout << cnt;
    return 0;
}