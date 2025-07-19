#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int maxN = (argc >= 2 ? atoi(argv[1]) : 1000000);
    int n = rnd.next(1, maxN);
    
    cout << n << "\n";
    return 0;
}