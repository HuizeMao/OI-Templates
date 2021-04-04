// AcWing 868. 筛质数
// O(N logN)
#include <iostream>
using namespace std;

const int N = 1e6 + 6;

int pri[N], tp;
bool v[N];
int n;

int main() {
    cin >> n;
    for(int i = 2; i <= n; i ++) {
        if(v[i]) continue ;
        pri[++tp] = i;
        for(int j = 2; j <= n/i; j ++) v[i*j] = 1;
    }
    cout << tp << endl;
}