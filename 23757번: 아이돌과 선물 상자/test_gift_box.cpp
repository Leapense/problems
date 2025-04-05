#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

/**
 * 선물 상자와 아이들의 요구를 받아
 * 모든 아이가 원하는 만큼 선물을 가져갈 수 있는지 여부를 반환한다.
 *
 * @param N 선물 상자의 개수
 * @param M 아이들의 수
 * @param boxes 각 선물 상자에 들어있는 선물 개수 벡터
 * @param wants 각 아이가 원하는 선물 개수 벡터
 * @return 모든 아이가 원하는 만큼 가져갈 수 있으면 true, 아니면 false
 */
bool canDistribute(int N, int M, const vector<int> &boxes, const vector<int> &wants) {
    // 최대 힙 생성
    priority_queue<int> pq(boxes.begin(), boxes.end());

    for (int i = 0; i < M; i++) {
        if (pq.empty()) {
            return false; // 더 이상 상자가 없는데 선물을 가져가야 하는 경우
        }

        int top = pq.top();
        pq.pop();

        if (top < wants[i]) {
            return false; // 원하는 양보다 상자에 들어있는 선물이 적은 경우
        }

        top -= wants[i];
        if (top > 0) {
            pq.push(top); // 남은 선물이 있으면 다시 힙에 넣기
        }
    }
    return true;
}

// ------------------[ Test Cases Using Google Test ]------------------

// 1) 문제 예시 입력 1
TEST(GiftTest, SampleInput1) {
    int N = 4, M = 4;
    vector<int> boxes = {4, 3, 2, 1};
    vector<int> wants = {3, 1, 2, 1};

    EXPECT_TRUE(canDistribute(N, M, boxes, wants));
}

// 2) 문제 예시 입력 2
TEST(GiftTest, SampleInput2) {
    int N = 4, M = 3;
    vector<int> boxes = {4, 3, 2, 1};
    vector<int> wants = {3, 1, 5};

    EXPECT_FALSE(canDistribute(N, M, boxes, wants));
}

// 3) 단순 케이스: 상자 1개, 아이 1명
TEST(GiftTest, SingleBoxSingleChild) {
    int N = 1, M = 1;
    vector<int> boxes = {10};
    vector<int> wants = {10};

    // 정확히 원하는 만큼 가져갈 수 있으므로 true
    EXPECT_TRUE(canDistribute(N, M, boxes, wants));
}

// 4) 조금 더 응용된 케이스: 여러 아이가 적은 양을 가져가는 경우
TEST(GiftTest, MultipleChildrenSmallWants) {
    int N = 3, M = 3;
    vector<int> boxes = {5, 3, 2};
    vector<int> wants = {2, 2, 1};

    // 문제 없이 모두 가져갈 수 있으므로 true
    EXPECT_TRUE(canDistribute(N, M, boxes, wants));
}

// 5) 아이가 너무 많이 가져가려고 하는 경우
TEST(GiftTest, OverWantsCase) {
    int N = 2, M = 2;
    vector<int> boxes = {2, 2};
    vector<int> wants = {3, 1};

    // 첫 번째 아이가 3개를 원하므로 실패해야 함(false)
    EXPECT_FALSE(canDistribute(N, M, boxes, wants));
}

// Google Test 실행을 위한 main 함수
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

