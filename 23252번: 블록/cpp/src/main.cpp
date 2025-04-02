#include <iostream>
#include "main.h"
using namespace std;

string solveCase(long long A, long long B, long long C) {
    if (A < C) return "No";
    if ((A - C) % 2 != 0) return "No";
    return "Yes";
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long A, B, C;
        cin >> A >> B >> C;
        cout << solveCase(A, B, C) << "\n";
    }

    return 0;
}
#endif
