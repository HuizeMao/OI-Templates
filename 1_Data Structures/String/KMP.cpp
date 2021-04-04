// AcWing 831. KMP字符串
// O(n) 匹配nxt, O(n) 匹配两个字符串
#include <iostream>
using namespace std;

const int N = 1000006;

char a[N], b[N];
int nxt[N];
int n, m, ans[N], tp;

int main() {
    cin >> n >> (a+1);
    cin >> m >> (b+1);
    for(int i = 2, j = 0; i <= n; i ++) {
        while(j && a[j+1] != a[i]) j = nxt[j];
        if(a[j+1] == a[i]) ++j;
        nxt[i] = j;
    }
    for(int i = 1, j = 0; i <= m; i ++) {
        while(j && a[j+1] != b[i]) j = nxt[j];
        if(a[j+1] == b[i]) ++j;
        if(j == n) ans[++tp] = i - n;
    }
    for(int i = 1; i <= tp; i ++) cout << ans[i] << " ";
}

// Implementation details:
// nxt[1] = 0