#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);
    int N;
    cin >> N;

    vector<int> a(N);

    vector<int> freq(100001, 0);
    int max_freq = 0;

    for (int &x : a) {
        cin >> x;
        freq[x]++;
        if (freq[x] > max_freq) {
            max_freq = freq[x];
        }
    }

    int limit = (N + 1) / 2;
    if (max_freq <= limit) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}