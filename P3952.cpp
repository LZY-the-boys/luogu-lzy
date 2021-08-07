#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int flag = 1;
void err()
{
    flag = 0;
    cout << "ERR" << endl;
}
int main(int argc, char const *argv[])
{
#ifdef DEBUG
    freopen("./P3952/ex_complexity2.in", "rb", stdin);
    freopen("./P3952/10.txt", "wb", stdout);
#endif
    int t;
    string tmpstr;
    char timestr[10] = {0};
    getline(cin, tmpstr);
    t = atoi(tmpstr.c_str());
    while (t--)
    {
        int linenum, i = 0, nocntflag = 1, cnt = 0, cntE = 0, endflag = 1, tc = 0, lc = 0, cmax = 0, cleartc;
        char v;
        char x[4], y[4];
        char vtable[100] = {0};  //lc
        int cntstack[100] = {0}; //tc
        getline(cin, tmpstr);
        sscanf(tmpstr.c_str(), "%d O(%s", &linenum, timestr);
        if (linenum % 2 != 0)
        {
            err();
        }
        for (i = 0; i < linenum; i++)
        {
            getline(cin, tmpstr);
            if (flag)
            {
                if (tmpstr[0] == 'F')
                {
                    if (endflag == 1)
                    {
                        endflag = 0;
                        // if(cntE!=0)
                        //     err();
                        // memset(vtable, 0, sizeof(vtable));
                        cnt = cntstack[tc];
                    }
                    if (endflag == 0)
                    {
                        cntE++;
                        sscanf(tmpstr.c_str(), "F %c %s %s", &v, x, y);
                        //check whether v repeat
                        char *p = vtable;
                        while (*p != 0 && *p != v)
                            p++;
                        if (*p != 0)
                            err();
                        else
                        {
                            *p = v, lc++;
                            //calc the time complex
                            if (nocntflag)
                            {
                                if ((x[0] == 'n' && y[0] != 'n') || (x[0] != 'n' && y[0] != 'n' && atoi(x) > atoi(y))) //O(1)后面无需计算
                                {
                                    nocntflag = 0;
                                    cleartc = tc;
                                }
                                else if (x[0] != 'n' && y[0] == 'n') //O(n)
                                    cnt++;
                                //else O(1)
                            }
                        }
                        // cout << cnt<<endl;
                        cntstack[++tc] = cnt;
                    }
                }
                else if (tmpstr[0] == 'E')
                {
                    if (cntE == 0)
                        err();
                    cntE--;
                    tc--;
                    if (nocntflag ==0&& tc == cleartc) //!
                        nocntflag = 1;
                    vtable[--lc] = 0;
                    if (endflag == 0)
                    {
                        if (cnt > cmax)
                        {
                            cmax = cnt;
                        }
                        endflag = 1;
                    }
                }
            }
        }
        if (flag && cntE != 0)
            err();
        //cmp
        if (flag)
        {
            //max
            cnt = cmax;
            //cout <<"--->"<< cmax << endl;
            if (timestr[0] == '1' && cnt == 0)
                cout << "Yes" << endl;
            else if (timestr[0] != '1')
            {
                int scnt;
                sscanf(timestr, "n^%d)", &scnt);
                if (scnt == cnt)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
            else
                cout << "No" << endl;
        }
        flag = 1;
    }
    return 0;
}
