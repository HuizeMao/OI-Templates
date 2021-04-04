// AcWing 1319. 移棋子游戏
// 定理： 设G1, G2, …, Gm 是m个有向图游戏。定义有向图游戏G，它的行动规则是任选某个有向图游戏Gi，并在Gi上行动一步。G被称为有向图游戏G1, G2, …, Gm的和。
// 有向图游戏的和的SG函数值等于它包含的各个子游戏SG函数值的异或和，即：
// SG(G) = SG(G1) ^ SG(G2) ^ … ^ SG(Gm)
// 如SG(G) > 0, 先手必胜， 否则必败
// O(N)
#include <iostream>
#include <cstring>
using namespace std;

const int N = 2006, M = 6006;

int Head[N], Ver[M], Nxt[M], tot;
int n, m, k;
int sg[N], a[N];
bool v[N];

inline void add(int u, int v) {
    Ver[++tot] = v, Nxt[tot] = Head[u], Head[u] = tot;
}

int SG(int x) {
    if(v[x]) return sg[x];
    int mex[N]; memset(mex, 0, sizeof mex);
    for(int i = Head[x]; i; i = Nxt[i]) {
        int y = Ver[i];
        mex[SG(y)] = 1;
    }
    int p = 0; while(mex[p]) ++p;
    v[x] = 1;
    return sg[x] = p;
}

int main() {
    cin >> n >> m >> k;
    while(m--) {
        int u, v; cin >> u >> v;
        add(u, v);
    }
    for(int i = 1; i <= k; i ++) {
        cin >> a[i];
        a[i] = SG(a[i]);
    }
    int res = a[1];
    for(int i = 2; i <= k; i ++)
        res ^= a[i];
    cout << (res ? "win" : "lose") << endl;
}

// Sample Input:
/*
6 8 4
2 1
2 4
1 4
1 5
4 5
1 3
3 5
3 6
1 2 4 6
*/

// Sample output:
// win