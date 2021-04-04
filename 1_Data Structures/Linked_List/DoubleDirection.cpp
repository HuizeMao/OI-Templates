// AcWing 827. 双链表
// 链表下标i代表链表里存着第i个插入值的信息, 插入删除O(1)
#include <iostream>
using namespace std;

const int N = 100006;

struct LL {
    int l, r, x;
} llist[N]; int tot = 1;
int n;

int main() {
    llist[0].r = 1, llist[1].l = 0;
    cin >> n;
    while(n--) {
        char op[10]; cin >> op;
        int x, pos; 
        if(op[0] == 'L') {
            cin >> x;
            llist[++tot].x = x, llist[tot].r = llist[0].r, llist[tot].l = 0;
            llist[0].r = llist[llist[tot].r].l = tot;
        } else if(op[0] == 'R') {
            cin >> x;
            llist[++tot].x = x, llist[tot].l = llist[1].l, llist[tot].r = 1;
            llist[1].l = llist[llist[tot].l].r = tot;
        } else if(op[0] == 'D') {
            cin >> pos; ++pos;
            llist[llist[pos].l].r = llist[pos].r;
            llist[llist[pos].r].l = llist[pos].l;
        } else if(op[1] == 'L') {
            cin >> pos >> x; ++pos;
            llist[++tot].x = x, llist[tot].r = pos, llist[tot].l = llist[pos].l;
            llist[pos].l = llist[llist[tot].l].r = tot;
        } else {
            cin >> pos >> x; ++pos;
            llist[++tot].x = x, llist[tot].l = pos, llist[tot].r = llist[pos].r;
            llist[pos].r = llist[llist[tot].r].l = tot;
        }
    }
    for(int i = llist[0].r; i != 1; i = llist[i].r)
        cout << llist[i].x << " ";
}


// Implementation details:
// llist[0] saves head to the list and [1] saves the tail
//        --> initially [0].r = 1, [1].l = 0
//        --> llist[head].r points to the 1st elem.
// tot has to be init as 1, so ++tot gives two(first one not occupied)
// thus when adding elem. to pos p, p has to "++p"


// Samples:
/* Input
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
*/

//Output
// 8 7 7 3 2 9

