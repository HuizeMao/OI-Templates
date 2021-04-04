// AcWing 885. 求组合数 I [N choose K] % mod 
// O(N^2), DP approach pre caculates all N choose K, (N,K <= 5000)
// always applicable, but with large n or k, a mod might be req.
#include <iostream>
using namespace std;

const int N = 2006, mod = 1e9 + 7;

int C[N][N], n;

void constr_C() {
    for(int i = 0; i <= N-6; i ++) 
        for(int j = 0; j <= i; j ++) {
            if(!j) C[i][j] = 1;
            else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        } 
}

int main() {
    cin >> n;
    constr_C();
    while(n--) {
        int a, b; cin >> a >> b;
        cout << C[a][b] << endl;
    }
}

// Sample Input:
/*
3
3 1
5 3
2 2
*/
/* Sample Output
3
10
1
*/