#include <iostream>
#include <time.h> 
using namespace std;

int a[100000];
// void swap(int &a,int &b)
// {
//     int tmp;
//     tmp=a;
//     a=b;
//     b=tmp;
// }
void quicksort(int l,int r)
{
    if(l<r-1)
    {
        int mid=rand()%(r-l)+l;//!
        swap(a[r-1],a[mid]);
        int j=l-1;
        for(int i=l;i<r-1;i++)
        {
            if(a[i]<=a[r-1])
            {
                j++;
                swap(a[i],a[j]);//!
            }
        }
        //!swap(a[r-1],a[mid]);
        swap(a[j+1],a[r-1]);
        quicksort(l,j+1);
        quicksort(j+2,r);
    } 

}
int main()
{
    #ifdef DEBUG
    freopen("./1.txt","rb",stdin);
    freopen("./2.txt","wb",stdout);
    #endif
    // int b=rand()%1000;
    // for(int i=0;i<100000;i++)
    // {
    //     cout<<b<<' ';
    // }
    ios::sync_with_stdio(false);
    int n;
    srand(time(NULL));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort(0,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
        if(i==n-1) cout<<endl;
        else cout<<' ';
    }
    return 0;
}