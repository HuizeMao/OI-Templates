// AcWing 893. 集合-Nim游戏
// 搞清楚操作和局面，由此设计SG函数, 接下来再NIM一下就可以了
// O(N)
#include <iostream>
#include <cstring>
using namespace std;

const int N = 10006;

int sg[N], a[N], op[N];
bool v[N];
int n, m;

int SG(int x) {
    if(v[x]) return sg[x];
    int mex[N]; memset(mex, 0, sizeof mex);
    for(int i = 1; i <= n; i ++) 
        if(x-op[i] >= 0) mex[SG(x-op[i])] = 1;
    int p = 0; while(mex[p]) ++p;
    v[x] = 1;
    return sg[x] = p;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> op[i];
    cin >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> a[i];
        a[i] = SG(a[i]);
    }
    int res = a[1];
    for(int i = 2; i <= m; i ++)
        res ^= a[i];
    cout << (res ? "Yes" : "No") << endl;
}

// Sample Input:
/*
21
113 42 249 102 203 238 250 162 210 196 101 166 297 294 73 191 105 70 95 169 157 
30
151 158 100 274 178 241 276 164 81 167 274 45 184 236 122 210 282 56 188 130 3 219 111 3 22 221 133 122 41 250
*/

// Sample output:
// yes