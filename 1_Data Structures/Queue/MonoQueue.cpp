// AcWing 154. 滑动窗口
// O(1) 弹栈顶, 入栈, 查询栈顶
#include <iostream>
using namespace std;

const int N = 1000006;

int qmx[N], qmn[N], lmx, lmn, rmx, rmn;
int n, m, a[N], ans1[N], ans2[N];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    lmx = lmn = 1, rmx = rmn = 0;
    for(int i = 1; i <= n; i ++) {
        while(lmx <= rmx && qmx[lmx] <= i-m) ++lmx;
        while(lmx <= rmx && a[qmx[rmx]] <= a[i]) --rmx;
        qmx[++rmx] = i;
        
        while(lmn <= rmn && qmn[lmn] <= i-m) ++lmn;
        while(lmn <= rmn && a[qmn[rmn]] >= a[i]) --rmn;
        qmn[++rmn] = i;
        
        ans1[i] = a[qmn[lmn]];
        ans2[i] = a[qmx[lmx]];
    }
    for(int i = m; i <= n; i ++) cout << ans1[i] << " ";
    puts("");
    for(int i = m; i <= n; i ++) cout << ans2[i] << " ";
}

// Implementation Details:
// q[i] 存的是下标, a[q[i]] 才是对应的值
