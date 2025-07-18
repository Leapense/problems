#include <testlib.h>
#include <bits/stdc++.h>
using namespace std;

static inline long long codeEdge(int u, int v)
{
    if (u > v) swap(u, v);
    return (static_cast<long long>(u) << 32) | v;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    if (argc < 3) {
        quitf(_fail, "Usage: %s n m [sm|bg|rd]", argv[0]);
    }
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    string mode = (argc >= 4 ? string(argv[3]) : "rd");

    ensuref(n >= 2, "n must be greater or same with 2.");
    ensuref(1LL * n * (n - 1) / 2 >= m, "dude, that m is too large for given n.");

    vector<pair<int, int>> edges;
    unordered_set<long long> seen;

    auto addEdge = [&](int u, int v) {
        if (u == v) return;
        long long key = codeEdge(u, v);
        if (seen.insert(key).second) {
            edges.emplace_back(u, v);
        }
    };

    if (mode == "sm") {
        int hubs = min(n, 7);

        for (int i = 1; i <= hubs; ++i) {
            for (int j = i + 1; j <= hubs; ++j) {
                addEdge(i, j);
            }
        }

        for (int v = hubs + 1; v <= n; ++v) {
            addEdge(v, rnd.next(1, hubs));
        }
    } else if (mode == "bg") {
        for (int v = 1; v < n; ++v) addEdge(v, v + 1);
    }

    while ((int)edges.size() < m) {
        int u = rnd.next(1, n);
        int v = rnd.next(1, n);
        addEdge(u, v);
    }

    printf("%d %d\n", n, m);
    shuffle(edges.begin(), edges.end());
    for (auto [u, v] : edges) {
        printf("%d %d\n", u, v);
    }

    return 0;
}