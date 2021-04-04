// AcWing 838. 堆排序
// bool operator 比较 
#include <iostream>
#include <queue>
using namespace std;

const int N = 10006;

struct node {
    int x;
    bool operator<(const node &a) const {
        return a.x < x;
    }
}tmp;
priority_queue<node> pq;
int n, m;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> tmp.x;
        pq.push(tmp);
    }
    while(m--) {
        tmp = pq.top(), pq.pop();
        cout << tmp.x << " ";
    }
}