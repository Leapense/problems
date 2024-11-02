#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;

    string s;

    cin >> s;

    if ((int)s.size() != N) {
        s.resize(N, '0');
    }

    ll total = 0;
    int current_run = 0;

    for (int x = N - 1; x >= 0; x--) {
        if (s[x] == '1') {
            current_run += 1;
        } else {
            current_run = 0;
        }

        total += current_run;
    }

    cout << total;

    return 0;
}