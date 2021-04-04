// AcWing 873. 欧拉函数
// Given a number x, phi(x) returns the number of elements {ai} such that
// 1 <= ai <= x and gcd(x, ai) = 1 [thus phi(1) = 1]
// O(n*sqrt(n)) 
#include <iostream>
#include <cmath>
#define ll long long 
using namespace std;

ll phi(ll x) {
    ll res = x;
    for(int i = 2; i <= sqrt(x); i ++)
        if(x % i == 0) {
            res = res/i*(i-1);
            while(x%i == 0) x /= i;
        }
    if(x > 1) res = res/x*(x-1);    
    return res;
}

int main() {
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        cout << phi(x) << endl;
    }
}