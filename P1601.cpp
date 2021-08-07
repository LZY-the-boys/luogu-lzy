#include <iostream>
using namespace std;
#define DIV
#ifdef ADD
string uadd(string &a, string &b)
{
    string s;
    int la = a.length();
    int lb = b.length();
    if (la < lb) //补零，以便长度相同
    {
        for (int i = 1; i <= lb - la; i++)
            a = "0" + a;
    }
    else
    {
        for (int i = 1; i <= la - lb; i++)
            b = "0" + b;
    }
    int l = a.length(); //更新长度
    int tmp, c = 0;     //进位
    for (int i = l - 1; i >= 0; i--)
    {
        tmp = a[i] - '0' + b[i] - '0' + c;
        c = tmp / 10;
        tmp %= 10;
        s = char(tmp + '0') + s;
    }
    if (c)
        s = char(c + '0') + s;
    return s;
}
#endif
//========================================================
#ifdef SUB
string usub(string &a, string &b) //a>b 重点是借位的逻辑,和前导零的处理
{
    int tmp, c = 0; //进位
    string s = "";
    int la = a.size(), lb = b.size();
    for (int i = 0; i < la; i++)
    {
        int ib = lb - 1 - i;
        int ia = la - 1 - i;
        if ( (ib<0&&a[ia]<'0') || (ib>=0&& b[ib] > a[ia]))
        {
            a[ia-1] --;
			a[ia] += 10;
        }
        if(ib<0)
            tmp = a[ia]-'0';
        else tmp = a[ia]-b[ib];
        s = char(tmp+'0') + s;
    }
    int ls = 0;
    while (s[ls] == '0'&& ls!=la-1)
        ls++;
    return s.substr(ls);
}

string sub(string &a, string &b) //a,b为正，结果包括负数,重点逻辑在处理负数
{
    string s;
    int la = a.length();
    int lb = b.length();
    if (la < lb || (la == lb && b > a)) //a<b string可以相互比较！
    {
        return "-" + usub(b, a);
    }
    else //a>b
    {
        return usub(a, b);
    }
}
#endif
//==============================================================
#ifdef MUL
int c[10001]={0};
void mul(string a,string b)
{
    //string s = "";
    int la = a.length();
    int lb = b.length();
    for (int i = la - 1; i >= 0; i--)
        for (int j = lb - 1; j >= 0; j--)
        {
            c[i + j + 1] += (a[i] - '0') * (b[j] - '0'); //6*4 所以开头必须留一个空
        }
    for (int i = la + lb - 1; i >= 0; i--)
    {
        if (c[i] > 9)
            c[i - 1] += c[i] / 10, c[i] = c[i] % 10;
    }
    //去零：
    int len = la + lb - 1, i = 0;
    while (c[i] == 0 && len != i) //防止结果为0的情况
        i++;
    for (; i <= len; i++)
        //s.push_back(c[i] + '0');
        cout << c[i];
    //return s;
}
#endif
//=====================================================
#ifdef DIV
string ddiv(string a,int b) //a=0,b=1,输出商的整数部分即可
{
    int la = a.size(),d=0;
    string s="";
    for (int i = 0; i < la;i++)
    {
        s.push_back(((long long)d * 10 + a[i] - '0') / b + '0');//!longlong
        d = ((long long)(d * 10 + a[i] - '0')) % b;
        // cout << (((long long)d * 10 + a[i] - '0') / b + '0') << ' ' << d << ' ' << s << endl;
    }
    int i = 0;
    while(s[i]=='0'&& i<la-1)
        i++;
    return s.substr(i);
}
int compare(string str1,string str2)
{
    int res;
    if (str1.length() > str2.length())
        res = 1;
    else if (str1.length() < str2.length())
        res = -1;
    else
    {
        if (str1 < str2)
        {
            res = -1;
        }
        else if (str1 == str2)
        {
            res = 0;
        }
    }
    return res;
}
/*
void div(string str1, string str2, string &quotient, string &residue)
{
    quotient = residue = ""; //清空
    if (str2 == "0")         //判断除数是否为0
    {
        quotient = residue = "ERROR";
        return;
    }
    if (str1 == "0") //判断被除数是否为0
    {
        quotient = residue = "0";
        return;
    }
    int res = compare(str1, str2);

    if (res==-1)
    {
        quotient = "0";
        residue = str1;
        return;
    }
    else if (res==0)
    {
        quotient = "1";
        residue = "0";
        return;
    }
    else //str1> str2
    {
        int len1 = str1.length();
        int len2 = str2.length();
        string tempstr;
        tempstr.append(str1, 0, len2 - 1);
        for (int i = len2 - 1; i < len1; i++)
        {
            tempstr = tempstr + str1[i];
            tempstr.erase(0, tempstr.find_first_not_of('0'));
            if (tempstr.empty())
                tempstr = "0";
            for (char ch = '9'; ch >= '0'; ch--) //试商
            {
                string str, tmp;
                str = str + ch;
                tmp = mul(str2, str);
                if (compare(tmp, tempstr) <= 0) //试商成功
                {
                    quotient = quotient + ch;
                    tempstr = sub(tempstr, tmp);
                    break;
                }
            }
        }
        residue = tempstr;
    }
    quotient.erase(0, quotient.find_first_not_of('0'));
    if (quotient.empty())
        quotient = "0";
}
*/
#endif
int main()
{
#ifdef STRING2
    //如何读进来-string
    string str1, str2;
    cin >> str1 >> str2;
#else
    string a;
    int b;
    cin >> a >> b;
#endif
#ifdef ADD
    cout << uadd(str1, str2);
#endif
#ifdef SUB
    cout<<sub(str1, str2);
#endif
#ifdef MUL
    mul(str1, str2);
#endif
#ifdef DIV
    cout<<ddiv(a, b);
#endif
    return 0;
}