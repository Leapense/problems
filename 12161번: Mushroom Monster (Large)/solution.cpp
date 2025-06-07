#include <bits/stdc++.h>
using namespace std;

static auto method1(const vector<uint32_t> &a) -> uint32_t {
    uint32_t sum = 0;
    for (size_t i = 0; i + 1 < a.size(); ++i) {
        if (a[i] > a[i + 1]) {
            sum += a[i] - a[i + 1];
        }
    }

    return sum;
}

static auto method2(const vector<uint32_t> &a) -> uint32_t {
    uint32_t rate = 0;
    for (size_t i = 0; i + 1 < a.size(); ++i) {
        rate = max(rate, a[i] > a[i + 1] ? a[i] - a[i + 1] : 0U);
    }

    uint32_t sum = 0;
    for (size_t i = 0; i + 1 < a.size(); ++i) {
        sum += min(a[i], rate);
    }

    return sum;
}

auto main() -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint32_t T;
    cin >> T;
    for (uint32_t tc = 1; tc <= T; ++tc) {
        size_t N;
        cin >> N;
        vector<uint32_t> m(N);
        for (auto &v : m) {
            cin >> v;
        }
        auto y = method1(m);
        auto z = method2(m);
        cout << "Case #" << tc << ": " << y << ' ' << z << '\n';
    }

    return 0;
}