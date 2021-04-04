// AcWing 869. 试除法求约数
// O(N * sqrt(X)) N = 100, X = 10^9
// 在10^9之内的自然数中, 约数个数最多的自然数仅有1536个约数, 所以之后的sort最多
// O(2000*log(2000))
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 2000;

int d[N], tp;
int n, x;

void constr_d() {
    for(int i = 1; i <= sqrt(x); i ++)
        if(x % i == 0) {
            d[++tp] = i;
            if(i*i != x) d[++tp] = x / i;
        }
}

int main() {
    cin >> n;
    while(n--) {
        cin >> x;
        tp = 0;
        constr_d();
        sort(d + 1, d + 1 + tp);
        for(int i = 1; i <= tp; i ++) cout << d[i] << " ";
        puts("");
    }
}