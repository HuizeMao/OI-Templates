// AcWing 868. 筛质数
// O(N)
#include <iostream>
using namespace std;

const int N = 1e6 + 6;

int pri[N], tp, v[N];
int n;

int main() {
    cin >> n;
    for(int i = 2; i <= n; i ++) {
        if(!v[i]) pri[++tp] = i, v[i] = i;
        for(int j = 1; j <= tp; j ++) {
            if(pri[j] > v[i] || pri[j] > n/i) break;
            v[pri[j]*i] = pri[j];
        }
    }
    cout << tp << endl;
}