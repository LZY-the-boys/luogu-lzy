#include <iostream>
using namespace std;

int l, r;

int f(int x) //f(x)表示[1,x]的整数中所含数字2的个数
{
    int a = x, t = 1, s = 0; //t是这一位的权值(个位是1，十位是10……)，s是答案
    while (x)
    {
        s += x / 10 * t; //第一部分(1~XXX00)大块的部分
        if (x % 10 > 2)
            s += t;
        if (x % 10 == 2)
            s += a % t + 1; //第二部分(XXX01~XXXXX)零头
        x /= 10;            //删掉最后一位
        t *= 10;
    }
    return s;
}

int main()
{
    cin >> l >> r;
    cout << f(r) - f(l - 1);
}