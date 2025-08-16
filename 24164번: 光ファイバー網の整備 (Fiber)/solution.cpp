#include <iostream>
#include <vector>
using namespace std;

static int find_set(int x, vector<int>& parent) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }

    return x;
}

static void unite(int a, int b, vector<int>& parent, vector<int>& sz) {
    int ra = find_set(a, parent);
    int rb = find_set(b, parent);
    if (ra == rb) {
        return;
    }
    if (sz[ra] < sz[rb]) {
        swap(ra, rb);
    }
    parent[rb] = ra;
    sz[ra] += sz[rb];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    int m;
    if (!(cin >> m)) {
        return 0;
    }

    if (n <= 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> parent(n + 1), sz(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a >= 1 && a <= n && b >= 1 && b <= n && a != b) {
            unite(a, b, parent, sz);
        }
    }

    vector<char> seen(n + 1, 0);
    int comps = 0;
    for (int i = 1; i <= n; i++) {
        int r = find_set(i, parent);
        if (!seen[r]) {
            seen[r] = 1;
            comps++;
        }
    }

    int ans = comps > 0 ? comps - 1 : 0;
    cout << ans << '\n';
    return 0;
}