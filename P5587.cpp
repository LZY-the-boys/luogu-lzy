#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1, str2,tmp;
    getline(cin, tmp);//空格
    int pos = 0;
    pos = tmp.find('<', pos);
    while (1)
    {
        if (pos == -1)
            break;
        else if (pos == 0)
        {
            tmp.erase(pos, 1);
            pos = tmp.find('<', pos);
        }
        else
        {
            tmp.erase(pos - 1, 2);
            pos = tmp.find('<', pos-1);//!pos-1
        }
    }
    while(tmp!="EOF")
    {
        str1 +='\t';
        str1 += tmp;
        getline(cin, tmp);
        pos = 0;
        pos = tmp.find('<', pos);
        while (1)
        {
            if (pos == -1)
                break;
            else if(pos == 0)
            {
                tmp.erase(pos, 1);
                pos = tmp.find('<', pos);
            }
            else
            {
                tmp.erase(pos - 1, 2);
                pos = tmp.find('<', pos - 1);
            }
        }
    }

    getline(cin, tmp);
    pos = 0;
    pos = tmp.find('<', pos);
    while(1)
    {
        if (pos == -1)
            break;
        else if (pos == 0)
        {
            tmp.erase(pos, 1);
            pos = tmp.find('<', pos);
        }
        else
        {
            tmp.erase(pos - 1, 2);
            pos = tmp.find('<', pos - 1);
        }
    }

    while (tmp != "EOF")
    {
        str2 += '\t';
        str2 += tmp;
        getline(cin, tmp);
        pos = 0;
        pos = tmp.find('<', pos);
        while (1)
        {
            if (pos == -1)
                break;
            else if (pos == 0)
            {
                tmp.erase(pos, 1);
                pos = tmp.find('<', pos);
            }
            else
            {
                tmp.erase(pos - 1, 2);
                pos = tmp.find('<', pos-1);
            }
        }
    }
    int T,cnt=0;
    cin >> T;
    
    for (int i = 0, j = 0; i < str1.size() && j < str2.size(); i++, j++)
    {
        if(str1[i]=='\t')//按行统计
            while(str2[j]!='\t')
            {
                j++;
            }
        else if (str2[j] == '\t')
            while (str1[i] != '\t')
            {
                i++;
            }
        else if (str1[i] == str2[j])
            cnt++;
    }
    cout << (int)cnt*60 / T;
    return 0;
}