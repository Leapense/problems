#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cassert>
#include <gtest/gtest.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    for (int puzzle = 1; puzzle <= t; puzzle++){
        int r, c;
        cin >> r >> c;
        vector<string> grid(r);
        for (int i = 0; i < r; i++) {
            cin >> grid[i];
        }
        int s;
        cin >> s;
        vector<string> words(s);
        for (int i = 0; i < s; i++) {
            cin >> words[i];
        }
        
        cout << "Word search puzzle #" << puzzle << ":\n";
        
        // 방향 정보: 오른쪽(R), 왼쪽(L), 아래(D), 위(U)
        vector<pair<char, pair<int,int>>> directions = {
            {'R', {0, 1}},
            {'L', {0, -1}},
            {'D', {1, 0}},
            {'U', {-1, 0}}
        };
        
        for (const auto &word : words) {
            bool found = false;
            for (int i = 0; i < r && !found; i++) {
                for (int j = 0; j < c && !found; j++) {
                    if (grid[i][j] != word[0])
                        continue;
                    
                    for (auto &dir : directions) {
                        char dCode = dir.first;
                        int dr = dir.second.first, dc = dir.second.second;
                        bool match = true;
                        int curR = i, curC = j;
                        for (int k = 0; k < (int)word.size(); k++) {
                            if (grid[curR][curC] != word[k]) {
                                match = false;
                                break;
                            }
                            curR = (curR + dr + r) % r;
                            curC = (curC + dc + c) % c;
                        }
                        if (match) {
                            cout << dCode << " " << (i + 1) << " " << (j + 1) << " " << word << "\n";
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
        cout << "\n";
    }
}

TEST(LoopyWordSearchTest, SampleTestCase) {
    // 샘플 입력 문자열
    string input = R"(2
6 12
JARWORDEPIDG
IWAXLOEAHNOK
KPEPSORTHGIN
ZASFCOFABEMW
QEHEZIUSRSTY
MWCORMNELTOS
5
WORD
SEARCH
KNIGHTRO
UNDERFUND
INGESTING
3 7
UCFAEHT
KNIGHTS
CODETRY
2
AGE
THETHETHETHETH
)";
    // 예상 출력 문자열 (마지막 개행 미포함)
    string expected_output = R"(Word search puzzle #1:
R 1 4 WORD
U 4 3 SEARCH
L 3 1 KNIGHTRO
D 5 7 UNDERFUND
D 1 10 INGESTING

Word search puzzle #2:
D 1 4 AGE
U 3 5 THETHETHETHETH
)";
    
    // 원래 스트림 버퍼 백업
    auto cinbuf_backup = cin.rdbuf();
    auto coutbuf_backup = cout.rdbuf();
    
    istringstream iss(input);
    ostringstream oss;
    cin.rdbuf(iss.rdbuf());
    cout.rdbuf(oss.rdbuf());
    
    solve();
    
    cin.rdbuf(cinbuf_backup);
    cout.rdbuf(coutbuf_backup);
    
    // 실제 출력 결과와 예상 출력 비교를 위해 마지막 개행 문자를 제거
    string output = oss.str();
    if (!output.empty() && output.back() == '\n')
        output.pop_back();
    
    EXPECT_EQ(output, expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
