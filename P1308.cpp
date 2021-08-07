#include <iostream>
#include <string>
using namespace std;
int main()
{
    // char word[15];
    // cin >> word;
    string doc,word;
    getline(cin, word);
    getline(cin, doc);
    int i = 0, cnt = 0, delt = 'a' - 'A',flag=1,ind,k=0,ilast;               //32
    //开头可能有空格,可能不止一个空格
    while (doc[i] == ' ') 
        i++;
    while(word[k]==' ')
        k++;

    
    int iter = 0;
    while(doc[i])
    {
        int j = k;
        ilast = i;
        while (doc[i] != ' ' && doc[i] && word[j] && word[j] != ' ')
        {
            if (!(doc[i] == word[j] || doc[i] > 'Z' && word[j] == doc[i] - delt || doc[i] < 'a' && word[j] == doc[i] + delt))
            {
                break;
            }
            i++, j++;
        }
        if ((doc[i] == ' ' || !doc[i])&& (!word[j]||word[j]==' '))//end!
        {
            cnt++;
            if(flag)
            {
                ind = ilast;
                flag = 0;
            }
            // cout << iter << endl;
        }
        iter++;
        while (doc[i] != ' ' && doc[i] != 0) //notice end of string
            i++;
        while (doc[i] == ' ')
            i++;
    }
    if(cnt) cout << cnt<<" "<<ind;
    else
        cout << -1;

    return 0;
}