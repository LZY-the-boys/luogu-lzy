#include <iostream>
#include <string.h>
#define M4
//两种暴力：9层循环=>P(9,3) = 504
#ifdef M1 //错误程序:不能包括零 轮数少但是比较次数多
int main()
{
    for (int i = 100; i <= 333; i++)
    {
        int x = i / 100, y = (i / 10) % 10, z = i % 10;
        if (x == y || y == z || z == x)
            continue;
        int u = 2 * i / 100, v = (2 * i / 10) % 10, w = 2 * i % 10;
        if (u == v || v == w || w == u || u == x || u == y || u == z || v == x ||
            v == y ||
            v == z ||
            w == x ||
            w == y ||
            w == z)
            continue;
        int r = 3 * i / 100, s = (3 * i / 10) % 10, t = 3 * i % 10;
        if (r == s || s == t || t == r || r == x ||
            r == y ||
            r == z ||
            s == x ||
            s == y ||
            s == z ||
            t == x ||
            t == y ||
            t == z ||
            r == u ||
            r == v ||
            r == w ||
            s == u ||
            s == v ||
            s == w ||
            t == u ||
            t == v ||
            t == w)
            continue;
        std::cout << i << " " << 2 * i << " " << 3 * i << std::endl;
    }
    return 0;
}
#endif
#ifdef M2 //积 - 优雅
int main()
{
    int a, b, c, e;

    for (int i = 123; i <= 329; i++) //根据运算结果还可以优化192-327。
    {
        long int d = 1;
        for (e = i; e <= 3 * i; e += i)
        {
            a = e / 100;
            b = (e - 100 * (e / 100) - e % 10) / 10;
            c = e % 10;
            d *= a * b * c;
        }
        //或：a/100+a/10%10+a%10+b/100+b/10%10+b%10+c/100+c/10%10+c%10==1+2+3+4+5+6+7+8+9)&&((a/100)*(a/10%10)*(a%10)*(b/100)*(b/10%10)*(b%10)*(c/100)*(c/10%10)*(c%10)==(1)*(2)*(3)*(4)*(5)*(6)*(7)*(8)*(9)))
        if (d == 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9) //保证只能是1,2,...,9
            printf("%d %d %d\n", i, 2 * i, 3 * i);
    }
    return 0;
}

#endif
#ifdef M3 //flag
int i, j, v;
bool a[10]; //ai表示第i个数已经用过了
int main()
{
    for (i = 192; i <= 327; i++) 
    {
        memset(a, 0, sizeof(a));
        v=0;//清零
        a[i % 10] = a[i / 10 % 10] = a[i / 100] = a[i * 2 % 10] = a[i * 2 / 10 % 10] = a[i * 2 / 100] = a[i * 3 % 10] = a[i * 3 / 10 % 10] = a[i * 3 / 100] = 1; //统计数字
        for (j = 1; j <= 9; j++)
            v += a[j]; //v表示1-9这些数字是否全部齐了
        if (v == 9)
            printf("%d %d %d\n", i, i * 2, i * 3); //如果齐了就输出
    }
    return 0;
}
#endif
#ifdef M4 //flag-二进制
int main()
{
    for (int i = 192; i <= 329; i++)
    { //枚举A最多329c
        int p = i, j = i << 1, k = i * 3, t = 0;
        while (p) //出现0该轮作废
            t |= 1 << p % 10 - 1, p /= 10; //t的（p%10）位=1
        while (j)
            t |= 1 << j % 10 - 1, j /= 10; 
        while (k)
            t |= 1 << k % 10 - 1, k /= 10;
        if ((t & 511) == 511)//1_1111_1111B = 511D
            printf("%d %d %d\n", i, i << 1, i * 3); //也就是都匹配到了
    }
    return 0;
}
#endif