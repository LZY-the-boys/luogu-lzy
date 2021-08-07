#include <iostream>
using namespace std;
int main()
{
    int M;
    cin >> M;
    int f1 = 0, f2 = 1;
    for (int i = 1;;i++)
    {
        int tmp = f2;
        f2 = (f1 + f2) % M;
        f1 = tmp;
        if(f1==0&&f2==1)
        {
            cout << i;
            return 0;
        }
    }
}