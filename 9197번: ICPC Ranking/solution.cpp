#include <bits/stdc++.h>
using namespace std;

struct Team {
    int teamId;                   
    int solvedCount = 0;          
    int penalty     = 0;          
    vector<bool> accepted;        
    vector<int>  wrongCount;      

    Team(int id, int P)
      : teamId(id),
        accepted(P + 1, false),
        wrongCount(P + 1, 0)
    {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int M, T, P, R;
        cin >> M >> T >> P >> R;
        if (!cin || (M|T|P|R) == 0) break;

        // 1) 팀 초기화
        vector<Team> teams;
        teams.reserve(T);
        for (int i = 1; i <= T; ++i)
            teams.emplace_back(i, P);

        // 2) 제출 기록 처리
        for (int i = 0; i < R; ++i) {
            int m, t, p, j;
            cin >> m >> t >> p >> j;
            auto &cur = teams[t - 1];
            if (cur.accepted[p]) 
                continue;

            if (j == 0) {
                cur.accepted[p]   = true;
                ++cur.solvedCount;
                cur.penalty      += m + cur.wrongCount[p] * 20;
            } else {
                ++cur.wrongCount[p];
            }
        }

        // 3) 정렬: 
        //    1) 많이 푼 순 ↓
        //    2) 벌칙 시간 적은 순 ↑
        //    3) 동점이면 팀 번호 내림차순 ↓
        sort(teams.begin(), teams.end(), [](auto &a, auto &b) {
            if (a.solvedCount != b.solvedCount)
                return a.solvedCount > b.solvedCount;
            if (a.penalty     != b.penalty)
                return a.penalty     < b.penalty;
            return a.teamId     > b.teamId;
        });

        // 4) 출력: 
        //    동점 그룹은 '=' , 그룹 간은 ','
        cout << teams[0].teamId;
        for (int i = 1; i < T; ++i) {
            bool sameGroup = (teams[i].solvedCount == teams[i-1].solvedCount
                           && teams[i].penalty     == teams[i-1].penalty);
            cout << (sameGroup ? '=' : ',')
                 << teams[i].teamId;
        }
        cout << "\n";
    }
    return 0;
}
