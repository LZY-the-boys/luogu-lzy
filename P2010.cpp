#include <iostream>
using namespace std;
int ymon[13] = {0,10,20,30,40,50,60,70,80,90,1,11,21};
int d31[7] = {1, 3, 5, 7, 8, 10, 12};
int d30[4] = {4,6,9,11};
int main()
{
    int d1, d2;
    cin >> d1 >> d2;
    int cnt = 0;
    int k = 0 ;
    if(d1==d2)
    {
        int tmp1 = d1;
        int tmp2 = d1;
        while(k!=4)
        {
            int l = tmp1 % 10;
            tmp1 = tmp1 / 10;
            int r = tmp2 / 10000000;
            tmp2 = (tmp2 % 10000000) * 10;
            if(l!=r)
            {
                cout << 0 ;
                return 0;
            }
            k++;
        }
        cout << 1;
        return 0;
    }
    else
    {
        int year1 = d1 / 10000;
        int year2 = d2 / 10000;
        int month1 = (d1 / 100) % 100;
        int month2 = (d2 / 100) % 100;
        int day1 = d1 % 100;
        int day2 = d2 % 100;

        for (int x = year1 / 100; x <= year2 / 100;)
        {
            if(x/10==0) 
            {
                x += 10 - x % 10; //首位数字不为零
            }
            else if(x%10<4)
            {
                if(x==13) //31:1,3,5,7,8,10,12
                {
                    for (int j = 0; j < 7;j++)
                    {
                        if ((year1 < ymon[d31[j]] + 100 * x && ymon[d31[j]] + 100 * x < year2) 
                        ||( ymon[d31[j]] + 100 * x == year1 && d31[j] > month1 )
                        || (ymon[d31[j]] + 100 * x == year1 && d31[j] == month1 && x / 10 + (x % 10) * 10 >= day1 )
                        || (ymon[d31[j]] + 100 * x == year2 && d31[j] < month2)
                        || (ymon[d31[j]] + 100 * x == year2 && d31[j] == month2 && x / 10 + (x % 10) * 10 <= day2))
                            cnt++;
                    }
                    x=20;
                }
                else if(x==3)//30
                {
                    for (int j = 0; j < 4;j++)
                    {
                        if ((year1 < ymon[d30[j]] + 100 * x && ymon[d30[j]] + 100 * x < year2) 
                        || (ymon[d30[j]] + 100 * x == year1 && d30[j] > month1) 
                        || (ymon[d30[j]] + 100 * x == year1 && d30[j] == month1 && x / 10 + (x % 10) * 10 >= day1) 
                        || (ymon[d30[j]] + 100 * x == year2 && d30[j] < month2) 
                        || (ymon[d30[j]] + 100 * x == year2 && d30[j] == month2 && x / 10 + (x % 10) * 10 <= day2))
                            cnt++;
                    }
                    x = 10;
                }
                else if(x%10<=2)
                {
                    int dx = x / 10 + (x % 10) * 10;
                    for (int i = 1; i <= 12;i++)//1,3-11
                    {
                         //2-29 =>92200229 是闰年
                        if ((year1 < 100 * x + ymon[i] &&  100 * x + ymon[i]< year2)
                        || (year1==year2&&100 * x + ymon[i]==year1 &&((month1<i&&i<month2)||(month1==month2&&month1==i&&(day1<=dx||dx<=day2))))
                        || (year1!=year2&& ((year1 == 100 * x + ymon[i]) && (month1 < i || (month1 == i && day1 <= dx))) || ((year2 == 100 * x + ymon[i]) && (month2 > i || (month2 == i && day2 >= dx)))))
                        {
                            cnt++;
                            // cout << 100 * x + ymon[i] << ' ' << i << ' ' << dx << endl;
                        }
                    }
                    if(x==92) break;
                    else if(x%10==2)
                    {
                        if(x/10>1)
                            x += 8;//12->13,22->30,32->40,...,82->90
                        else
                            x++;
                    }
                    else
                        x++;//*0->*1->*2
                }
            }
            else //44->50
            {
                x += 10 - x % 10;
            }
        }
    }
    cout << cnt;
    return 0;
}

int i, j, n, m, a, b, c, sum, ans;
int s[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main2()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= 12; i++) //枚举月和日
        for (j = 1; j <= s[i]; j++)
        {
            c = (j % 10) * 1000 +
                (j / 10) * 100 +
                (i % 10) * 10 +
                (i / 10);                  //算出前四位。
            sum = c * 10000 + i * 100 + j; //算出整个日期
            if (sum < n || sum > m)
                continue;
            ans++; //统计
        }
    printf("%d", ans);
    return 0;
}