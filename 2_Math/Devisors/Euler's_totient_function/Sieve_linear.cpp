// AcWing 874. 线性筛 + 欧拉和积性函数性质 求欧拉函数
// O(N), 在筛质数的时候顺便把欧拉函数也构造起来
// 积性函数性质: J(1) = 1, J(a*b) = J(a) * J(b) 且 gcd(a, b) = 1
// 完全积性【J(a*b) = J(a) * J(b) 且a,b不需互质】
#include <iostream>
using namespace std;

const int N = 1e6 + 6;

int phi[N], tp, v[N], pri[N];
int n;

int main() {
    cin >> n;
    phi[1] = 1;
    for(int i = 2; i <= n; i ++) {
        if(!v[i]) {
            v[i] = i, pri[++tp] = i;
            phi[i] = i - 1;
        }
        for(int j = 1; j <= tp; j ++) {
            if(pri[j] > v[i] || pri[j] > n/i) break;
            v[pri[j]*i] = pri[j];
            phi[pri[j]*i] = i % pri[j] ? phi[i] * phi[pri[j]] : phi[i] * pri[j];
        }
    }
    long long sum = 0;
    for(int i = 1; i <= n; i ++) sum += phi[i];
    cout << sum << endl;
}