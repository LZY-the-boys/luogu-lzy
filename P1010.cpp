#include <iostream>
using namespace std;
string s="";
string fun(int n)
{
    int ans = 0;
    string str = "";
    if (n == 0)
    {
        str = "0";
    }
    else
    {
        while (n)
        {
            string s = "";
            if (n & 1)
            {
                if(ans==1)
                {
                    s = "2";
                }
                else
                {
                    s = "2(" + fun(ans) + ")";
                }
                if (str == "")
                    str = s;
                else
                    str = s + "+" + str;
                //上述逻辑可用：if(x&1)s=(i==1?"2":"2("+run(i)+")")+(s==""?"":"+"+s);替代
            }
            ans++;
            n >>= 1;
        }
    }
    return str;
}
void fun1(int n)
{
    int ans = 0;
    //想正常打出来就必须高->低
    for (int i = 14; i >= 0; i--) //20000=100111000100000 最大15bit
    {
        if ((1<<i)&n)
        {
            if (i == 0)
                cout << "2(0)";
            else if (i == 1)
            {
                cout<<"2";
            }
            else
            {
                cout << "2(";
                fun1(i);
                cout << ")";
            }
            n -= (1 << i);//判断是否还有
            if(n)
                cout << "+";
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    fun1(n);
    return 0;
}
