// AcWing 243 一个简单的整数问题2
// 区间查询 O(logN), 区间更改 O(logN)
#include <iostream>
#define ll long long
#define ls(p) p << 1
#define rs(p) p << 1 | 1
using namespace std;

const int N = 100006;

struct ST {
    int l, r;
    ll sum, add;
} tr[N<<2];
int n, m, a[N];

void build(int p, int l, int r) {
    tr[p].l = l, tr[p].r = r, tr[p].add = 0;
    if(l == r) {tr[p].sum = a[l]; return ;}
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    tr[p].sum = tr[ls(p)].sum + tr[rs(p)].sum;
}

void spread(int p) {
    if(tr[p].add) {
        tr[ls(p)].add += tr[p].add;
        tr[rs(p)].add += tr[p].add; //有可能修改区间已经有标记了，要在原标记之上处理
        tr[ls(p)].sum += (tr[ls(p)].r - tr[ls(p)].l + 1) * tr[p].add;
        tr[rs(p)].sum += (tr[rs(p)].r - tr[rs(p)].l + 1) * tr[p].add;
        tr[p].add = 0;
    }
}

ll ask(int p, int x, int y) {
    if(tr[p].l >= x && tr[p].r <= y) return tr[p].sum;
    spread(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    ll res = 0;
    if(x <= mid) res += ask(ls(p), x, y);
    if(y > mid) res += ask(rs(p), x, y);
    return res;
}

void change(int p, int x, int y, ll w) {
    if(tr[p].l >= x && tr[p].r <= y) {
        tr[p].add += w; //有可能修改区间已经有标记了，要在原标记之上处理
        tr[p].sum += (tr[p].r - tr[p].l + 1) * w;
        return ;
    }
    spread(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if(x <= mid) change(ls(p), x, y, w);
    if(y > mid) change(rs(p), x, y, w);
    tr[p].sum = tr[ls(p)].sum + tr[rs(p)].sum;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    build(1, 1, n);
    while(m--) {
        char op[10]; cin >> op;
        int x, y; ll w;
        if(op[0] == 'Q'){
            cin >> x >> y;
            cout << ask(1, x, y) << endl;
        } else {
            cin >> x >> y >> w;
            change(1, x, y, w);
        }
    }
}
// Implementation Details:
// When spreading, tr[ls(p)] __+=__ tr[p].add
// But tr[ls(p)].sum += (tr[ls(p)].r - tr[ls(p)].l + 1) * __tr[p].add__


/* Sample
Input
10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4

Output
4
55
9
15
*/