// AcWing 889. 满足条件的01序列
// 给定n个0和n个1，它们按照某种顺序排成长度为2n的序列
// 满足任意前缀中0的个数都不少于1的个数的序列的数量为： 
//     Cat(n) = C(2n, n) / (n + 1)
// 有mod的话直接乘法逆元求组合数 O(NlogN)

#include <iostream>
#define ll long long
using namespace std;

int n, mod = 1e9 + 7;

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

int main() {
    cin >> n;
    ll inv = ksm(n+1, mod-2);
    cout << C(2*n, n) * inv % mod << endl;
}