#include <iostream>
using namespace std;
struct amymap
{
    int a, b, g, k;
} mymap[10000];
int main()
{
    int n,x,y;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> mymap[i].a >> mymap[i].b >> mymap[i].g >> mymap[i].k;
    }
    cin >> x >> y;
    //正序查找
    // int tmp = -1;
    // for (int i = 0; i < n;i++)
    // {
    //     if (x <= mymap[i].a + mymap[i].g && x >= mymap[i].a && y >= mymap[i].b && y <= mymap[i].b + mymap[i].k)
    //     {
    //         tmp = i+1;
    //     }
    // }
    //cout<<tmp;
    //!逆序查找
    for (int i = n-1; i >= 0;i--)
    {
        if (x <= mymap[i].a + mymap[i].g && x >= mymap[i].a && y >= mymap[i].b && y <= mymap[i].b + mymap[i].k)
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}