#include<iostream>
#include <cstring>
using namespace std;
int c[10001] = {0};
string mul(string a, string b)
{
    memset(c, 0,sizeof(c));
    string s = "";
    int la = a.length();
    int lb = b.length();
    for (int i = la - 1; i >= 0; i--)
        for (int j = lb - 1; j >= 0; j--)
        {
            c[i + j+1] += (a[i] - '0') * (b[j] - '0'); //6*4 所以开头必须留一个空
        }
    for (int i = la + lb-1; i >= 0; i--)
    {
        if (c[i] > 9)
            c[i - 1] += c[i] / 10, c[i] = c[i] % 10;
    }
    //去零：
    int len = la + lb - 1, i = 0;
    while (c[i] == 0 && len != i) //防止结果为0的情况
        i++;
    for (; i <= len; i++)
        s.push_back(c[i]+'0');
    return s;
}
string uadd(string &a, string &b)
{
    string s;
    int la = a.length();
    int lb = b.length();
    if (la < lb) //补零，以便长度相同
    {
        for (int i = 1; i <= lb - la; i++)
            a = "0" + a;
    }
    else
    {
        for (int i = 1; i <= la - lb; i++)
            b = "0" + b;
    }
    int l = a.length(); //更新长度
    int tmp, c = 0;     //进位
    for (int i = l - 1; i >= 0; i--)
    {
        tmp = a[i] - '0' + b[i] - '0' + c;
        c = tmp / 10;
        tmp %= 10;
        s = char(tmp + '0') + s;
    }
    if (c)
        s = char(c + '0') + s;
    return s;
}

int main()
{
    int n;
    cin >> n;
    string result = "0",tmp = "1";
    for (int i = 1; i <= n;i++)
    {
        tmp = mul(tmp, to_string(i));//factorial
        result = uadd(tmp,result);
        cout << i << ':' << tmp << endl;
    }
    cout << result;
}