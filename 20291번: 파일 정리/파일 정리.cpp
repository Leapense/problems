#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    map<string, int> cnt;

    for (int i = 0; i < N; i++) {
        string filename;
        cin >> filename;

        size_t pos = filename.find_last_of('.');
        string ext = filename.substr(pos + 1);
        cnt[ext]++;
    }

    for (auto &[k, v] : cnt) {
        cout << k << " " << v << "\n";
    }

    return 0;
}