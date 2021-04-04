// AcWing 837. 连通块中点的数量
#include <iostream>
using namespace std;

const int N = 100006;

struct DS {
    int fa, sz;
} ds[N];
int n, m;

int find(int x) {
    if(ds[x].fa == x) return x;
    return ds[x].fa = find(ds[x].fa);
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) ds[i].fa = i, ds[i].sz = 1;
    while(m--) {
        char op[10]; cin >> op;
        int x, y, gx, gy;
        if(op[0] == 'C') {
            cin >> x >> y;
            gx = find(x), gy = find(y);
            if(gx == gy) continue ;
            ds[gy].fa = gx, ds[gx].sz += ds[gy].sz;
        } else if(op[1] == '1'){
            cin >> x >> y;
            gx = find(x), gy = find(y);
            cout << (gx == gy ? "Yes" : "No") << endl;
        } else {
            cin >> x; gx = find(x);
            cout << ds[gx].sz << endl;
        }
    } 
}

// Implementation details:
// 注意判断如果合并操作  是否多余(x, y已经在同一个集合？), 多余要continue.