#include <iostream>
#include <string>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int flag = 0;
    if(N<=0)
    {
        if(N==0)
        {
            cout << 0;
            return 0;
        }
        N = -N;
        cout << "-";
    }
    string s = to_string(N);
    for (int i = s.length() - 1; i >= 0; i--)
    {
        //!if (flag == 0 && s[i] == 0)
        if (flag == 0 && s[i] == '0')
            continue;
        else if (flag == 0&& s[i] != '0') flag = 1;
        cout << s[i];
    }
    return 0;
}