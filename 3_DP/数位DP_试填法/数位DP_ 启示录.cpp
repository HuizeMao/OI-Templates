// 以数位为阶段的线性DP预处理 + 试填法
// DP O(10), 试填 O(10*10), O(N)
#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;

const int N = 26;

ll f[N][6], pwr[N];
int n, d, a[N], tp;

void dp() {
    f[0][0] = 1;
    for(int i = 1; i <= 13; i ++) {
        for(int j = 1; j <= 3; j ++) f[i][j] = f[i-1][j-1];
        f[i][3] += f[i-1][3] * 10;
        f[i][0] = (f[i-1][0]+f[i-1][1]+f[i-1][2]) * 9;
    }
}

int get_d() {
    int res = 3;
    while(f[res][3]-f[res-1][3] < n) n -= (f[res][3]-f[res-1][3]), ++res;
    return res;
}

ll calc(int i, int p, int x) {
    if(x == 3) return pwr[p-1];
    ll res = f[p-1][3];
    if(i == 6) {
        if(x == 0) res += f[p-1][2];
        if(x == 1) res += f[p-1][1] + f[p-1][2];
        if(x == 2) res = pwr[p-1];
    }
    return res;
}

void dfs(int p, int numlast) {
    if(!p) return ;
    int st = p == d ? 1 : 0;
    for(int i = st; i <= 9; i ++) {
        ll w = calc(i, p, numlast);
        if(w < n) n -= w;
        else {
            a[++tp] = i;
            int tmp = numlast == 3 ? 3 : (i == 6 ? numlast + 1 : 0);
            dfs(p-1, tmp); 
            return ; //注意试填过后直接返回
        }
    }
}

int main() {
    // freopen("data.in", "r", stdin);
    pwr[0] = 1;
    for(int i = 1; i <= 14; i ++) pwr[i] = pwr[i-1] * 10;
    dp();
    int T; cin >> T;
    while(T--) {
        cin >> n;
        d = get_d();
        tp = 0, dfs(d, 0);
        for(int i = 1; i <= tp; i ++) cout << a[i];
        puts("");
    }
}