#include <iostream>
using namespace std;
int n;
string str;
string s[5][10] = {{"XXX", "..X", "XXX", "XXX", "X.X", "XXX", "XXX", "XXX", "XXX", "XXX"},
              {"X.X", "..X", "..X", "..X", "X.X", "X..", "X..", "..X", "X.X", "X.X"},
              {"X.X", "..X", "XXX", "XXX", "XXX", "XXX", "XXX", "..X", "XXX", "XXX"},
              {"X.X", "..X", "X..", "..X", "..X", "..X", "X.X", "..X", "X.X", "..X"},
              {"XXX", "..X", "XXX", "XXX", "..X", "XXX", "XXX", "..X", "XXX", "XXX"}};
int main() {
    cin >> n >> str;
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < n-1; i++) {
            int k = str[i] - '0';
            cout << s[j][k]<<'.' ;
            // printf("%s.", s[j][k]); string 不能用printf直接打印 printf("%s",aa.c_str())
        }
        cout << s[j][str[n-1] - '0'] << '\n';
        // printf("%s\n", s[j][n - 1]);
    }
}