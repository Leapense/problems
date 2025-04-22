#include <gtest/gtest.h>
#include <vector>
using namespace std;
using ll = long long;

ll findMinX(const vector<ll>& A, ll K) {
    ll lo = 0, hi = *max_element(A.begin(), A.end());
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        __int128 sum = 0;
        for (auto v : A) if (v > mid) {
            sum += v - mid;
            if (sum > K) break;
        }
        if (sum <= K) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

TEST(CandyTest, Sample1) {
    vector<ll> A = {80, 100, 50, 40};
    ll K = 80;
    EXPECT_EQ(findMinX(A, K), 50);
}

TEST(CandyTest, Sample2) {
    vector<ll> A = {80, 100, 50, 40};
    ll K = 61;
    EXPECT_EQ(findMinX(A, K), 60);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
