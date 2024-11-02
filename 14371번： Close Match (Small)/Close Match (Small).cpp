#include <bits/stdc++.h>
using namespace std;

// 재귀적으로 각 자릿수의 조합을 결정하는 함수
void dfs(int pos, string &C, string &J, long long &best_c, long long &best_j, long long &min_diff, string &cur_c, string &cur_j) {
    // 끝까지 도달한 경우, 점수 계산
    if (pos == C.size()) {
        long long c_val = stoll(cur_c);
        long long j_val = stoll(cur_j);
        long long diff = abs(c_val - j_val);

        // 차이를 최소화하고, 동일한 경우 Coders와 Jammers 점수를 최소화
        if (diff < min_diff || (diff == min_diff && c_val < best_c) || (diff == min_diff && c_val == best_c && j_val < best_j)) {
            min_diff = diff;
            best_c = c_val;
            best_j = j_val;
        }
        return;
    }

    // 현재 자리에서 '?'인 경우 모든 가능성을 시도
    if (C[pos] == '?' && J[pos] == '?') {
        for (char c = '0'; c <= '9'; c++) {
            for (char j = '0'; j <= '9'; j++) {
                cur_c[pos] = c;
                cur_j[pos] = j;
                dfs(pos + 1, C, J, best_c, best_j, min_diff, cur_c, cur_j);
            }
        }
    } else if (C[pos] == '?') {
        for (char c = '0'; c <= '9'; c++) {
            cur_c[pos] = c;
            dfs(pos + 1, C, J, best_c, best_j, min_diff, cur_c, cur_j);
        }
    } else if (J[pos] == '?') {
        for (char j = '0'; j <= '9'; j++) {
            cur_j[pos] = j;
            dfs(pos + 1, C, J, best_c, best_j, min_diff, cur_c, cur_j);
        }
    } else {
        // '?'가 없는 경우 그대로 진행
        dfs(pos + 1, C, J, best_c, best_j, min_diff, cur_c, cur_j);
    }
}

void solve_case(int t, string C, string J) {
    long long best_c = LLONG_MAX, best_j = LLONG_MAX, min_diff = LLONG_MAX;
    string cur_c = C, cur_j = J;

    dfs(0, C, J, best_c, best_j, min_diff, cur_c, cur_j);

    // 출력 포맷 맞추기
    cout << "Case #" << t << ": ";
    cout << setw(C.size()) << setfill('0') << best_c << " ";
    cout << setw(C.size()) << setfill('0') << best_j << endl;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string C, J;
        cin >> C >> J;
        solve_case(t, C, J);
    }

    return 0;
}