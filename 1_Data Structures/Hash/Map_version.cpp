// AcWing 840. 模拟散列表
// unordered_map to see if some elements has appeared before
// O(1) average, O(N) worst case
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> H;
int n;

int main() {
    cin >> n;
    while(n--) {
        char op[10]; cin >> op;
        int x; cin >> x;
        if(op[0] == 'I') H[x] = 1;
        else cout << (H.find(x) == H.end() ? "No" : "Yes") << endl;
    }
    return 0;
}