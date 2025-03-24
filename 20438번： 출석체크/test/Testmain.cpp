#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <vector>
using namespace std;

// Sample Test Case 1
TEST(AttendanceTest, SampleTest1)
{
    int N = 10, K = 1, Q = 3, M = 1;
    vector<int> sleeping = {7};
    vector<int> initialRecipients = {3, 5, 7};
    vector<pair<int, int>> queries = {{3, 12}};
    vector<int> expected = {4};

    vector<int> result = solve(N, K, Q, M, sleeping, initialRecipients, queries);
    EXPECT_EQ(result, expected);
}

// Sample Test Case 2
TEST(AttendanceTest, SampleTest2)
{
    int N = 50, K = 4, Q = 5, M = 1;
    vector<int> sleeping = {24, 15, 27, 43};
    vector<int> initialRecipients = {3, 4, 6, 20, 25};
    vector<pair<int, int>> queries = {{3, 52}};
    vector<int> expected = {25};

    vector<int> result = solve(N, K, Q, M, sleeping, initialRecipients, queries);
    EXPECT_EQ(result, expected);
}

// 추가 테스트: 선생님이 출석 코드를 보내지 않은 경우 (모두 미출석)
TEST(AttendanceTest, NoTeacherCodeTest)
{
    int N = 10, K = 0, Q = 0, M = 1;
    vector<int> sleeping = {};
    vector<int> initialRecipients = {};
    vector<pair<int, int>> queries = {{3, 12}};
    // 전체 학생 수: 10명이 모두 미출석
    vector<int> expected = {10};

    vector<int> result = solve(N, K, Q, M, sleeping, initialRecipients, queries);
    EXPECT_EQ(result, expected);
}

// 추가 테스트: 초기 출석코드 수신자가 졸고 있는 경우 (출석 전파 제한)
TEST(AttendanceTest, SleepingInitialTest)
{
    int N = 10, K = 2, Q = 2, M = 1;
    vector<int> sleeping = {3, 5};
    vector<int> initialRecipients = {3, 6}; // 3은 졸고 있으므로 무시, 6은 깨어있음
    vector<pair<int, int>> queries = {{3, 12}};
    // 6번 학생은 깨어있으므로, 6번과 6의 배수 12번만 출석 처리됩니다.
    // 전체 학생 수 10명 중 2명 출석 => 미출석 8명
    vector<int> expected = {8};

    vector<int> result = solve(N, K, Q, M, sleeping, initialRecipients, queries);
    EXPECT_EQ(result, expected);
}

// 추가 테스트: 단일 출석코드 전파에 의한 전체 전파 확인
TEST(AttendanceTest, FullPropagationTest)
{
    int N = 20, K = 0, Q = 1, M = 1;
    vector<int> sleeping = {};
    vector<int> initialRecipients = {3}; // 3번이 깨어있으므로 출발점
    vector<pair<int, int>> queries = {{3, 22}};
    // 3번의 배수: 3,6,9,12,15,18,21 출석 처리
    // 전체 학생 수는 20명 => 미출석 20 - 7 = 13명
    vector<int> expected = {13};

    vector<int> result = solve(N, K, Q, M, sleeping, initialRecipients, queries);
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}