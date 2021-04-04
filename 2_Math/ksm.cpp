//  AcWing 875. 快速幂
// A^B % C, O(log B)
#include <iostream>
#define ll long long 
using namespace std;

ll ksm(ll a, ll b, ll mod) {
    ll res = 1;
    for(; b; b >>= 1) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

int main() {
    int n; cin >> n;
    while(n--) {
        ll a, b, mod;
        cin >> a >> b >> mod;
        cout << ksm(a, b, mod) << endl;
    }
}