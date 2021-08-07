#include <iostream>
#include <cstring>
long long N,l,t;
char str[31];
using namespace std;
int main(int argc, char const *argv[])
{
    cin >> str+1;
    cin >> N;
    l = t =strlen(str+1);
    while(t<N)
        t <<= 1;
    while(t > l)
    {
        t >>= 1;
        //前半段
        if(N<=t)
            continue;
        //后半段
        else if(t==N-1)
            N = t;
        else
            N -= t + 1;
    }
    cout << str[N];
    return 0;
}
