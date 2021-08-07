#include <iostream>
using namespace std;
int x[10000], y[10000], v[10000];
int main(int argc, const char** argv) 
{
#ifdef DEBUG
    freopen("./P4343/autoac19.in", "rb", stdin);
    freopen("./P4343/tmp.txt", "wb", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n;i++)
    {
        cin >> x[i] >> y[i] >> v[i];
    }
    return 0;
}