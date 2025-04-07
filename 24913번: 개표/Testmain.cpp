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
        if (pos <= mid) {
            update(idx * 2, l, mid, pos, val);
        } else {
            update(idx * 2 + 1, mid + 1, r, pos, val);
        }

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
        return {min(left.first, right.first), max(left.second, right.second)};
    }
};

void solve(istream &in, ostream &out) {
    ios::sync_with_stdio(false);
    in.tie(nullptr);

    int N, Q;
    in >> N >> Q;

    vector<ll> init(N, 0);
    SegTree seg(N);

    if (N > 0) {
        seg.build(init, 1, 0, N - 1);
    }

    ll candidateJ = 0;

    for (int i = 0; i < Q; i++) {
        int type;
        in >> type;
        if (type == 1) {
            ll x;
            int p;
            in >> x >> p;

            if (p == N + 1) candidateJ += x;
            else seg.update(1, 0, N - 1, p - 1, x);
        } else {
            ll x, y;
            in >> x >> y;
            ll newJ = candidateJ + x;
            if (N == 0) {
                out << "YES\n";
                continue;
            }

            auto res = seg.query(1, 0, N - 1, 0, N - 1);
            ll othersMax = res.second;
            ll othersMin = res.first;
            ll bestOther = max(othersMax, othersMin + y);
            
            out << (newJ > bestOther ? "YES" : "NO") << "\n";
        }
    }
}

#ifndef UNIT_TEST
int main()
{
    solve(cin, cout);
    return 0;
}
#endif

#ifdef UNIT_TEST
#include <gtest/gtest.h>

TEST(SolutionTest, SampleTest1) {
    string input = R"(2 5
1 5 1
1 7 2
1 3 3
2 5 1
2 5 3
)";
    string expected = "YES\nNO\n";
    stringstream in(input), out;
    solve(in, out);
    EXPECT_EQ(out.str(), expected);
}

TEST(SolutionTest, SingleCandidateTest) {
    string input = R"(0 3
1 10 1
2 5 100
2 0 0
)";
    string expected = "YES\nYES\n";
    stringstream in(input), out;
    solve(in, out);
    EXPECT_EQ(out.str(), expected);
}

TEST(SolutionTest, TieTest) {
    string input = R"(1 5
1 10 1
1 5 2
1 3 2
2 0 2
2 5 0
)";
    string expected = "NO\nYES\n";
    stringstream in(input), out;
    solve(in, out);
    EXPECT_EQ(out.str(), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
