// AcWing 838. 堆排序
// O(logN) to push
#include <iostream>
#include <queue>
using namespace std;

const int N = 10006;

priority_queue<int> pq;
int n, m;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        int ai; cin >> ai;
        pq.push(-ai);
    }
    while(m--) {
        int ai = -pq.top (); pq.pop();
        cout << ai << " ";
    }
}

// Implementation Detail:
// negate values to get the minimun on top
// don't forget to negate back when outputting