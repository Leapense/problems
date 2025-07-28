#include <bits/stdc++.h>
using namespace std;

enum class Kind { Cube, Cyl };
struct Block {
    Kind k;
    int v;
    string raw;
};

static bool fits(const Block& a, const Block& b) {
    if (a.k == Kind::Cube && b.k == Kind::Cube) return a.v <= b.v;
    if (a.k == Kind::Cube && b.k == Kind::Cyl) return static_cast<double>(a.v) <= b.v * std::sqrt(2.0);
    if (a.k == Kind::Cyl && b.k == Kind::Cyl) return a.v <= b.v;
    return 2 * a.v <= b.v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<Block> a(n);
    for (auto& b : a) {
        string t;
        int v;
        cin >> t >> v;
        b.k = t == "cube" ? Kind::Cube : Kind::Cyl;
        b.v = v;
        b.raw = t + ' ' + to_string(v);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (!fits(a[i], a[j]) && !fits(a[j], a[i])) {
                cout << "impossible\n";
                return 0;
            }
        }
    }

    std::stable_sort(begin(a), end(a), [](const Block& x, const Block& y) {
        if (fits(x, y) && !fits(y, x)) return true;
        if (fits(y, x) && !fits(x, y)) return false;
        return false;
    });

    for (auto& b : a) cout << b.raw << "\n";
    return 0;
}