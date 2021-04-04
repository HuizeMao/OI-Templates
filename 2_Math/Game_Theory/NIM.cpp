// AcWing 891. Nim游戏
// 定理： NIM博弈先手必胜，当且仅当 A1 ^ A2 ^ … ^ An != 0
// O(N)
#include <iostream>
using namespace std;

const int N = 1e5 + 6;

int a[N];
int n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int res = a[1];
    for(int i = 2; i <= n; i ++) res ^= a[i];
    cout << (res ? "Yes" : "No") << endl;
}