#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 학생 구조체 정의
struct Student {
    int gender; // 0: 남자, 1: 여자
    int height;
};

int main(){
    int n;
    cin >> n;
    
    vector<Student> boys;
    vector<Student> girls;
    
    // 학생 정보 입력받기
    for(int i=0; i<n; ++i){
        int a, h;
        cin >> a >> h;
        if(a == 0){
            boys.push_back({a, h});
        }
        else{
            girls.push_back({a, h});
        }
    }
    
    // 남자 학생들을 키가 큰 순서대로 정렬
    sort(boys.begin(), boys.end(), [](const Student &a, const Student &b) -> bool{
        return a.height > b.height;
    });
    
    // 여자 학생들을 키가 큰 순서대로 정렬
    sort(girls.begin(), girls.end(), [](const Student &a, const Student &b) -> bool{
        return a.height > b.height;
    });
    
    // 최종 줄 서기
    vector<int> lineup;
    for(auto &student : boys){
        lineup.push_back(student.height);
    }
    for(auto &student : girls){
        lineup.push_back(student.height);
    }
    
    // 인접한 두 학생의 키 차이 중 최대값 찾기
    int max_diff = 0;
    for(int i=1; i<lineup.size(); ++i){
        int diff = abs(lineup[i] - lineup[i-1]);
        if(diff > max_diff){
            max_diff = diff;
        }
    }
    
    cout << max_diff;
}