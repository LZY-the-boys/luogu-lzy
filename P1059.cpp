#include <iostream>
#include <algorithm>
using namespace std;

int a[10000];
int ahash[1000];
int main()
{
    int n,tmp,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        //method1
        /*
        int j;
        if(i==0) cin>>a[0],cnt++;//!注意和下面不同
        else
        {
            cin>>tmp;
            for(j=0;j<i;j++)
                if(a[j]==tmp) break;
            if(j==i)
            {
                a[cnt]=tmp;//!写成[i]
                cnt++;
            } 
        }*/
        //method2
        cin>>tmp;
        if(ahash[tmp]==0) 
        {
            a[cnt++]=tmp;
            ahash[tmp]++;
        }
    }
    sort(a,a+cnt);
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
//桶排序--其实就是hash。。
int main2(){
    int n,x;
    cin>>n;
    int sum(0),bus[1002]={0};
    for(int i=1;i<=n;i++){
        cin>>x;
        if(bus[x])  //如果这个数已经出现过了，那么跳过
            continue;
        bus[x]++;  //如果没有出现，把数据放在桶里，并让总数居++
        sum++;
    }
    cout<<sum<<endl;
    for(int i=1;i<=1000;i++) //i就是天然的顺序
        if(bus[i])
            cout<<i<<' ';
    cout<<endl;
    return 0;
}