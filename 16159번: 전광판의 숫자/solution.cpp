#include <bits/stdc++.h>
using namespace std;

static constexpr array<array<array<string,7>,10>,1> make_table() {
    return {{{{
        {"000000","011110","010010","010010","010010","011110","000000"},
        {"000000","000100","001100","000100","000100","000100","000000"},
        {"000000","011110","000010","011110","010000","011110","000000"},
        {"000000","011110","000010","011110","000010","011110","000000"},
        {"000000","000100","001100","010100","111110","000100","000000"},
        {"000000","011110","010000","011110","000010","011110","000000"},
        {"000000","011110","010000","011110","010010","011110","000000"},
        {"000000","011110","000010","000100","001000","001000","000000"},
        {"000000","011110","010010","011110","010010","011110","000000"},
        {"000000","011110","010010","011110","000010","011110","000000"}
    }}}};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    if (!(cin >> line)) return 0;
    vector<string> rows(7);
    rows[0] = move(line);
    for (int i = 1; i < 7; ++i) cin >> rows[i];
    const int n = static_cast<int>(rows[0].size() / 6);
    const auto tbl = make_table()[0];
    auto grab_digit = [&](int idx) {
        array<string,7> cur;
        for (int r = 0; r < 7; ++r) cur[r] = rows[r].substr(idx * 6, 6);
        for (int d = 0; d < 10; ++d)
            if (equal(cur.begin(), cur.end(), tbl[d].begin())) return d;
        return -1;
    };
    vector<int> seq(n);
    for (int i = 0; i < n; ++i) seq[i] = grab_digit(i);
    if (!next_permutation(seq.begin(), seq.end())) {
        cout << "The End\n";
        return 0;
    }
    for (int r = 0; r < 7; ++r) {
        for (int d : seq) cout << tbl[d][r];
        cout << '\n';
    }
    return 0;
}