#include <iostream>
#include <algorithm>
using namespace std;
int h[300];
int main(int argc, const char **argv)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    long long sum = 0;
        sort(h, h + n);
        for (int i = n - 1, j = 0; i > j; )
        {
            sum += (h[i] - h[j]) * (h[i] - h[j]);
            i--;
            sum += (h[i] - h[j]) * (h[i] - h[j]);
            j++;
        }
    sum +=(h[n - 1]) * (h[n - 1]);

    cout << sum;
    return 0;
}