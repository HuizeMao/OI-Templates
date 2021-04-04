// 如果 N = p1^c1 * p2^c2 * ... *pk^ck
// 约数个数： (c1 + 1) * (c2 + 1) * ... * (ck + 1)
#include <iostream>
#include <cmath>
#include <unordered_map>
#define ll long long
using namespace std;

typedef pair<int, ll> PII; PII tmp;
const int mod = 1e9 + 7;

unordered_map<int, ll> H;
unordered_map<int, ll>::iterator it;
int n;

void decom(int x) { //decom 末尾一定要特判如果x > 1
    for(int i = 2; i <= sqrt(x); i ++)
        if(x%i == 0) {
            int num = 0;
            while(x%i == 0) ++num, x /= i;
            H[i] = (H[i] + num) % mod;
        }
    if(x > 1) H[x] = (H[x] + 1) % mod; 
}

int main() {
    cin >> n;
    while(n--) {
        int x; cin >> x;
        decom(x);
    }
    ll ans = 1;
    for(it = H.begin(); it != H.end(); it ++) {
        tmp = *it;
        ans = (ans * (tmp.second + 1)) % mod;
    }
    cout << ans << endl;
}

// Sample Input:
/*
3
2
6
8
*/
// Sample output: 12