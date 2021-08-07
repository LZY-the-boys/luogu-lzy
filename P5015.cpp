#include <iostream>
#include <string>


using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int cnt = 0;
    /*
        while(a!='\n'){
        a=getchar();
        if(a==' ')continue;
        else ans++;}
    */
    for (int i = 0;i<str.size();i++)
    {
        if(str[i]==' ')
            continue;
        cnt++;
    }
    cout << cnt;
    return 0;
}