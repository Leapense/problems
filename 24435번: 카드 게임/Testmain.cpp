#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>

// gtest 헤더
#include <gtest/gtest.h>
using namespace std;

// solve 함수: 입력 스트림(in)으로부터 입력을 받고, 출력 스트림(out)에 결과를 출력함.
void solve(istream &in, ostream &out) {
    int T;
    in >> T;
    while (T--) {
        int n;
        string bobStr, aliceStr;
        in >> n >> bobStr >> aliceStr;
        
        // Bob이 만든 두 수 계산: 좌-우와 우-좌
        int bobLR = stoi(bobStr);
        string bobRev = bobStr;
        reverse(bobRev.begin(), bobRev.end());
        int bobRL = stoi(bobRev);
        int threshold = min(bobLR, bobRL);
        
        vector<char> aliceCards(aliceStr.begin(), aliceStr.end());
        vector<bool> used(n, false);
        int best = -1;
        
        // 백트래킹 함수: 현재까지 만든 수 current
        function<void(int)> backtrack = [&](int current) {
            // 현재까지 만든 수가 threshold 미만이면 best 갱신
            if (current < threshold) {
                best = max(best, current);
            }
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    used[i] = true;
                    int newNum = current * 10 + (aliceCards[i] - '0');
                    backtrack(newNum);
                    used[i] = false;
                }
            }
        };
        
        backtrack(0);
        out << best << "\n";
    }
}

#ifndef UNIT_TEST
// 일반 실행 시 main 함수
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
#endif

#ifdef UNIT_TEST
// gtest를 위한 main 함수
// gtest_main 라이브러리를 사용하지 않을 경우 아래와 같이 작성
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif

// 아래는 gtest를 활용한 샘플 테스트 케이스입니다.
#ifdef UNIT_TEST
TEST(SampleTests, TestCase1) {
    // Sample Input 1:
    // 5
    // 2
    // 99
    // 99
    // 3
    // 212
    // 222
    // 3
    // 234
    // 123
    // 4
    // 4123
    // 2345
    // 8
    // 12345678
    // 99999999
    //
    // Expected Output:
    // 9
    // 22
    // 231
    // 2543
    // 9999999
    string input = R"(5
2
99
99
3
212
222
3
234
123
4
4123
2345
8
12345678
99999999
)";
    string expected_output = R"(9
22
231
2543
9999999
)";
    stringstream ss_in(input), ss_out;
    solve(ss_in, ss_out);
    EXPECT_EQ(ss_out.str(), expected_output);
}
#endif

