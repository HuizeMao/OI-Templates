// AcWing 826. 单链表
// 链表下标i代表链表里存着第i个插入值的信息, 插入删除O(1)
#include <iostream>
using namespace std;

const int N = 100006;

struct LL {
    int r, x;
} llist[N]; int Head = -1, tot;
int n;

int main() {
    cin >> n;
    while(n--) {
        char op[10]; cin >> op;
        int pos, x;
        if(op[0] == 'H') {
            cin >> x;
            llist[++tot].x = x;
            llist[tot].r = Head;
            Head = tot;
        } else if(op[0] == 'D') {
            cin >> pos;
            if(!pos) Head = llist[Head].r;
            else llist[pos].r = llist[llist[pos].r].r;
        } else {
            cin >> pos >> x;
            llist[++tot].x = x;
            llist[tot].r = llist[pos].r;
            llist[pos].r = tot;
        }
    }
    for(int i = Head; i != -1; i = llist[i].r)
        cout << llist[i].x << " ";
}

// Implementation details:
// Head init as -1, tot as 0 (but ++tot every time)


// Input
/*
10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6
*/

//Output
// 6 4 6 5
