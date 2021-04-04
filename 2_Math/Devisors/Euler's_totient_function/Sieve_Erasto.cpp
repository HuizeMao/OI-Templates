// AcWing 874. 筛法求欧拉函数
// E式筛法: O(NlogN), 在筛质数的时候顺便把欧拉函数也构造起来
#include <iostream>
#define ll long long
using namespace std;

const int N = 1e6 + 6;

ll phi[N], n; 

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) phi[i] = i;
    for(int i = 2; i <= n; i ++)
        if(phi[i] == i) {
            for(int j = i; j <= n; j += i) 
                phi[j] = phi[j] / i * (i-1);
        }
    ll S = 0;
    for(int i = 1; i <= n; i ++) S += phi[i];
    cout << S << endl;
}