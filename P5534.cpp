#include <iostream>
using namespace std;
int main()
{
    int a1, a2, n;
    cin >> a1 >> a2 >> n;
    int d = a2 - a1;
    cout << (long long)n * a1 + (long long)n * (n - 1) / 2 * d;
    return 0;
}