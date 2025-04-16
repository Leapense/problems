#include <gtest/gtest.h>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 7;

vector<int> modPow = {0, 3, 2, 6, 4, 5, 1, 3, 2, 6, 4};
vector<int> invModPow = {0, 5, 4, 6, 2, 3, 1, 5, 4, 6, 2};

int digitCount(int num) {
    int cnt = 0;
    while (num > 0) {
        cnt++;
        num /= 10;
    }

    return cnt;
}

long long countPairs(const vector<int>& nums) {
    int n = nums.size();
    vector<int> mods(n, 0);
    vector<int> freq(7, 0);

    for (int i = 0; i < n; ++i) {
        mods[i] = nums[i] % MOD;
        freq[mods[i]]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int b = nums[i];
        int rem_b = b % MOD;
        int d = digitCount(b);
        int p = modPow[d];
        int inv_p = invModPow[d];
        int target = ((-rem_b) % MOD + MOD) % MOD;
        target = (target * inv_p) % MOD;

        int addCount = freq[target];
        if (mods[i] == target) addCount--;
        ans += addCount;
    }

    return ans;
}

TEST(AmazingDivisibilityTest, SampleTest1) {
    vector<int> nums = {127, 1996, 12};
    EXPECT_EQ(countPairs(nums), 4);
}

TEST(AmazingDivisibilityTest, SampleTest2) {
    vector<int> nums = {11, 2, 1, 12};
    EXPECT_EQ(countPairs(nums), 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
