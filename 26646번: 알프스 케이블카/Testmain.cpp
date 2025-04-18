#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
using ll = long long;

ll solve_alps(const vector<ll>& H) {
    int N = H.size();
    if (N == 0) return 0;
    if (N == 1) return 2 * H[0] * H[0];
    ll ans = 0;
    ans += 2LL * H[0] * H[0];
    ans += 2LL * H[N - 1] * H[N - 1];
    for (int i = 1; i < N - 1; i++) {
        ans += 4LL * H[i] * H[i];
    }

    return ans;
}

TEST(AlpsCableCarTest, Sample1) {
    vector<ll> H = {4, 2, 3, 4};
    EXPECT_EQ(solve_alps(H), 116LL);
}

TEST(AlpsCableCarTest, Sample2) {
    vector<ll> H = {1, 1};
    EXPECT_EQ(solve_alps(H), 4LL);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
