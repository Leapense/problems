#include <iostream>
#include <cstdint>
#include <tuple>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Key
{
    int a, b, c;
    uint64_t x;

    bool operator==(const Key &other) const
    {
        return a == other.a && b == other.b && c == other.c && x == other.x;
    }
};

struct KeyHash
{
    size_t operator()(const Key &k) const
    {
        size_t res = 17;
        res = res * 31 + std::hash<int>()(k.a);
        res = res * 31 + std::hash<int>()(k.b);
        res = res * 31 + std::hash<int>()(k.c);
        res = res * 31 + std::hash<uint64_t>()(k.x);
        return res;
    }
};

unordered_map<Key, uint64_t, KeyHash> memo;

uint64_t dp(int a, int b, int c, uint64_t x)
{
    if (x == 0)
        return 0;
    if (a == 0 && b == 0 && c == 0)
        return x;

    Key key{a, b, c, x};
    if (memo.find(key) != memo.end())
        return memo[key];

    uint64_t best = UINT64_MAX;

    if (a > 0)
    {
        uint64_t nx = x / 2;
        best = min(best, dp(a - 1, b, c, nx));
    }
    if (b > 0)
    {
        uint64_t nx = (x + 1) / 2;
        best = min(best, dp(a, b - 1, c, nx));
    }
    if (c > 0)
    {
        uint64_t nx = (x > 0 ? (x - 1) : x) / 2;
        best = min(best, dp(a, b, c - 1, nx));
    }

    memo[key] = best;
    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint64_t n;
    int a, b, c;
    cin >> n >> a >> b >> c;

    uint64_t result = dp(a, b, c, n);
    cout << result << "\n";

    return 0;
}