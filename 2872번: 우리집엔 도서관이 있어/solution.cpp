#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> a(N);
    for (int &x : a) cin >> x;

    int  expected = N;
    for (int i = N - 1; i >= 0; --i) {
        if (a[i] == expected) --expected;
    }

    cout << expected << "\n";
    return 0;
}
