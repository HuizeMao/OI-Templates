// 如果 N = p1^c1 * p2^c2 * ... *pk^ck
// 约数之和： (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
#include <unordered_map>
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

unordered_map<int, ll> H;
unordered_map<int, ll>::iterator it;
int n;

void decom(int x) {
    for(int i = 2; i <= sqrt(x); i ++)
        if(x % i == 0) {
            int num = 0;
            while(x % i == 0) num++, x /= i;
            H[i] += num;
        }
    if(x > 1) H[x]++;
}

ll ksm(ll a, ll b) {
    ll res = 1;
    for(; b; b >>= 1) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

int main() {
    cin >> n;
    while(n--) {
        int x; cin >> x;
        decom(x);
    }
    ll prod = 1;
    for(it = H.begin(); it != H.end(); it ++) {
        pair<int, ll> tmp = *it;
        ll sum = 0;
        for(int i = 0; i <= tmp.second; i ++)
            sum = (sum + ksm(tmp.first, i)) % mod;
        prod = (prod * sum) % mod;
    }
    cout << prod << endl;
}

// Sample Input:
/*
3
2
6
8
*/
// Sample output: 252