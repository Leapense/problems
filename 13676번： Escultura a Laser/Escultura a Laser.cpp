#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, C;

    while (cin >> A >> C) {
        if (A == 0 and C == 0) break;

        vector<int> X(C);

        for (auto &x : X) cin >> x;

        long long total = 0;
        int prev = A;

        for (auto x:X) {
            if (prev > x) total += (prev - x);
            prev = x;
        }

        cout << total << "\n";
    }

    return 0;
}