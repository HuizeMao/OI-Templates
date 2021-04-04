// AcWing 309. 装饰围栏
// O(N^3)
#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;

const int N = 26;

ll f[N][N][2], m; //f[i][j][0/1] 表示 填前i位数，最后一位填j 并 处于低/高位的cnt
int n, tp, a[N];
bool v[N];

void dp() {
    f[1][1][1] = f[1][1][0] = 1;
    for(int i = 2; i <= 20; i ++) //注意i从2开始
        for(int j = 1; j <= i; j ++) {
            for(int k = 1; k <= j-1; k ++) f[i][j][1] += f[i-1][k][0];
            for(int k = j+1; k <= i; k ++) f[i][j][0] += f[i-1][k-1][1];
                //注意上个阶段k应当排在第k-1位
                //注意 k 上界是i
        }
}

void get_init(int &c, int &pos1) {
    for(int i = 1; i <= n; i ++) {
        if(m > f[n][i][1]) m -= f[n][i][1];
        else {
            pos1 = i, c = 1;
            return ;
        }
        if(m > f[n][i][0]) m -= f[n][i][0];
        else {
            pos1 = i, c = 0;
            return ;
        }
    }
}

void dfs(int p, int lastc, int lasti) {
    int c = lastc^1, pos = 0;
    for(int i = 1; i <= n; i ++) {
        if(v[i]) continue ;
        ++pos; //离散id
        if(lastc && i > lasti) continue ;
        if(!lastc && i < lasti) continue ;
        if(m > f[p][pos][c]) m -= f[p][pos][c];
        else {
            a[++tp] = i, v[i] = 1;
            dfs(p-1, c, i);
            return ;
        }
    }
}

int main() {
    dp(); //DP预处理
    int T; cin >> T;
    while(T--) {
        cin >> n >> m;
        int c, pos1; get_init(c, pos1); //第一位特殊处理
        tp = 0, memset(v, 0, sizeof v);
        v[pos1] = 1, a[++tp] = pos1;
        
        dfs(n-1, c, pos1); //试填法
        for(int i = 1; i <= n; i ++) cout << a[i] << " ";
        puts("");
    }
}