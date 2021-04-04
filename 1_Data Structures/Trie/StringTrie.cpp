// AcWing 835. Trie字符串统计
// O(字符串总长)
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100006;

int trie[N][30], cnt[N], tot = 1;
int n, sz;
char s[N];

void insert(int p, int dep) {
    if(dep == sz) {cnt[p]++; return ;}
    int c = s[dep] - 'a';
    if(!trie[p][c]) trie[p][c] = ++tot;
    insert(trie[p][c], dep + 1);
}

int ask(int p, int dep) {
    if(dep == sz) return cnt[p];
    if(!p) return 0;
    int c = s[dep] - 'a';
    return ask(trie[p][c], dep + 1);
}

int main() {
    cin >> n;
    while(n--) {
        char op[10]; cin >> op >> s;
        sz = strlen(s);
        if(op[0] == 'I') insert(1, 0);
        else cout << ask(1, 0) << endl;
    }
}

// Implementation details:
// tot init as 1