#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cassert>

#include <gtest/gtest.h>
using namespace std;

int countPayForPancakes(const std::vector<int>& pancakes) {
    int left = 0, right = static_cast<int>(pancakes.size()) - 1;
    int countPay = 0;
    int currentMax = 0;

    while (left <= right) {
        if (pancakes[left] <= pancakes[right]) {
            if (pancakes[left] >= currentMax) {
                currentMax = pancakes[left];
                countPay++;
            }
            left++;
        } else {
            if (pancakes[right] >= currentMax) {
                currentMax = pancakes[right];
                countPay++;
            }
            right--;
        }
    }

    return countPay;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> pancakes(N);
        for (int i = 0; i < N; i++) {
            cin >> pancakes[i];
        }

        int result = countPayForPancakes(pancakes);
        cout << "Case #" << t << ": " << result << "\n";
    }

    return 0;
}
#endif

#ifdef UNIT_TEST

TEST(PancakeDequeTest, SampleTest1) {
    std::vector<int> pancakes = {1, 5};
    EXPECT_EQ(countPayForPancakes(pancakes), 2);
}

TEST(PancakeDequeTest, SampleTest2) {
    std::vector<int> pancakes = {1, 4, 2, 3};
    EXPECT_EQ(countPayForPancakes(pancakes), 3);
}

TEST(PancakeDequeTest, AllEqualTest) {
    std::vector<int> pancakes = {10, 10, 10, 10, 10};
    EXPECT_EQ(countPayForPancakes(pancakes), 5);
}

TEST(PancakeDequeTest, MixedTest) {
    std::vector<int> pancakes = {7, 1, 3, 1000000};
    EXPECT_EQ(countPayForPancakes(pancakes), 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
