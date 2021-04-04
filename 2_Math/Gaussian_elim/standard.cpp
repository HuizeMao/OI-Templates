// AcWing 883. 高斯消元解线性方程组
// O(N^3)
// 检查顺序: 1.无解情况 2.自由元（无穷解）3.唯一解
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 106;
const double eps = 1e-8;

int n;
double a[N][N];

int gauss() {
    int r, c; bool flag = 0;
    for(r = 1, c = 1; c <= n; c ++) {
        int t = r;
        for(int i = r + 1; i <= n; i ++)
            if(abs(a[i][c]) > abs(a[t][c])) t = i;
        for(int k = 1; k <= n + 1; k ++) swap(a[t][k], a[r][k]);
        if(abs(a[r][c]) < eps) {flag = 1; continue ;}
        for(int i = 1; i <= n; i ++)
            if(i != r && abs(a[i][c]) > 0) {
                double w = a[i][c] / a[r][c];
                for(int k = 1; k <= n+1; k ++) a[i][k] -= a[r][k] * w;
            }
        ++r;
    }
    for(int i = r; i <= n; i ++)
        if(abs(a[i][n+1]) > eps) return 1;
    if(flag) return 2;
    return 3;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
        cin >> a[i][n+1];
    }
    int d = gauss();
    if(d == 1) puts("No solution");
    else if(d == 2) puts("Infinite group solutions");
    else {
        for(int i = 1; i <= n; i ++)
            printf("%.2lf\n", a[i][n+1] / a[i][i]);
    }
}

// Sample Input
/*
3
1.00 2.00 -1.00 -6.00
2.00 1.00 -3.00 -9.00
-1.00 -1.00 2.00 7.00
*/

// Sample Output
/*
1.00
-2.00
3.00
*/