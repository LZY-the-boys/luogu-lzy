#include <iostream>
using namespace std;
/*
在一局比赛中，先得11分的一方为胜方；
比分出现10平后，先多得2分的—方为胜方。
十一分制中一定要有一人达到十分后，领先2分，才算胜方。
如14:15不行，8:5也不行，但11:13是13分的为胜方。
*/
int result[10000][2];
int main(int argc, char const *argv[])
{
    char c;
    int cntW = 0, cntL = 0;//11
    int cntW21 = 0, cntL21 = 0,tmpcnt=0;
    while(cin>>c&&c!='E')
    {
        if(c=='W')
        {
            cntW++;
            cntW21++;
        }
        else if(c=='L')
        {
            cntL++;
            cntL21++;
        }
        if ((cntW > cntL+1 && cntW>= 11)||(cntL>cntW+1 && cntL>=11))
        {
            cout << cntW << ':' << cntL<<endl;
            cntW = cntL = 0;
        }
        if ((cntW21 > cntL21 + 1 && cntW21 >= 21) || (cntL21 > cntW21 + 1 && cntL21 >= 21))
        {
            result[tmpcnt][0] = cntW21;
            result[tmpcnt][1] = cntL21;
            cntW21 = cntL21 = 0;
            tmpcnt++;
        }
    }
    cout << cntW << ":" << cntL<<endl<<endl;
    for (int i = 0; i < tmpcnt;i++)
    {
        cout << result[i][0] << ':' << result[i][1] << endl;
    }
    cout << cntW21 << ":" << cntL21;
    return 0;
}
