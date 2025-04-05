#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

// solve() 함수는 입력 스트림으로부터 문제 데이터를 읽고, 결과를 출력 스트림에 기록합니다.
void solve(istream &in, ostream &out) {
    int N, M;
    in >> N >> M;
    
    vector<pair<int,int>> hits;  // 탄환이 맞은 칸 좌표만 저장
    string row;
    // 사격판 입력 처리: 각 행을 문자열로 읽으면서 '1'인 칸의 좌표를 hits에 저장
    for (int r = 0; r < N; r++) {
        in >> row;
        for (int c = 0; c < M; c++) {
            if (row[c] == '1') {
                hits.emplace_back(r, c);
            }
        }
    }
    
    // 표적지의 오프셋 정보 저장 (중심 기준: (9,9))
    // 각 오프셋 (dr, dc)와 해당 칸의 점수 ring (1~10)을 미리 계산
    vector<tuple<int, int, int>> offsets;
    offsets.reserve(361);
    for (int r = 0; r < 19; r++) {
        for (int c = 0; c < 19; c++) {
            int d = max(abs(r - 9), abs(c - 9));
            int ring = 10 - d;  // 중심은 10점, 바깥쪽은 1점
            if (ring >= 1 && ring <= 10) {
                offsets.emplace_back(r - 9, c - 9, ring);
            }
        }
    }
    
    // 각 사격판 칸에서 점수별 탄환 개수를 저장할 3차원 벡터 (N x M x 10)
    // 단, 각 점수에 대해 2개 이상이면 이미 불가능하므로 값을 2 이상으로 클램프합니다.
    vector<vector<vector<uint8_t>>> centerScoreCount(N, vector<vector<uint8_t>>(M, vector<uint8_t>(10, 0)));
    
    // 각 탄환(hit)에 대해 표적지 오프셋을 적용하여, 표적지 중심이 (R, C)인 경우에 해당 점수를 획득하는 것으로 처리
    for (const auto &[x, y] : hits) {
        for (const auto &[dr, dc, ring] : offsets) {
            int R = x - dr;
            int C = y - dc;
            if (R >= 0 && R < N && C >= 0 && C < M) {
                uint8_t &cnt = centerScoreCount[R][C][ring - 1];
                if (cnt < 2) cnt++;
            }
        }
    }
    
    // 모든 (R, C) 위치에 대해, 1점부터 10점까지 모두 정확히 1개씩 있어야 함
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            bool valid = true;
            for (int k = 0; k < 10; k++) {
                if (centerScoreCount[r][c][k] != 1) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                out << r << " " << c << "\n";
                return;
            }
        }
    }
    out << -1 << "\n";
}

// 테스트 케이스들을 위한 헬퍼 함수: 입력 문자열을 읽어 solve()를 실행한 후 결과 문자열을 반환합니다.
string runTest(const string &input) {
    istringstream iss(input);
    ostringstream oss;
    solve(iss, oss);
    return oss.str();
}

// 샘플 테스트 케이스 1
TEST(TargetTest, SampleTest1) {
    string input = R"(10 10
1000000000
0100000000
0010000000
0001000000
0000100000
0000010000
0000001000
0000000100
0000000010
0000000001
)";
    // sample output는 "0 0"이지만, 문제 조건에 맞는 다른 정답이 존재할 수도 있으므로,
    // 본 테스트에서는 출력 결과가 -1이 아닌 경우에 대해 각 점수가 1개씩 존재하는지 검증할 수도 있습니다.
    // 여기서는 sample output 그대로 "0 0"을 기대합니다.
    string expected = "0 0\n";
    string result = runTest(input);
    SCOPED_TRACE("Input:\n" + input);
    SCOPED_TRACE("Expected output: " + expected);
    SCOPED_TRACE("Your program output: " + result);
    EXPECT_EQ(result, expected);
}

// 샘플 테스트 케이스 2
TEST(TargetTest, SampleTest2) {
    string input = R"(10 10
1000000000
0100000000
0010000000
0001000000
0000100000
0000010000
0000001000
0000000100
0000000010
0000000011
)";
    string expected = "-1\n";
    string result = runTest(input);
    SCOPED_TRACE("Input:\n" + input);
    SCOPED_TRACE("Expected output: " + expected);
    SCOPED_TRACE("Your program output: " + result);
    EXPECT_EQ(result, expected);
}

// 추가적인 테스트 케이스 예제 (원하는 만큼 추가 가능)
// 예: 간단한 케이스: 1x1 보드
TEST(TargetTest, SingleCellBoard) {
    string input = R"(1 1
1
)";
    // 19x19 표적지를 1x1 보드에 올리면 표적지의 대부분이 격자 밖으로 나가므로 조건을 만족시킬 수 없다.
    string expected = "-1\n";
    string result = runTest(input);
    SCOPED_TRACE("Input:\n" + input);
    SCOPED_TRACE("Expected output: " + expected);
    SCOPED_TRACE("Your program output: " + result);
    EXPECT_EQ(result, expected);
}

// main() 함수: 모든 테스트 케이스를 실행합니다.
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
