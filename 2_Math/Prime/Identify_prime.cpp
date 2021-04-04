// AcWing 866. 试除法判定质数
// O(N * sqrt(X)), X为给定数的最大值
#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int x) {
    if(x <= 1) return false;
    for(int i = 2; i <= sqrt(x); i ++)
        if(x % i == 0) return false;
    return true;
}

int main() {
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        cout << (is_prime(x) ? "Yes" : "No") << endl;
    }
}

// Implementation details:
// numbers <= 1 are not primes nor composite, so 特判