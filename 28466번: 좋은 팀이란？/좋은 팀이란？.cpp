#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    // 천간 관계 점수 입력
    vector<vector<int>> a(10, vector<int>(10, 0));
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            cin >> a[i][j];
        }
    }
    
    // 지지 관계 점수 입력
    vector<vector<int>> b(12, vector<int>(12, 0));
    for(int i=0;i<12;i++) {
        for(int j=0;j<12;j++) {
            cin >> b[i][j];
        }
    }
    
    // 60갑자 매핑
    // 천간: 0-9, 지지: A-L (0-11)
    // 사주 문자열은 "0A" ~ "9L"
    // 각 saju 문자열을 고유 인덱스로 매핑
    unordered_map<string, int> sajuMap;
    vector<pair<int, int>> sajuList(60);
    for(int k=0; k<60; k++){
        int h = k %10;
        int e = k %12;
        string saju = to_string(h) + char('A' + e);
        sajuMap[saju] = k;
        sajuList[k] = {h, e};
    }
    
    // 각 사주별 상위 3명 실력 저장
    // 최소 힙을 사용하여 상위 3명 유지
    vector<priority_queue<int, vector<int>, greater<int>>> topSkills(60, priority_queue<int, vector<int>, greater<int>>());
    
    for(int i=0; i<N; i++){
        int X;
        string S;
        cin >> X >> S;
        if(sajuMap.find(S) == sajuMap.end()){
            // 유효한 사주가 아니면 무시 (문제 조건상 모든 S는 유효하므로 필요 없을 수 있음)
            continue;
        }
        int sajuIdx = sajuMap[S];
        if(topSkills[sajuIdx].size() <3){
            topSkills[sajuIdx].push(X);
        }
        else{
            if(X > topSkills[sajuIdx].top()){
                topSkills[sajuIdx].pop();
                topSkills[sajuIdx].push(X);
            }
        }
    }
    
    // 각 사주별로 내림차순으로 정렬된 상위 3명 리스트로 변환
    vector<vector<int>> peopleInSaju(60, vector<int>());
    for(int k=0; k<60; k++){
        while(!topSkills[k].empty()){
            peopleInSaju[k].push_back(topSkills[k].top());
            topSkills[k].pop();
        }
        // 내림차순 정렬
        sort(peopleInSaju[k].begin(), peopleInSaju[k].end(), greater<int>());
    }
    
    // 사주 간의 관계 점수 미리 계산
    // c[i][j} = a[h1][h2} + b[e1][e2}
    // h1, h2: 0-9
    // e1, e2: 0-11
    // c는 60x60
    vector<vector<int>> c(60, vector<int>(60, 0));
    for(int i=0; i<60; i++){
        for(int j=0; j<60; j++){
            c[i][j] = a[sajuList[i].first][sajuList[j].first] + b[sajuList[i].second][sajuList[j].second];
        }
    }
    
    int maxScore = 0;
    
    // 사주 조합을 효율적으로 탐색
    for(int sa1=0; sa1<60; sa1++){
        if(peopleInSaju[sa1].empty()) continue;
        for(int sa2=sa1; sa2<60; sa2++){
            if(peopleInSaju[sa2].empty()) continue;
            for(int sa3=sa2; sa3<60; sa3++){
                if(peopleInSaju[sa3].empty()) continue;
                
                int totalSkill = 0;
                int totalCompat = 0;
                
                if(sa1 == sa2 && sa2 == sa3){
                    // 모두 같은 사주
                    if(peopleInSaju[sa1].size() <3) continue;
                    totalSkill = peopleInSaju[sa1][0] + peopleInSaju[sa1][1] + peopleInSaju[sa1][2];
                    totalCompat = c[sa1][sa1] * 3;
                }
                else if(sa1 == sa2){
                    // sa1과 sa2가 같은 사주, sa3는 다른 사주
                    if(peopleInSaju[sa1].size() <2 || peopleInSaju[sa3].size() <1) continue;
                    totalSkill = peopleInSaju[sa1][0] + peopleInSaju[sa1][1] + peopleInSaju[sa3][0];
                    totalCompat = c[sa1][sa1] + 2 * c[sa1][sa3];
                }
                else if(sa2 == sa3){
                    // sa2와 sa3가 같은 사주, sa1은 다른 사주
                    if(peopleInSaju[sa2].size() <2 || peopleInSaju[sa1].size() <1) continue;
                    totalSkill = peopleInSaju[sa2][0] + peopleInSaju[sa2][1] + peopleInSaju[sa1][0];
                    totalCompat = c[sa2][sa2] + 2 * c[sa1][sa2];
                }
                else{
                    // 모두 다른 사주
                    if(peopleInSaju[sa1].size() <1 || peopleInSaju[sa2].size() <1 || peopleInSaju[sa3].size() <1) continue;
                    totalSkill = peopleInSaju[sa1][0] + peopleInSaju[sa2][0] + peopleInSaju[sa3][0];
                    totalCompat = c[sa1][sa2] + c[sa1][sa3] + c[sa2][sa3];
                }
                
                int teamScore = totalSkill + totalCompat;
                if(teamScore > maxScore){
                    maxScore = teamScore;
                }
            }
        }
    }
    
    cout << maxScore;
    
    return 0;
}
