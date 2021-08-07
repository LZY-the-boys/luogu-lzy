#include <iostream>
#include <algorithm>
using namespace std;
struct person{
    int id;
    int grade;
} pr[5000];
int cmpp(person a,person b)
{
    return a.grade == b.grade ? (a.id < b.id) : (a.grade > b.grade);
}
int main(int argc, const char** argv) 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n;i++)
    {
        cin >> pr[i].id >> pr[i].grade;
    }
    sort(pr, pr + n,cmpp);
    int level = (int)(1.5 * m);
    int last = 0,cnt=0;
    for (int i = 0;;i++)
    {
        if(pr[i].grade!=last)
        {
            cnt++;
            // m>=3 , level>=4
            if (cnt==level)
            {
                last = pr[i].grade;
            }
            else if (cnt==level+1)
            {
                cout << last <<' '<< i << endl;
                break;
            }
        }
    }
    for (int i = 0; pr[i].grade >= last;i++)
        cout << pr[i].id << ' ' <<pr[i].grade<<endl;
    return 0;
}