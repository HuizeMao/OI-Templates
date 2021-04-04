// AcWing 872. 最大公约数
// O(N*log(X)) 取模使得规模至少/2, 所以Euclid gcd 复杂度是O(logX)
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int n; cin >> n;
    while(n--) {
        int a, b; cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
}