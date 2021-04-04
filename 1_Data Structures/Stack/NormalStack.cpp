//AcWing 828. 模拟栈
//O(1) 弹栈顶, 入栈, 查询栈顶
#include <iostream>
using namespace std;

const int N = 100006;

int sta[N], tp;
int n;

int main() {
    cin >> n;
    while(n--) {
        char op[10]; cin >> op;
        if(op[0] == 'p' && op[1] == 'u') ++tp, cin >> sta[tp];
        else if(op[0] == 'p') --tp;
        else if(op[0] == 'q') cout << sta[tp] << endl;
        else cout << (tp ? "NO" : "YES") << endl;
    }
}