#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
        explicit DisjointSet(int n) : parent(n), rank_(n, 0) {
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unite(int a, int b) {
            int ra = find(a);
            int rb = find(b);
            if (ra == rb) {
                return;
            }
            if (rank_[ra] < rank_[rb]) {
                parent[ra] = rb;
            } else if (rank_[ra] > rank_[rb]) {
                parent[rb] = ra;
            } else {
                parent[rb] = ra;
                ++rank_[ra];
            }
        }
    private:
        vector<int> parent;
        vector<int> rank_;
};

static void multiplyByTwo(string& s) {
    int carry = 0;
    for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
        int d = (s[i] - '0') * 2 + carry;
        s[i] = static_cast<char>((d % 10) + '0');
        carry = d / 10;
    }
    if (carry) {
        s.insert(s.begin(), static_cast<char>(carry + '0'));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    vector<vector<int>> grid(2, vector<int>(n));
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> grid[r][c];
        }
    }

    DisjointSet dsu(2 * n);

    for (int c = 0; c < n; ++c) {
        dsu.unite(c, n + c);
    }

    vector<int> firstPos(n + 1, -1);
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < n; ++c) {
            int num = grid[r][c];
            int idx = (r == 0 ? c : n + c);
            if (firstPos[num] < 0) {
                firstPos[num] = idx;
            } else {
                dsu.unite(firstPos[num], idx);
            }
        }
    }

    unordered_set<int> roots;
    roots.reserve(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        roots.insert(dsu.find(i));
    }

    int C = static_cast<int>(roots.size());

    string answer = "1";
    for (int i = 0; i < C; ++i) {
        multiplyByTwo(answer);
    }

    cout << answer << "\n";
    return 0;
}