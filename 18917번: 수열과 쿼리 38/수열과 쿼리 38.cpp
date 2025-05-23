#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    unordered_map<int, int> count_map;
    count_map.reserve(600000);
    count_map[0] = 1;
    ll total_sum = 0;
    ll total_xor = 0;

    for (int i = 0; i < M; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            count_map[x]++;
            total_sum += x;
            total_xor ^= x;
        }
        else if (type == 2) {
            int x;
            cin >> x;
            count_map[x]--;
            total_sum -= x;
            total_xor ^= x;
        }
        else if (type == 3) {
            cout << total_sum << "\n";
        }
        else if (type == 4) {
            cout << total_xor << "\n";
        }
    }

    return 0;
}