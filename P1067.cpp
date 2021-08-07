#include <iostream>
using namespace std;

int main()
{
    int n,tmp;
    string p="";
    cin >> n;
    for (int i = 0; i <= n;i++)
    {
        cin >> tmp;
        if(tmp!=0)
        {
            if (i == n)
            {
                if(tmp>0)
                    p += "+";
                p += to_string(tmp);
            }
            else if(i==n-1)
            {
                if(tmp>0)
                {
                    p += "+";
                    if(tmp!=1)
                        p += to_string(tmp);
                    p += "x";
                }
                else if(tmp<0)
                {
                    if(tmp!=-1)
                        p += to_string(tmp);
                    else
                        p += "-";
                    p += "x";
                }
            }
            else if(tmp<0)
            {
                if(tmp!=-1)
                    p += to_string(tmp);
                else 
                    p += "-";
                p += "x^" + to_string(n - i);
            }
            else if(tmp>0)
            {
                if(p!="")  p += "+";
                if (tmp != 1)
                    p += to_string(tmp);
                p += "x^" + to_string(n - i);
            }
        }
    }
    cout << p;
    return 0;
}