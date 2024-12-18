#include <bits/stdc++.h>
using namespace std;

struct Key {
    int r, c;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Key> pos(10);
    pos[1] = {0,0}; pos[2] = {0,1}; pos[3] = {0,2};
    pos[4] = {1,0}; pos[5] = {1,1}; pos[6] = {1,2};
    pos[7] = {2,0}; pos[8] = {2,1}; pos[9] = {2,2};
    pos[0] = {3,1};

    auto canType = [&](int x) {
        string s = to_string(x);
        if (s[0] == '0') return false; 
        for (int i = 0; i+1 < (int)s.size(); i++) {
            int d1 = s[i]-'0', d2 = s[i+1]-'0';
            if (pos[d2].r < pos[d1].r || pos[d2].c < pos[d1].c) {
                return false;
            }
        }
        return true;
    };

    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        int best = -1;
        int bestDiff = 1e9;
        for (int x = 1; x <= 999; x++) {
            if (canType(x)) {
                int diff = abs(x - k);
                if (diff < bestDiff) {
                    bestDiff = diff;
                    best = x;
                }
            }
        }
        cout << best << "\n";
    }

    return 0;
}