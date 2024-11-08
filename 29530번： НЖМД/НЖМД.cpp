#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n);
    for (int &x : p) {
        cin >> x;
    }

    vector<int> pos(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pos[p[i]] = i + 1;
    }

    int rotations = 0;

    for (int i = 2; i <= n; ++i) {
        if (pos[i] < pos[i - 1]) {
            rotations++;
        }
    }

    cout << rotations << endl;

    return 0;
}