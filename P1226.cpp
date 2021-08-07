#include <iostream>
using namespace std;
int quickpower(int a,int b) //$a^b$
{
    int ans = 1, base =a;
    while (b>0)
    {
        if (b & 1)
            ans *= base; // $a^(2^n)$
        base *= base;
        b >>= 1;
    }
    return ans;
}

int quickpowermod(int a,int b,int m)
{
    int ans = 1, base = a;//兼顾了b=0的情况
    while(b>0)
    {
        if(b&1)
            ans = ((long long)ans*base)%m;
        base = ((long long)base*base) %m;//=(base*base)%m
        b >>= 1;
    }
    return ans%m;
}
int main(int argc, const char** argv) {
    int b, p, k;
    cin >> b >> p >> k;

    cout << b<<"^"<<p<<" mod "<<k<<"="<< quickpowermod(b, p, k);
    return 0;
}