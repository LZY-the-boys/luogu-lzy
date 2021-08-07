#include <iostream>
using namespace std;
int N, M;
int p[1000][1000];
int main(int argc, char const *argv[])
{
    cin >> N >> M;
    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < M;j++)
        {
            cin >> p[i][j];
        }
    }
        return 0;
}
