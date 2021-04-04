// AcWing 830. 单调栈
// O(1) 弹栈顶, 入栈, 查询栈顶
#include <iostream>
using namespace std;

const int N = 100006;

int sta[N], tp;
int n, a[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        while(tp && a[sta[tp]] >= a[i]) --tp;
        cout << (tp ? a[sta[tp]] : -1) << " ";
        sta[++tp] = i;
    }
}

// Implementation Details:
// 栈里存下标, 单调栈满足下标(sta[i])递增, 对应的a[]值(a[sta[i]])也递增
