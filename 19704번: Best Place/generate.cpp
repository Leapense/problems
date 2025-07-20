#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int MAX_N = atoi(argv[1]);
    int MAX_COORD = atoi(argv[2]);

    int count = rnd.next(1, MAX_N);
    cout << count << "\n";

    for (int i = 0; i < count; i++) {
        int x = rnd.next(-MAX_COORD, MAX_COORD);
        int y = rnd.next(-MAX_COORD, MAX_COORD);
        cout << x << " " << y << "\n";
    }

    return 0;
}