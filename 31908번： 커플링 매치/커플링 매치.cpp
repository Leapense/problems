#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    // 반지 특징별로 이름을 저장하는 맵
    map<string, vector<string>> feature_map;
    // 특징의 입력 순서를 유지하기 위한 벡터
    vector<string> feature_order;
    
    for(int i=0; i<N; i++){
        string name, feature;
        cin >> name >> feature;
        if(feature != "-"){ // '-'인 경우는 제외
            feature_map[feature].push_back(name);
            // 새로운 특징일 경우, 순서를 기록
            if(feature_map[feature].size() == 1){
                feature_order.push_back(feature);
            }
        }
    }
    
    // 커플 의심군 쌍을 저장할 벡터
    vector<pair<string, string>> couples;
    
    for(auto &feature : feature_order){
        if(feature_map[feature].size() == 2){
            // 정확히 두 명인 경우 쌍을 저장
            couples.emplace_back(feature_map[feature][0], feature_map[feature][1]);
        }
    }
    
    // 결과 출력
    cout << couples.size() << "\n";
    for(auto &p : couples){
        cout << p.first << " " << p.second << "\n";
    }
}
