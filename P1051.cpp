#include <iostream>
#include <algorithm>
using namespace std;
struct per
{
    char name[21];
    int money;
    int id;
} pr[100];
int cmps(per a,per b)
{
    return (a.money == b.money) ? (a.id < b.id) : (a.money > b.money);//手动保证顺序
}
int main(int argc, const char** argv) 
{
    int N;
    cin >> N;
    int g1, g2, g5,total=0;
    char g3, g4;
    for (int i = 0; i < N;i++)
    {
        cin >> pr[i].name;
        pr[i].money = 0;
        pr[i].id = i;
        cin >> g1 >> g2 >> g3 >> g4 >> g5;
        if(g1>80&&g5>=1)
            pr[i].money += 8000;
        if(g1>85&&g2>80)
            pr[i].money += 4000;
        if(g1>90)
            pr[i].money += 2000;
        if(g1>85&&g4=='Y')
            pr[i].money += 1000;
        if(g2>80&&g3=='Y')
            pr[i].money += 850;
        total += pr[i].money;
    }
    sort(pr, pr + N,cmps);
    cout << pr[0].name << endl
         << pr[0].money << endl
         << total << endl;
    return 0;
}