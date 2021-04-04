// AcWing 1275. 最大数
// 区间查询 O(logN), 单点更改 O(logN)
#include <iostream>
#define ls(p) p << 1
#define rs(p) p << 1 | 1
using namespace std;

const int N = 200006;

struct ST {
    int l, r, mx;
} tr[N<<2];
int n, mod, m;

void build(int p, int l, int r) {
    tr[p].l = l, tr[p].r = r; 
    if(l == r) {tr[p].mx = 0; return ;}
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    tr[p].mx = max(tr[ls(p)].mx, tr[rs(p)].mx);
}

void change(int p, int pos, int val) {
    if(tr[p].l == pos && tr[p].r == pos) {tr[p].mx = val; return ;}
    int mid = (tr[p].l + tr[p].r) >> 1;
    if(pos <= mid) change(ls(p), pos, val);
    else change(rs(p), pos, val);
    tr[p].mx = max(tr[ls(p)].mx, tr[rs(p)].mx);
}

int ask(int p, int x, int y) {
    if(tr[p].l >= x && tr[p].r <= y) return tr[p].mx;
    int res = 0;
    int mid = (tr[p].l + tr[p].r) >> 1;
    if(x <= mid) res = max(res, ask(ls(p), x, y));
    if(y > mid) res = max(res, ask(rs(p), x, y));
    return res;
}

int main() {
    cin >> m >> mod;
    build(1, 1, m);
    int a = 0, cnt = 0;
    while(m--) {
        char op[10]; cin >> op;
        int x;
        if(op[0] == 'A') {
            cin >> x;
            ++cnt;
            change(1, cnt, (x+a) % mod);
        } else {
            cin >> x;
            a = ask(1, cnt-x+1, cnt);
            cout << a << endl;
        }
    }
    return 0;
}