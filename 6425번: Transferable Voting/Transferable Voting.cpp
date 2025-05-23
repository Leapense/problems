#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

struct Election {
    int c;
    int n;
    vector<vector<int>> ballots;
    int invalid;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int c, n;
    int election_num = 1;
    
    while(cin >> c >> n){
        if(c == 0 && n == 0){
            break;
        }
        
        Election election;
        election.c = c;
        election.n = n;
        election.invalid = 0;
        election.ballots.reserve(n);
        
        // 각 유권자의 투표 읽기 및 유효성 검사
        for(int i=0; i<n; ++i){
            vector<int> ballot(c);
            bool valid = true;
            set<int> seen;
            for(int j=0; j<c; ++j){
                cin >> ballot[j];
                if(ballot[j] < 1 || ballot[j] > c){
                    valid = false;
                }
                seen.insert(ballot[j]);
            }
            if(seen.size() != c){
                valid = false;
            }
            if(valid){
                election.ballots.push_back(ballot);
            }
            else{
                election.invalid++;
            }
        }
        
        // Transferable Vote 알고리즘 시작
        // 활성 후보를 추적
        vector<bool> active(c+1, true); // 후보 번호는 1부터 시작
        int valid_ballots = election.ballots.size();
        int required = valid_ballots / 2 + 1;
        bool elected = false;
        vector<int> winner;
        
        while(!elected){
            // 각 후보의 현재 득표수 초기화
            vector<int> votes(c+1, 0);
            
            // 각 투표를 통해 현재 활성 후보에게 투표 배분
            for(auto &ballot : election.ballots){
                for(auto choice : ballot){
                    if(active[choice]){
                        votes[choice]++;
                        break;
                    }
                }
            }
            
            // 최대 득표 확인
            int max_votes = -1;
            for(int i=1; i<=c; ++i){
                if(active[i] && votes[i] > max_votes){
                    max_votes = votes[i];
                }
            }
            
            // 승자 확인
            vector<int> current_winners;
            for(int i=1; i<=c; ++i){
                if(active[i] && votes[i] >= required){
                    current_winners.push_back(i);
                }
            }
            if(!current_winners.empty()){
                winner = current_winners;
                elected = true;
                break;
            }
            
            // 최소 득표 후보 찾기
            int min_votes = 1e9;
            for(int i=1; i<=c; ++i){
                if(active[i] && votes[i] < min_votes){
                    min_votes = votes[i];
                }
            }
            
            // 최소 득표 후보 모두 찾기
            vector<int> min_candidates;
            for(int i=1; i<=c; ++i){
                if(active[i] && votes[i] == min_votes){
                    min_candidates.push_back(i);
                }
            }
            
            // 모든 활성 후보이면서 최소 득표라면 무승부
            int active_count = 0;
            for(int i=1; i<=c; ++i){
                if(active[i]){
                    active_count++;
                }
            }
            if(min_candidates.size() == active_count){
                // 무승부
                for(int i=1; i<=c; ++i){
                    if(active[i]){
                        winner.push_back(i);
                    }
                }
                elected = true;
                break;
            }
            
            // 최소 득표 후보 제거
            for(auto cand : min_candidates){
                active[cand] = false;
            }
        }
        
        // 출력
        cout << "Election #" << election_num++ << "\n";
        if(election.invalid > 0){
            cout << "   " << election.invalid << " bad ballot(s)\n";
        }
        if(winner.size() == 1){
            cout << "   Candidate " << winner[0] << " is elected.\n";
        }
        else{
            cout << "   The following candidates are tied:";
            for(auto cand : winner){
                cout << " " << cand;
            }
            cout << " \n"; // 마지막에 공백과 줄바꿈
        }
    }
}