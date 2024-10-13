//=====================================================================
//   19025번:    Time to get up!                   
//   @date:   2024-10-13              
//   @link:   https://www.acmicpc.net/problem/19025  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int digits_segments[10] = {
        0b0111111, //0
        0b0000110, //1
        0b1011011, //2
        0b1001111, //3
        0b1100110, //4
        0b1101101, //5
        0b1111101, //6
        0b0000111, //7
        0b1111111, //8
        0b1101111  //9
    };
    auto get_digit = [&](const vector<string>& grid) -> int {
        int mask = 0;
        if(grid[0][1] == 'X' || grid[0][2] == 'X') mask |= (1<<0);
        if(grid[1][3] == 'X' || grid[2][3] == 'X') mask |= (1<<1);
        if(grid[4][3] == 'X' || grid[5][3] == 'X') mask |= (1<<2);
        if(grid[6][1] == 'X' || grid[6][2] == 'X') mask |= (1<<3);
        if(grid[4][0] == 'X' || grid[5][0] == 'X') mask |= (1<<4);
        if(grid[1][0] == 'X' || grid[2][0] == 'X') mask |= (1<<5);
        if(grid[3][1] == 'X' || grid[3][2] == 'X') mask |= (1<<6);
        for(int d=0; d<10; d++) if(digits_segments[d] == mask) return d;
        return -1;
    };
    int T;
    cin >> T;
    while(T--){
        vector<string> lines(7);
        for(auto &s: lines) cin >> s;
        auto extract_grid = [&](int start) -> vector<string> {
            vector<string> grid(7);
            for(int i=0;i<7;i++) grid[i] = lines[i].substr(start,4);
            return grid;
        };
        vector<int> digits;
        digits.push_back(get_digit(extract_grid(0)));
        digits.push_back(get_digit(extract_grid(5)));
        digits.push_back(get_digit(extract_grid(12)));
        digits.push_back(get_digit(extract_grid(17)));
        string time = "";
        time += (digits[0] != -1 ? to_string(digits[0]) : "0");
        time += (digits[1] != -1 ? to_string(digits[1]) : "0");
        time += ":";
        time += (digits[2] != -1 ? to_string(digits[2]) : "0");
        time += (digits[3] != -1 ? to_string(digits[3]) : "0");
        cout << time << "\n";
    }
}
