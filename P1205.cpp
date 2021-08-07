#include <iostream>
using namespace std;
int n;
char s1[10][10];
bool flag[8];
int main(){
    cin >> n;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> s1[i][j];
        }
    }
    //
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            //顺时针旋转90得到，相当于逆时针转90
            if (!flag[0] && c != s1[n - 1 - j][i] ) {
                flag[0] = true;
            }
            //旋转180
            if (!flag[1] && c != s1[n-1-i][n-1-j]) {
                flag[1] = true;
            }
            //逆时针90
            if (!flag[2] && c != s1[j][n - 1 - i]) {
                flag[2] = true;
            }
            //反射
            if (!flag[3] && c != s1[i][n-1-j]) {
                flag[3] = true;
            }
            //组合
            if (!flag[4] && c != s1[n-1-j][n-1-i]) {
                // i,j -> i,n-1-j -> n-1-j,n-1-i || n-1-i,j || j,i
                flag[4] = true;
            }
            if (!flag[5] && c != s1[n-1-i][j]) {
                flag[5] = true;
            }
            if (!flag[6] && c != s1[j][i]) {
                flag[6] = true;
            }
            if (!flag[7] && c != s1[i][j]) {
                flag[7] = true;
            }
        }
    }
    for (int i = 0; i < 6;i++){
        if (!flag[i]) {
            if (i > 6) cout << i - 1;
            else if (4 <= i && i <= 6) cout << 5;
            else
                cout << i+1;
            return 0;
        }
    }
    cout << 7;
    return 0;
}