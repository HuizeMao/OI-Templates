// AcWing 829. 模拟队列
// O(1) 出队，入队，查询队头队尾
#include <iostream>
using namespace std;

const int N = 100006;

int q[N], l, r;
int n;

int main() {
    cin >> n;
    l = 1, r = 0;
    while(n--) {
        char op[10]; cin >> op;
        if(op[0] == 'e') cout << (l <= r ? "NO" : "YES") << endl;
        else if(op[0] == 'p' && op[1] == 'u') ++r, cin >> q[r];
        else if(op[0] == 'p') ++l;
        else cout << q[l] << endl;
    }
}

// Implementation Details:
// l>r 队列为空, ++l 出队, ++r 入队
