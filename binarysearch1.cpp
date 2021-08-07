#include <iostream>
using namespace std;

int main1()
{
    int a[10] = {2, 3, 4, 4, 5, 5, 6, 7, 8, 10};
    int l = 0, r = 9,mid=0;
    while(l<=r)
    {
        mid = (l + r) / 2;
        if(a[mid]==2)
            break;
        else if(a[mid]<2)
            l = mid+1 ;
        else
            r = mid-1 ;
        cout << l << ' ' << r << endl;//会卡在[0,2]
    }
    cout << mid;
    return 0;
}

int main2()
{
    int a[10] = {2, 3, 4, 4, 5, 5, 6, 7, 8, 10};
    int l = 0, r = 9, mid = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == 10)
            break;
        else if (a[mid] < 10)
            l = mid ;
        else
            r = mid ;
        cout << l << ' ' << r << endl;//会卡在[8,9]
    }
    cout << mid;
    return 0;
}
int main()
{
    return main2();
}
