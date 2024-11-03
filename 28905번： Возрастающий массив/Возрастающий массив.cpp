#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> b;

    b.reserve(n);

    long long prev = -1e10;
    for (int i = 0; i < n; i++)
    {
        int c1 = a[i];
        int c2 = -a[i];

        if (c1 > c2) {
            swap(c1, c2);
        }

        if (c1 >= prev) {
            b.push_back(c1);
            prev = c1;
        }
        else if (c2 >= prev) {
            b.push_back(c2);
            prev = c2;
        }
        else {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << (i < n - 1 ? " " : "\n");
    }

    return 0;
}