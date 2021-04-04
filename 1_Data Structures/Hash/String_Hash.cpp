// AcWing 841. 字符串哈希 
// O(N) creat hash table, O(1) compare
// If one hash function gives WA, creat another hash, and another so on 
#include <iostream>
#define ull unsigned long long
using namespace std;

const int N = 100006, P = 13331;

char a[N];
ull h[N], pwr[N];
int n, m;

ull getH(int l, int r) {
    return h[r] - h[l-1] * pwr[r-l+1];
} 

int main() {
    cin >> n >> m;
    cin >> (a+1);
    pwr[0] = 1;
    for(int i = 1; i <= n; i ++) pwr[i] = pwr[i-1] * P;
    for(int i = 1; i <= n; i ++) h[i] = h[i-1] * P + a[i];
    while(m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(getH(l1, r1) == getH(l2, r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}
