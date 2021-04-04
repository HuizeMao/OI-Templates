// AcWing 877. 扩展欧几里得算法
// O(logN) to find a pair of int (x, y) such that a*x+b*y=gcd(a, b)
#include <iostream>
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

int main() {
    int n; cin >> n;
    while(n--) {
        int a, b, x, y; cin >> a >> b;
        int d = exgcd(a, b, x, y);
        cout << x << " " << y << endl;
    }
}