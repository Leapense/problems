#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

// 문제의 해결 로직: 입력 스트림 in에서 데이터를 읽고, 결과를 출력 스트림 out에 기록
void solve(istream &in, ostream &out) {
    int N;
    in >> N;
    
    // prefix[i]: 1번부터 i번 학생까지 찬성 투표 수의 누적합 (prefix[0] = 0)
    vector<int> prefix(N + 1, 0);
    int totalYes = 0;
    
    for (int i = 1; i <= N; i++) {
        int X, Y;
        in >> X >> Y;
        
        bool voteYes = false;
        if (Y == 0) {
            voteYes = true;
        } else if (Y == X + 1) {
            voteYes = false;
        } else {
            int leftIndex = i - X - 1;
            int countYes = prefix[i - 1] - (leftIndex >= 0 ? prefix[leftIndex] : 0);
            voteYes = (countYes >= Y);
        }
        
        totalYes += voteYes ? 1 : 0;
        prefix[i] = totalYes;
    }
    
    out << totalYes;
}

#ifdef UNIT_TEST
#include <gtest/gtest.h>

TEST(VotingTest, Sample1) {
    string input = R"(4
0 1
1 0
1 1
3 3
)";
    string expected_output = "2";
    stringstream ss_in(input), ss_out;
    solve(ss_in, ss_out);
    EXPECT_EQ(ss_out.str(), expected_output);
}

TEST(VotingTest, Sample2) {
    string input = R"(5
0 0
1 1
2 3
3 1
4 3
)";
    string expected_output = "4";
    stringstream ss_in(input), ss_out;
    solve(ss_in, ss_out);
    EXPECT_EQ(ss_out.str(), expected_output);
}

TEST(VotingTest, Sample3) {
    string input = R"(10
0 0
1 2
1 1
1 0
3 1
2 3
1 1
5 3
8 4
7 2
)";
    string expected_output = "4";
    stringstream ss_in(input), ss_out;
    solve(ss_in, ss_out);
    EXPECT_EQ(ss_out.str(), expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#else

// 일반 실행시엔 표준 입력/출력으로 동작
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}

#endif

