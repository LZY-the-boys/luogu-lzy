#include <iostream>
#include <algorithm>
using namespace std;
int N, C;
int x[100000];
int f(int d, int j)
{
    int cnt = 1, last = x[j]; //!cnt=1
    for (int j = 1; j < N; j++)
    {
        if (x[j] - last >= d)
        {
            cnt++;
            last = x[j];
        }
    }
    return cnt;
}
int f1(int d)
{
    int cnt = 1, last = x[0]; //!cnt=1
    for (int j = 1; j < N; j++)
    {
        if (x[j] - last >= d)
        {
            cnt++;
            last = x[j];
        }
    }
    return cnt;
}
void main1()
{
#ifdef D
    freopen("./txt.txt", "wb", stdout);
    freopen("./P1824_3.in", "rb", stdin);
#endif
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }
    sort(x, x + N); //!
    int fmax = 0;
    for (int i = 0; i < N - C + 1; i++)//!bug: i接近N-C的时候即使f没有达到C也会退出循环。
    //! i大于24的时候就已经不可能超过C！这里需要一个不存在的判断
    {
        int l = i, r = x[N - 1];
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (f(mid, i) == C)
                l = mid + 1;
            else if (f(mid, i) < C)
                r = mid;
            else
                l = mid + 1;
            //cout << "[" << l << ' ' << r << ']' << endl;
        }
        // cout<< f(l-1,i) <<endl;
        if (f(l-1,i)>=19|| l - 1 > fmax )
            fmax = l - 1;
    }
    cout <<fmax;
}
void main2()
{
#ifdef D
    freopen("./txt.txt", "wb", stdout);
    freopen("./P1824_3.in", "rb", stdin);
#endif
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }
    sort(x, x + N); //!

    int fmax = 0;
    int l = 1, r = x[N - 1] - x[0];
    while (l < r)
    {
        int mid = (l + r) / 2;
        //cout << "f:"<<f(mid,i) << endl;
        if (f1(mid) == C)
            l = mid + 1;
        else if (f1(mid) < C)
            r = mid;
        else
            l = mid + 1;
        //cout << "[" << l << ' ' << r << ']' << endl;
    }

    cout << l - 1;
}
int main(int argc, char const *argv[])
{
    main1();
    return 0;
}
