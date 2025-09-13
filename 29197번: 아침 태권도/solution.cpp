#include <bits/stdc++.h>
using namespace std;

struct P {
    int x, y;
    bool operator==(const P& o) const { return x == o.x && y == o.y; }
};

struct H {
    size_t operator()(const P& p) const noexcept {
        uint64_t a = (uint64_t)(int64_t)p.x;
        uint64_t b = (uint64_t)(int64_t)p.y;
        uint64_t z = (a << 1) ^ (b + 0x9e3779b97f4a7c15ULL + (a << 6) + (a >> 2));

        z += 0x9e3779b97f4a7c15ULL;
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
        z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
        z ^= (z >> 31);
        return (size_t)z;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    unordered_set<P, H> S;
    S.reserve((size_t)(N * 1.3));

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        int gx = abs(x), gy = abs(y);
        int g = std::gcd(gx, gy);
        int u = x / g, v = y / g;
        S.insert({u, v});
    }

    cout << S.size() << '\n';
    return 0;
}