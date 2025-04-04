#include <iostream>
#include <vector>
#include <algorithm>
#ifdef UNIT_TESTS
#include <gtest/gtest.h>
#endif

using namespace std;

long long minEnergyDiff(int N, const vector<long long>& ages) {
    vector<long long> v = ages; // 원본 복사
    sort(v.begin(), v.end());
    long long ans = v[2 * N - 1] - v[N];
    return ans;
}

#ifndef UNIT_TESTS
// 실제 입출력용 main 함수
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int total = 3 * N;
    vector<long long> ages(total);
    for (int i = 0; i < total; i++) {
        cin >> ages[i];
    }
    cout << minEnergyDiff(N, ages) << "\n";
    return 0;
}
#else
// gtest를 위한 테스트 코드
TEST(MinEnergyDiffTest, SampleTest) {
    int N = 2;
    vector<long long> ages = {21, 22, 23, 24, 25, 26};
    // 문제 예시: {21,22,23,24,25,26}인 경우, 올바른 답은 1이어야 함.
    EXPECT_EQ(minEnergyDiff(N, ages), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif

