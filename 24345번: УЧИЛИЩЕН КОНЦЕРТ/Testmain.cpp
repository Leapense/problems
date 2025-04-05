#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

ll minimumTime(int N, const vector<int>& T) {
    int K = T.size();
    int minT = *min_element(T.begin(), T.end());
    ll lo = 1, hi = static_cast<ll>(minT) * N, ans = hi;

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        ll total = 0;
        for (int i = 0; i < K; i++) {
            total += mid / T[i];
            if (total >= N) break;
        }

        if (total >= N) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

TEST(ConcertTest, SampleTest1) {
    int N = 3, K = 2;
    vector<int> T = {10, 15};
    EXPECT_EQ(minimumTime(N, T), 20);
}

TEST(ConcertTest, SingleComputerSingleDVD) {
    int N = 1, K = 1;
    vector<int> T = {100};
    EXPECT_EQ(minimumTime(N, T), 100);
}

TEST(ConcertTest, MultipleComputersTest) {
    int N = 5, K = 3;
    vector<int> T = {2, 3, 4};
    EXPECT_EQ(minimumTime(N, T), 6);
}

TEST(ConcertTest, MixedSpeedTest) {
    int N = 10;
    vector<int> T = {1, 2, 3};
    EXPECT_EQ(minimumTime(N, T), 6);
}

TEST(ConcertTest, EdgeCaseTest) {
    int N = 1000;
    vector<int> T(100, 100);
    EXPECT_EQ(minimumTime(N, T), 1000);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
