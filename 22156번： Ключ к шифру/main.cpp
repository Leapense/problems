#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

const ull BASE = 131;

vector<ull> prefixHash, revPrefixHash, power;

void computeHashes(const string &s, const string &s_rev) {
    int n = s.size();
    prefixHash.resize(n + 1);
    revPrefixHash.resize(n + 1);
    power.resize(n + 1);
    prefixHash[0] = 0;
    revPrefixHash[0] = 0;
    power[0] = 1;

    for (int i = 0; i < n; i++) {
        prefixHash[i + 1] = prefixHash[i] * BASE + s[i];
        revPrefixHash[i + 1] = revPrefixHash[i] * BASE + s_rev[i];
        power[i + 1] = power[i] * BASE;
    }
}

ull getHash(const vector<ull>& hashArr, int l, int r) {
    return hashArr[r + 1] - hashArr[l] * power[r - l + 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string enc;
        cin >> enc;
        int n = enc.size();
        string enc_rev = enc;
        reverse(enc_rev.begin(), enc_rev.end());

        computeHashes(enc, enc_rev);

        int bestKeyLen = 0;
        int best_t_len = -1;
        int best_r = 0;

        for (int r = 0; r <= n / 2; r++) {
            int t_len = n - 2 * r;
            if (t_len <= 0) break;

            int lo = 1, hi = t_len;
            int cur_max = 0;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                ull hash1 = getHash(prefixHash, r, r + mid - 1);
                ull hash2 = getHash(revPrefixHash, r, r + mid - 1);

                if (hash1 == hash2) {
                    cur_max = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if (cur_max > bestKeyLen || (cur_max == bestKeyLen && t_len > best_t_len)) {
                bestKeyLen = cur_max;
                best_t_len = t_len;
                best_r = r;
            }
        }

        cout << enc.substr(best_r, bestKeyLen) << "\n";
    }

    return 0;
}
