#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int N,i,x,y;
    cin>>N;
    i = floor((sqrt(8 * (N-1) + 1) - 1) / 2);//注意
    int s = i * (i + 1) / 2;
    //cout << i <<":"<< s << endl;
    if(i%2) x = (N - s), y = i+2 - (N - s);
    else
        x = i +2- (N - s), y = (N - s);
    cout << x << "/" << y;
    return 0;
}