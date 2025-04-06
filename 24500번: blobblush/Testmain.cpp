#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

/**
 * 문제 풀이 함수를 solve()로 정의한다.
 * 표준 입력에서 N을 읽어서 원하는 결과를 표준 출력으로 내보낸다.
 * (이전 답변에서 설명한 blobblush 문제 알고리즘을 그대로 적용)
 */
void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    // 1. N의 가장 높은 비트 위치: L
    int L = 64 - __builtin_clzll(N);
    // 2. M = 2^L - 1
    unsigned long long M = (1ULL << L) - 1ULL;

    if (M <= (unsigned long long)N) {
        // 카드 1장, 바로 M
        cout << 1 << "\n";
        cout << M << "\n";
    } else {
        // 카드 2장 (x, y)
        long long T = (long long)M - N;
        long long x = max(1LL, T); // 사전순 가장 앞서는 x
        long long y = (long long)M - x;
        cout << 2 << "\n";
        cout << x << "\n" << y << "\n";
    }
}

/**
 * 헬퍼 함수: 주어진 입력 문자열을 stdin에 대입하고,
 * solve() 함수를 실행하여 얻은 출력을 문자열로 반환한다.
 */
string runBlobblush(const string &inputData) {
    // 기존 버퍼 저장
    streambuf* backupIn = cin.rdbuf();
    streambuf* backupOut = cout.rdbuf();

    // 임시 입력/출력 스트림
    istringstream inputBuf(inputData);
    ostringstream outputBuf;

    // 표준 입출력 버퍼를 임시 스트림으로 교체
    cin.rdbuf(inputBuf.rdbuf());
    cout.rdbuf(outputBuf.rdbuf());

    // 문제 풀이 함수 실행
    solve();

    // 실행 후 결과 스트링 획득
    string result = outputBuf.str();

    // 입출력 복원
    cin.rdbuf(backupIn);
    cout.rdbuf(backupOut);

    return result;
}

/**
 * 실제 테스트 케이스들
 * 각 TEST(테스트_스위트이름, 테스트_케이스이름)으로 구성
 */
TEST(BlobblushTest, SampleCase1) {
    // N=7 => 예상 출력: 1\n7\n
    string inputData = "7\n";
    string expectedOutput = "1\n7\n";
    EXPECT_EQ(runBlobblush(inputData), expectedOutput);
}

// 추가 테스트 1: N=1 -> 최대 XOR = 1 <= N => {1}
TEST(BlobblushTest, CaseN1) {
    // N=1 => 1\n1\n
    string inputData = "1\n";
    string expectedOutput = "1\n1\n";
    EXPECT_EQ(runBlobblush(inputData), expectedOutput);
}

// 추가 테스트 2: N=2 -> L=2 => M=3 => 3>2 => 2장: x=1, y=2
TEST(BlobblushTest, CaseN2) {
    // N=2 => 2\n1\n2\n
    string inputData = "2\n";
    string expectedOutput = "2\n1\n2\n";
    EXPECT_EQ(runBlobblush(inputData), expectedOutput);
}

// 추가 테스트 3: N=8 -> L=4 => M=15 => 15>8 => x=7, y=8
TEST(BlobblushTest, CaseN8) {
    // N=8 => 2\n7\n8\n
    string inputData = "8\n";
    string expectedOutput = "2\n7\n8\n";
    EXPECT_EQ(runBlobblush(inputData), expectedOutput);
}

// 추가 테스트 4: N=31 -> L=5 => M=31 => 31<=31 => {31}
TEST(BlobblushTest, CaseN31) {
    // N=31 => 1\n31\n
    string inputData = "31\n";
    string expectedOutput = "1\n31\n";
    EXPECT_EQ(runBlobblush(inputData), expectedOutput);
}

// 추가 테스트 5: N=32 -> L=6 => M=63 => 63>32 => x=31, y=32
TEST(BlobblushTest, CaseN32) {
    // N=32 => 2\n31\n32\n
    string inputData = "32\n";
    string expectedOutput = "2\n31\n32\n";
    EXPECT_EQ(runBlobblush(inputData), expectedOutput);
}

// 추가 테스트 6: 조금 큰 수, N=100 -> L=7 => M=127 => 127>100 => x=27, y=100
TEST(BlobblushTest, CaseN100) {
    // N=100 => 2\n27\n100\n
    string inputData = "100\n";
    string expectedOutput = "2\n27\n100\n";
    EXPECT_EQ(runBlobblush(inputData), expectedOutput);
}

/**
 * GTest 실행을 위한 main 함수
 */
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
