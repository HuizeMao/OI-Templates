// AcWing 867. 分解质因数
// O(N * sqrt(X)), X is the max integer value
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;

void decom(int x) {
    if(x == 1) {printf("1 1\n"); return ;}
    for(int i = 2; i <= sqrt(x); i ++)
        if(x % i == 0) {
            int num = 0;
            while(x % i == 0) x /= i, ++num;
            printf("%d %d\n", i, num);
        }
    if(x > 1) printf("%d %d\n", x, 1);
    puts("");
}

int main() {
    cin >> n;
    while(n--) {
        int x; cin >> x;
        decom(x);
    }
    return 0;
}

// Implementation details:
// after decom from 2 - sqrt(x), check if x is still > 1, if so x now itself
//  is a prime 