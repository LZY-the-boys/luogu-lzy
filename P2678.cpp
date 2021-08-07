#include <iostream>
#include <algorithm>
using namespace std;

struct stone
{
    int l;
    int id;
} s[50001];
int cmps(stone a, stone b)
{
    return (a.l == b.l) ? (a.id < b.id) : (a.l < b.l);
}
void main1()
{
#ifdef DEBUG
    freopen("./P2678/stone3.in", "rb", stdin);
    freopen("./P2678/tmp.txt", "wb", stdout);
#endif
    int L, M, N, distance, lastdistance = 0;
    cin >> L >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> distance;
        s[i].l = distance - lastdistance;
        s[i].id = i;
        lastdistance = distance;
    }
    s[N].l = L - distance, s[N].id = N;
    int sc = 0;
    while (sc < M)
    {
        sort(s + sc, s + N + 1, cmps);
        if (s[sc].id == N) //删第N个前面那个而不是第N个
        {
            int max = 0;
            for (int i = sc + 1; i <= N; i++)
            {
                if (s[i].id > max)
                    max = s[i].id;
            }
            s[sc].l += s[max].l;
            s[max] = s[sc]; //max删除
        }
        else
            s[s[sc].id + 1].l += s[sc].l;
        sc++;
        // for (int i = 0; i < N+1; i++)
        // {
        //     cout << s[i].id << ":" << s[i].l << endl;
        // }
    }
    cout << s[sc].l;
}
int L, M, N;
int a[50000];
int cnt(int step) //计数需要删除的石头数目
{
    int sc = 0,last=0;
    for (int i = 0; i < N; i++)
    {
        if (a[i]-last<step)
            sc++;
        else
            last = a[i];
    }
    if(L-last<step)
        sc++;
    return sc;
}
#define M1
void main2()
{
#ifdef DEBUG
    freopen("./P2678/stone5.in", "rb", stdin);
    //freopen("./P2678/tmp.txt", "wb", stdout);
#endif
    cin >> L >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
#ifdef graph
    for (int i = 1; i <= L;i++)
    {
        cout << cnt(i) << endl;
    }
#endif
#ifdef M1
    int l = 1, r = L,mid;
    while (r > l) //终止条件r==l
    {
        mid = (l + r + 1 ) / 2;
        //mid = (l + r ) / 2;卡在[1881198 1881199]
        if (cnt(mid)<=M) //这里l代表最大的i使得cnt(mid)<=M，实现由mid完成。
            l = mid;
        else
            r = mid-1;
        //r = mid;卡在[1881199 1881200]
        cout <<"["<< l << ' ' << r <<"]"<< endl;
    }
    //[1881199 1881201]->[1881199 1881199]->1881199
    cout <<"result:"<< l;
#endif
#ifdef M2
    int left = 1, right = L;

    while (left < right) //[1881200 1881200]结束
    {
        int mid = (left + right) / 2;
        if (cnt(mid) == M)
        {
            left = mid + 1; // left代表cnt(i)==M中最大的i+1
        }
        else if (cnt(mid) < M)
        {
            left = mid + 1;
        }
        else if (cnt(mid) > M)
        {
            right = mid;
            //right = mid - 1; //输出错误结果,在[1881199 1881199]处结束
        }
        cout << "[" << left << ' ' << right << "]" << endl;
    }
    cout<< "result:"<<left - 1; // 注意
#endif
}
int main()
{
    main2();
    return 0;
}