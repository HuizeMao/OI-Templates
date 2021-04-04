// AcWing 887. 求组合数 III [N choose K] % P, P must be prime
// 若p是质数，则对于任意整数 1 <= m <= n，有：
//   C(n, m) = C(n % p, m % p) * C(n / p, m / p) (mod p)
// O(Plog(P)), good when n and k is large but p is small
// 可以预处理逆元，或者如果询问小的话直接暴力算组合数【这个模板用暴力】
#include <iostream>
#define ll long long 
using namespace std;

int n, mod;

ll ksm(ll a, ll b) {
    ll res = 1;
    for(; b; b >>= 1) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

ll C(ll a, ll b) {
    if(!a || !b) return 1;
    ll res = 1;
    for(int i = a, j = 1; j <= b; j ++, i --) {
        res = (res * i) % mod;
        ll inv = ksm(j, mod-2);
        res = (res * inv) % mod;
    }
    return res;
}

ll lucas(ll a, ll b) {
    if(a < mod && b < mod) return C(a, b);
    return C(a%mod, b%mod) * lucas(a/mod, b/mod) % mod;
}

int main() {
    cin >> n;
    while(n--) {
        ll a, b; cin >> a >> b >> mod;
        cout << lucas(a, b) << endl;
    }
}