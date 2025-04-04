#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

#ifdef UNIT_TESTS
#include <gtest/gtest.h>
#endif

using namespace std;

// 주어진 3N명의 참가자 연령으로부터, 크루의 에너지 차이의 최소값을 구하는 함수.
long long minEnergyDiff(int N, const vector<long long>& ages) {
    vector<long long> v = ages;  // 원본 배열을 복사
    sort(v.begin(), v.end());
    long long ans = numeric_limits<long long>::max();
    
    // k는 가운데 구간에서 시작 인덱스를 의미하며, [N, 2N] 범위 내에서 후보 구간을 선택합니다.
    for (int k = N; k <= 2 * N; k++) {
        ans = min(ans, v[k + N - 1] - v[k]);
    }
    return ans;
}

#ifndef UNIT_TESTS
// 실제 입출력을 위한 main 함수
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
// gtest를 위한 main 함수
TEST(MinEnergyDiffTest, SampleTest) {
    int N = 2;
    vector<long long> ages = {21, 22, 23, 24, 25, 26};
    // 문제 예시에서 크루를 구성하면 에너지 차이가 1이 되어야 합니다.
    EXPECT_EQ(minEnergyDiff(N, ages), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif

