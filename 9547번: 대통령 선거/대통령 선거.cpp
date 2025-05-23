#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int C, V; cin >> C >> V;
        vector<vector<int>> preferences(V, vector<int>(C));
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < C; j++) {
                cin >> preferences[i][j];
            }
        }

        // 1회차 투표
        vector<int> countVotes(C+1, 0);
        for (int i = 0; i < V; i++) {
            int topCandidate = preferences[i][0];
            countVotes[topCandidate]++;
        }

        // 과반수 체크
        int majority = V / 2 + 1; 
        int winner = 0;
        for (int i = 1; i <= C; i++) {
            if (countVotes[i] >= majority) {
                winner = i;
                break;
            }
        }

        if (winner != 0) {
            // 1회차 과반수 당선
            cout << winner << " 1\n";
            continue;
        }

        // 과반수 없음 -> 상위 2명 결정
        // (1위, 2위 후보 찾기)
        // 단순 정렬을 위해 pair(득표수, 후보번호)로 만들고 내림차순 정렬
        vector<pair<int,int>> candidateRank;
        for (int i = 1; i <= C; i++) {
            candidateRank.push_back({countVotes[i], i});
        }
        sort(candidateRank.begin(), candidateRank.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        int firstCandidate = candidateRank[0].second;
        int secondCandidate = candidateRank[1].second;

        // 2회차 투표
        int votesFirst = 0;
        int votesSecond = 0;
        for (int i = 0; i < V; i++) {
            // preferences[i]에서 firstCandidate와 secondCandidate 중 더 선호하는 후보 찾기
            int posFirst = -1, posSecond = -1;
            for (int j = 0; j < C; j++) {
                if (preferences[i][j] == firstCandidate) posFirst = j;
                if (preferences[i][j] == secondCandidate) posSecond = j;
            }
            if (posFirst < posSecond) votesFirst++;
            else votesSecond++;
        }

        if (votesFirst > votesSecond) cout << firstCandidate << " 2\n";
        else cout << secondCandidate << " 2\n";
    }

    return 0;
}