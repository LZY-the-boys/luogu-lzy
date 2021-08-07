#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int d[] = {10, 8, 10, 9, 10, 9, 10, 10, 9, 10, 9, 10}; //2-29特判
int dayprime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int monthday[39] = {103, 107, 113, 131, 211, 223, 229, 307, 311, 313, 317, 331, 419, 503, 523, 607, 613, 617, 619, 719, 811, 823, 829, 907, 911, 919, 929, 1013, 1019, 1031, 1103, 1117, 1123, 1129, 1213, 1217, 1223, 1229, 1231};

char str[10];
int cnt = 0;
int isprime(int x) //二位质数打表
{
    for (int i = 2; i <= sqrt(x); i++) //i*i<=x
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
    // cout << x << ',';
    // cnt++;
}
void search() //年-日-月打表=>年打表代码过长
{
    for (int k = 1; k < 10000; k++)
        for (int j = 1; j <= 12; j++)
        {
            for (int i = 0; i <= d[j - 1]; i++) //day
            {
                if (isprime(dayprime[i] + j * 100))
                    if (isprime(dayprime[i] + j * 100 + 10000 * k))
                        cout << dayprime[i] + j * 100 + 10000 * k << ',', cnt++;
            }
            //是4的倍数&&不是100的倍数 || 是400的倍数
            if (j == 2 && ((k % 4 == 0 && (k % 100)) || !(k % 400)))
            {
                if (isprime(k * 10000 + 229))
                    cout << k * 10000 + 229 << ',', cnt++;
            }
        }
}

int main()
{
#ifdef DEBUG
    freopen("./tmp2.txt", "wb", stdout);
#endif
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> str;
        int l[4], h[4],flag=1;
        for (int i = 0; i < 4; i++)
        {
            if (str[i] != '-')
                l[i] = h[i] = str[i] - 48, flag = 0;
            else
                l[i] = 0, h[i] = 9; //year \in [1 9999]
        }
        if(flag)
        {
            int uu;
            for (uu= 4; uu < 8;uu++)
            {
                if(str[uu]!='-')
                    break;
            }
            if(uu==8)
            {
                cout << 55157 << endl;
                //return 0;
                continue;
            } //--------
        }
        int cnt = 0;
        for (int j = 0; j < 39; j++)
        {
            int md = monthday[j];
            int i;
            for (i = 7; i >= 4; i--, md /= 10)
            {
                // cout << i << '-' << md % 10<<' ';
                if (str[i] != '-' && str[i] != md % 10 + '0') //!
                    break;
            }

            if (i == 3)
            {
                for (int a = l[0]; a <= h[0]; a++)
                    for (int b = l[1]; b <= h[1]; b++)
                        for (int c = l[2]; c <= h[2]; c++)
                            for (int d = l[3]; d <= h[3]; d++)
                            {
                                int k = a * 1000 + b * 100 + c * 10 + d;
                                if(k!=0)
                                {
                                    if (monthday[j] == 229 )
                                    {
                                        if (((k % 4 == 0 && (k % 100)) || !(k % 400)) && isprime(k * 10000 + 229))
                                            cnt++;
                                    }
                                    else
                                    {
                                        if (isprime(k * 10000 + monthday[j]))
                                            cnt++;
                                    }
                                } 
                            }
            }
        }

        cout << cnt << endl;
    }
}