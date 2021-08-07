// n->n-3对角线
// n=3: 0
// n=4: 1
// 任意三条对角线不会交于一点
// n=5: 1+2+2 可以新连4-2
// n=6: 5+3+4+3=15  可以新连5-2
// n=7: 12+4+6+6+4=35
// n=8: 32+5+8+9+8+5
//     8 = 4+4
//     9 = 3+3+3
// n = k: fk-1+k-3+2*(k-4)+3*(k-5)+...2*(k-4)+k-3  后面共k-3项
#include <iostream>
using namespace std;
//
int main1() {
    int n;
    cin >> n;
    int fk = 0;
    for (int k = 3; k <= n; k++) {
        int i = 0;
        while(i<k-3){
            int dk = (i/2 + 1) * (k - 3 - i/2);
            fk += dk;
            if(++i<k-3){
                fk += dk;
                ++i;
            }
        }
    }
    cout << fk;
    return 0;
}
//
int main2() {
    int n;
    cin >> n;
    long long fk = 0;
    for (int k = 3; k <= n; k++) {
        int i = 0;
        while (i < k - 3) {
            int dk = (i / 2 + 1) * (k - 3 - i / 2);
            fk += dk;
            if (++i < k - 3) {
                fk += dk;
                ++i;
            }
        }
    }
    cout << fk;
    return 0;
}
//
int main(){
    int n;
    cin >> n;
    long long ans = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4; //n * (n-1) * (n-2) * (n-3) / 24 可能会爆，写成这样就好 
    // 一定除得尽的
    /*
    首先n和n-1一定有一个是２的倍数，因此２可以除尽，
同理n,n-1,n-2中一定有一个是３的倍数，因此３可以除尽（除掉２只会消除因数２而对３没有影响）
同理４也可以除尽
    */
    cout << n;
    return 0;
}
