// AcWing 886. 求组合数 II [N choose K] % mod 
// O(NlogN), binomial coef. formula + Modular Multiplicative Inverse
// 乘法逆元(b^-1)是一个值, 这个值=(1/b) % mod
// 根据费马小定理, inv(a) = a^(p-2), p is prime, a and p are coprime, a < p
// only applicable when [moding] a number
#include <iostream>
#define ll long long 
using namespace std;

const int N = 100006, mod = 1e9 + 7;

ll jc[N], invjc[N];
int n;

ll ksm(ll a, ll b) {
    ll res = 1;
    for(; b; b >>= 1) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

void constr_jc_invjc() {
    jc[0] = invjc[0] = 1;
    for(int i = 1; i <= N-6; i ++) {
        jc[i] = (jc[i-1] * i) % mod;
        ll inv = ksm(i, mod - 2);
        invjc[i] = (invjc[i-1] * inv) % mod;
    }
}

int main() {
    cin >> n;
    constr_jc_invjc();
    while(n--) {
        int a, b; cin >> a >> b;
        ll res = jc[a];
        res = (res * invjc[a-b]) % mod;
        res = (res * invjc[b]) % mod;
        cout << res << endl;
    }
}
// Sample Input:
/*
*/
/* Sample Output
3
10
1
*/