#include <bits/stdc++.h>
using namespace std;

// 핸드 구조체 정의
struct Hand {
    bool is_set;    // 세트 여부
    int matched;    // 매치된 랭크 (세트의 경우 세트 랭크, 페어의 경우 페어 랭크)
    int unmatched;  // 언매치된 랭크 (세트의 경우 0)
};

// 핸드 비교 함수: 오름차순 정렬을 위해 사용
bool compare_hands(const Hand& a, const Hand& b) {
    if (a.is_set != b.is_set) {
        return a.is_set < b.is_set; // 페어는 세트보다 낮게
    }
    if (!a.is_set && !b.is_set) {
        if (a.matched != b.matched)
            return a.matched < b.matched;
        return a.unmatched < b.unmatched;
    }
    if (a.is_set && b.is_set) {
        return a.matched < b.matched;
    }
    return false;
}

// 주어진 핸드 a가 핸드 b보다 큰지 판단하는 함수
bool is_greater(const Hand& a, const Hand& b){
    if(a.is_set != b.is_set){
        return a.is_set > b.is_set; // 세트는 페어보다 큼
    }
    if(!a.is_set && !b.is_set){
        if(a.matched != b.matched)
            return a.matched > b.matched;
        return a.unmatched > b.unmatched;
    }
    if(a.is_set && b.is_set){
        return a.matched > b.matched;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // 모든 가능한 페어와 세트를 생성
    vector<Hand> sorted_hands;
    // 페어 생성
    for(int matched = 1; matched <=13; matched++){
        for(int unmatched =1; unmatched <=13; unmatched++){
            if(unmatched == matched) continue;
            Hand h;
            h.is_set = false;
            h.matched = matched;
            h.unmatched = unmatched;
            sorted_hands.push_back(h);
        }
    }
    // 세트 생성
    for(int set_rank =1; set_rank <=13; set_rank++){
        Hand h;
        h.is_set = true;
        h.matched = set_rank;
        h.unmatched = 0;
        sorted_hands.push_back(h);
    }
    // 핸드 정렬
    sort(sorted_hands.begin(), sorted_hands.end(), compare_hands);
    
    while(1){
        int A, B, C;
        cin >> A >> B >> C;
        if(A ==0 && B ==0 && C ==0) break;
        
        // 입력 핸드 분석
        bool is_set = false;
        bool is_pair = false;
        int matched = 0;
        int unmatched =0;
        
        if(A == B && B == C){
            is_set = true;
            matched = A;
        }
        else{
            // 페어인지 확인
            if(A == B || A == C){
                is_pair = true;
                matched = A;
                unmatched = (A == B) ? C : B;
            }
            else if(B == C){
                is_pair = true;
                matched = B;
                unmatched = A;
            }
        }
        
        // 입력 핸드 객체 생성
        Hand input_hand;
        if(is_set){
            input_hand.is_set = true;
            input_hand.matched = matched;
            input_hand.unmatched = 0;
        }
        else if(is_pair){
            input_hand.is_set = false;
            input_hand.matched = matched;
            input_hand.unmatched = unmatched;
        }
        
        // 결과 핸드 찾기
        bool found = false;
        Hand result;
        if(!is_set && !is_pair){
            // 노 페어인 경우, 가장 낮은 페어가 이김
            result = sorted_hands[0];
            found = true;
        }
        else{
            // 페어나 세트인 경우, sorted_hands에서 첫 번째로 큰 핸드를 찾음
            for(auto &h : sorted_hands){
                if(is_greater(h, input_hand)){
                    result = h;
                    found = true;
                    break;
                }
            }
        }
        
        if(found){
            if(result.is_set){
                // 세트인 경우
                cout << result.matched << " " << result.matched << " " << result.matched << "\n";
            }
            else{
                // 페어인 경우
                // 카드들을 오름차순으로 정렬하여 출력
                vector<int> cards = {result.matched, result.matched, result.unmatched};
                sort(cards.begin(), cards.end());
                cout << cards[0] << " " << cards[1] << " " << cards[2] << "\n";
            }
        }
        else{
            // 이기는 핸드가 없는 경우
            cout << "*\n";
        }
    }
}