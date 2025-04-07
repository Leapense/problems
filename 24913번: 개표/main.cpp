#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll mn, mx;
};

struct SegTree {
    int n;
    vector<Node> tree;

    SegTree(int n) : n(n) {
        tree.resize(4 * n, {0, 0});
    }

    void build(vector<ll>& arr, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = {arr[l], arr[l]};
            return;
        }

        int mid = (l + r) / 2;
        build(arr, idx * 2, l, mid);
        build(arr, idx * 2 + 1, mid + 1, r);
        tree[idx].mn = min(tree[idx * 2].mn, tree[idx * 2 + 1].mn);
        tree[idx].mx = max(tree[idx * 2].mx, tree[idx * 2 + 1].mx);
    }

    void update(int idx, int l, int r, int pos, ll val) {
        if (l == r) {
            tree[idx].mn += val;
            tree[idx].mx += val;
            return;
        }

        int mid = (l + r) / 2;
        if (pos <= mid) update(idx * 2, l, mid, pos, val);
        else update(idx * 2 + 1, mid + 1, r, pos, val);

        tree[idx].mn = min(tree[idx * 2].mn, tree[idx * 2 + 1].mn);
        tree[idx].mx = max(tree[idx * 2].mx, tree[idx * 2 + 1].mx);
    }

    pair<ll, ll> query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return {LLONG_MAX, 0};
        if (ql <= l && r <= qr) {
            return {tree[idx].mn, tree[idx].mx};
        }

        int mid = (l + r) / 2;
        auto left = query(idx * 2, l, mid, ql, qr);
        auto right = query(idx * 2 + 1, mid + 1, r, ql, qr);
        return {min(left.first,right.first), max(left.second, right.second)};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;

    vector<ll> init(N, 0);
    SegTree seg(N);
    seg.build(init, 1, 0, N - 1);

    ll candidateJ = 0;

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            ll x;
            int p;
            cin >> x >> p;
            if (p == N + 1) {
                candidateJ += x;
            } else {
                seg.update(1, 0, N - 1, p - 1, x);
            }
        } else {
            ll x, y;
            cin >> x >> y;
            ll newJ = candidateJ + x;
            auto res = seg.query(1, 0, N - 1, 0, N - 1);
            ll othersMax = res.second;
            ll othersMin = res.first;

            ll bestOther = max(othersMax, othersMin + y);
            cout << (newJ > bestOther ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}
