#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int MAX_r = atoi(argv[1]);
    int MAX_R = atoi(argv[2]);
    int MAX_n = atoi(argv[3]);

    int r = rnd.next(1, MAX_r);
    int R = rnd.next(r, MAX_R);
    int n = rnd.next(1, MAX_n);

    cout << r << " " << R << " " << n << "\n";
    return 0;
}