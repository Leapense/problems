#include <bits/stdc++.h>
using namespace std;

/* ───────────────────── 알고리즘 본체 ───────────────────── */
static int days_in_month(int Y, int M) {
    static int md[]{0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (M == 2) {
        bool leap = (Y % 400 == 0) || (Y % 4 == 0 && Y % 100 != 0);
        return leap ? 29 : 28;
    }
    return md[M];
}

std::string Solve(std::istream& in) {
    string y, m, d;             // YYYY MM DD
    if (!(in >> y >> m >> d)) return {};
    string s = y + m + d;
    sort(s.begin(), s.end());

    vector<string> res;
    do {
        int Y = stoi(s.substr(0,4));
        if (Y == 0) continue;

        int M = stoi(s.substr(4,2));
        if (M == 0 || M > 12) continue;

        int D = stoi(s.substr(6,2));
        if (D == 0 || D > days_in_month(Y, M)) continue;

        ostringstream oss;
        oss << setw(4) << setfill('0') << Y << ' '
            << setw(2) << setfill('0') << M << ' '
            << setw(2) << setfill('0') << D;
        res.push_back(oss.str());
    } while (next_permutation(s.begin(), s.end()));

    sort(res.begin(), res.end());
    ostringstream out;
    out << res.size() << '\n';
    for (auto& e : res) out << e << '\n';
    return out.str();
}

/* ─────────────── 엔트리포인트 (테스트 제외) ─────────────── */
#ifndef UNIT_TEST
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << Solve(cin);
    return 0;
}
#endif

