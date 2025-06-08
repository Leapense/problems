#include <bits/stdc++.h>
using namespace std;

constexpr int32_t MAX_N   = 1'000'000;
constexpr int32_t MAX_CNT = 240;    // empirically sufficient

struct Node { int addr; int youngest; };

static array<uint16_t, MAX_N + 1> cntDiv {};
static array<int32_t, MAX_N + 1>   minDiv {};
static vector<vector<Node>>        buckets;   // indexed by cntDiv value

static void precompute()
{
    /* modified sieve */
    for (int d = 2; d * 2 <= MAX_N; ++d)
        for (int m = d * 2; m <= MAX_N; m += d) {
            ++cntDiv[m];
            if (minDiv[m] == 0) { minDiv[m] = d; }
        }

    /* allocate buckets */
    buckets.assign(MAX_CNT + 1, {});
    for (int x = 2; x <= MAX_N; ++x) {
        buckets[cntDiv[x]].push_back({x, minDiv[x]});
    }
}

static int solve(int N, int M)
{
    const auto signature = cntDiv[N];
    if (signature == 0) { return 0; }   // N is prime → no recipient qualifies

    const auto &vec = buckets[signature];

    auto it = std::lower_bound(vec.begin(), vec.end(), N,
                               [](const Node &n, int value) { return n.addr < value; });
    int32_t ans = 0;
    for (auto iter = vec.begin(); iter != it; ++iter) {
        if (iter->youngest >= M) { ++ans; }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N, M; cin >> N >> M;
        cout << "Case #" << tc << ": " << solve(N, M) << '\n';
    }
    return 0;
}