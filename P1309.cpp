#include <iostream>
#include <algorithm>
using namespace std;

struct per
{
    int grade;
    int w;
    int id;
} p[200000], win[100000], lose[100000];

int cmpg(per a, per b)
{
    return (a.grade== b.grade?(a.id<b.id):a.grade>b.grade); //总分相同的，约定编号较小的选手排名靠前
}

void merge1(int N)
{
    int i=0, j=0,k=0;
    while (k < 2 * N)
    {
        if (i == N )
            while (j != N )
            {
                p[k++] = lose[j++];
                break;
            }
        else if(j==N)
            while(i!=N)
            {
                p[k++] = win[i++];
                break;
            }
        if (cmpg(win[i], lose[j]))
            p[k++] = win[i++];
        if (i != N)
            if (cmpg(lose[j], win[i]))
                p[k++] = lose[j++];
    }
}

void merge(int N)
{
    int i = 0, j = 0, k = 0;//win-lose-a
    while(i<N&&j<N)
    {
        if (cmpg(win[i], lose[j]))
            p[k++] = win[i++];
        else
            p[k++] = lose[j++];
    }
    while(i<N)
        p[k++] = win[i++];
    while(j<N)
        p[k++] = lose[j++];
}

int main1(int argc, char const *argv[])
{

    int N, R, Q;
    cin >> N >> R >> Q;
    for (int i = 0; i < 2 * N; i++)
    {
        p[i].id = i+1;
        cin >>p[i].grade;
    }
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> p[i].w;
    }
    while (R--)
    {
        sort(p, p + 2 * N, cmpg);
        for (int i = 0; i < N; i++)
        {
            if (p[2 * i].w > p[2 * i + 1].w)
                p[2 * i].grade++;
            else
                p[2 * i + 1].grade++;
        }
    }
    sort(p, p + 2 * N, cmpg);//快排tle
    cout << p[Q - 1].id;
    return 0;
}

int main(int argc, char const *argv[])
{
#ifdef DEBUG
    freopen("./P1309/2.in", "rb", stdin);
    //freopen("./P1309/tmp.txt", "wb", stdout);
#endif
    int N, R, Q;
    cin >> N >> R >> Q;
    for (int i = 0; i < 2 * N; i++)
    {
        p[i].id = i + 1;
        cin >> p[i].grade;
    }
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> p[i].w;
    }
    sort(p, p + 2 * N, cmpg);//第一次是无序的
    while (R--)
    {
        for (int i = 0; i < N; i++)
        {
            if (p[2 * i].w > p[2 * i + 1].w)
            {
                p[2 * i].grade++;
                win[i] = p[2 * i];//!
                lose[i] = p[2 * i+1];
            }
            else
            {
                p[2 * i + 1].grade++;
                lose[i] = p[2 * i];
                win[i] = p[2 * i+1];
            }
        }
        merge(N);
    }
    cout << p[Q - 1].id;
    return 0;
}
