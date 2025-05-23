#include <bits/stdc++.h>
using namespace std;

// 요일과 월을 숫자로 매핑
unordered_map<string, int> day_map = {
    {"Monday", 0},
    {"Tuesday", 1},
    {"Wednesday", 2},
    {"Thursday", 3},
    {"Friday", 4},
    {"Saturday", 5},
    {"Sunday", 6}
};

unordered_map<string, int> month_map = {
    {"January", 1},
    {"February", 2},
    {"March", 3},
    {"April", 4},
    {"May", 5},
    {"June", 6},
    {"July", 7},
    {"August", 8},
    {"September", 9},
    {"October", 10},
    {"November", 11},
    {"December", 12}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    int year;
    cin >> year;
    
    // 윤년 판별
    bool is_leap = false;
    if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
        is_leap = true;
    }
    
    // 월별 일수 설정
    int days_in_month[13] = {0};
    days_in_month[1] = 31;
    days_in_month[2] = is_leap ? 29 : 28;
    days_in_month[3] = 31;
    days_in_month[4] = 30;
    days_in_month[5] = 31;
    days_in_month[6] = 30;
    days_in_month[7] = 31;
    days_in_month[8] = 31;
    days_in_month[9] = 30;
    days_in_month[10] = 31;
    days_in_month[11] = 30;
    days_in_month[12] = 31;
    
    // 공휴일 저장
    vector<pair<int, int>> holidays;
    for(int i = 0; i < N; i++){
        int day;
        string month;
        cin >> day >> month;
        int m = month_map[month];
        holidays.emplace_back(day, m);
    }
    
    string first_day_str;
    cin >> first_day_str;
    int first_day = day_map[first_day_str];
    
    // 연간 요일 개수 계산
    int total_days = is_leap ? 366 : 365;
    int base = total_days / 7; // 각 요일이 최소 몇 번 있는지
    int extra = total_days % 7; // 추가로 있는 요일의 수
    
    int weekdays_count[7];
    for(int i = 0; i < 7; i++) weekdays_count[i] = base;
    
    // 추가 일수 분배
    for(int i = 0; i < extra; i++){
        int day = (first_day + i) % 7;
        weekdays_count[day]++;
    }
    
    // 공휴일 요일 계산
    int holidays_on_day[7] = {0};
    for(auto &[day, month] : holidays){
        // 해당 날짜까지의 총 일수 계산
        int total = 0;
        for(int m = 1; m < month; m++) total += days_in_month[m];
        total += (day - 1); // 현재 달의 day까지
        int dow = (first_day + total) % 7;
        holidays_on_day[dow]++;
    }
    
    // 각 요일별 총 휴일 계산
    // total_days_off = weekdays_count[d] + (N - holidays_on_day[d])
    // 최대과 최소를 찾기
    int max_off = -1, min_off = 1e9;
    int best_day = 0, worst_day = 0;
    for(int d = 0; d < 7; d++){
        int total_off = weekdays_count[d] + (N - holidays_on_day[d]);
        if(total_off > max_off){
            max_off = total_off;
            best_day = d;
        }
        if(total_off < min_off){
            min_off = total_off;
            worst_day = d;
        }
    }
    
    // 요일 이름 배열
    string days_names[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    cout << days_names[best_day] << " " << days_names[worst_day];
}