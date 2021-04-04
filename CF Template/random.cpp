#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

const int N = 20, M = 30;

int random(int mod) {
    return rand() * rand() % mod;
}

int main() {
    freopen("data.in", "w", stdout);
    srand((unsigned) time(0));
    
}