#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    vector<int> temps;
    temps.reserve(n);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t > 0) {
            temps.push_back(t);
        }
    }

    if (temps.empty()) {
        cout << "NIE";
        return 0;
    }

    sort(temps.begin(), temps.end());
    
    ll sum = 0;
    int count = temps.size();
    for (auto t : temps) {
        sum += t;
    }

    int removed = 0;

    while (count > 0 && (double)sum / count < w) {
        sum -= temps[removed];
        count--;
        removed++;
    }

    if (count > 0 && (double)sum / count >= w) {
        cout << removed;
    } else {
        cout << "NIE";
    }

    return 0;
}