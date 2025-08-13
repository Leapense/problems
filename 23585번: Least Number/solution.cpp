#include <bits/stdc++.h>
using namespace std;

static string build_min_number(long long sum, int forbiddenDigit) {
    const int digitMin = 0;
    const int digitMax = 9;
    const int maxDigit = forbiddenDigit == 9 ? 8 : 9;
    const int minOther = forbiddenDigit == 0 ? 1 : 0;

    long long length = (sum + maxDigit - 1) / maxDigit;
    while (true) {
        string result;
        result.reserve(static_cast<size_t>(length));
        long long remaining = sum;
        bool ok = true;

        for (long long i = 0; i < length; ++i) {
            int startDigit = i == 0 ? 1 : digitMin;
            bool placed = false;

            for (int d = startDigit; d <= digitMax; ++d) {
                if (d == forbiddenDigit) continue;
                long long rem = remaining - d;
                if (rem < 0) break;
                long long left = length - 1 - i;
                long long minRem = left * static_cast<long long> (minOther);
                long long maxRem = left * static_cast<long long> (maxDigit);
                if (rem >= minRem && rem <= maxRem) {
                    result.push_back(static_cast<char>('0' + d));
                    remaining = rem;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                ok = false;
                break;
            }
        }

        if (ok && remaining == 0) {
            return result;
        }

        ++length;
        if (length > sum) {
            return string();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int d;
    if (!(cin >> N >> d)) {
        return 0;
    }

    string ans = build_min_number(N, d);
    cout << ans << '\n';

    return 0;
}