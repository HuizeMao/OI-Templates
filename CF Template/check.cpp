#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int main() {
    for(int i = 1; i <= 1000; i ++) {
        system("random.exe");
        double st = clock();
        system("sol.exe");
        double ed = clock();
        system("bf.exe");
        if(system("fc data.out data.ans")) {
            puts("WA");
            return 0;
        } else {
            printf("AC, Test#%d, Time: %.0lfms\n",i, ed-st);
        }
    }
}