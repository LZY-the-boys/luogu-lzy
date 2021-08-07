#include <iostream>
using namespace std;
double a, b, c, d;
double f(double x)
{
    // return a * x ^ 3 + b * x ^ 2+c * x + d;
    return a * x *x*x + b * x *x + c * x + d;
}

double midsearch(double l, double r) //二分查找
{
    if (f(r) < 0.0000001 && f(r) > -0.0000001)
        return r;
    if (f(l) < 0.0000001 && f(l) > -0.0000001)
        return l;
    double mid = (r + l) / 2;
    if(r-l<0.0005)
        return mid;//!
    if ((double)f(l) * f(mid) <= 0)
        return midsearch(l,mid);
    else //if(f(r)*f(mid)<=0)
        return midsearch(mid,r);
    //else
}
int main()
{
    cin >> a >> b >> c >> d;
    double last=112;
    for (double i = -100; i <= 100; i += 0.5)
    {
        // cout << i <<" "<< f(i) << endl;
        double r=111;
        if (f(i) < 0.0000001 && f(i) > -0.0000001)
            r = i;
        if((double)f(i)*f(i+0.5)<0)//避免重复
        {
            // cout << f(i) << ' ' << f(i+0.5) <<endl;
            r = midsearch(i, i + 0.5);
        }
        if (r != 111 && r != last)
            printf("%.2lf ", r), last = r;
    }
    return 0;
}