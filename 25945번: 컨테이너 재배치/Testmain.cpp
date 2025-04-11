#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

#ifdef UNIT_TESTS
#include <gtest/gtest.h>
#endif

void solve(std::istream& in, std::ostream& out) {
    int n;
    in >> n;

    std::vector<int> containers(n);
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        in >> containers[i];
        total += containers[i];
    }

    int base = total / n;
    int r = total % n;

    std::sort(containers.begin(), containers.end(), std::greater<int>());

    long long moves = 0;

    for (int i = 0; i < r; ++i) {
        if (containers[i] > base + 1) {
            moves += containers[i] - (base + 1);
        }
    }

    for (int i = r; i < n; ++i) {
        if (containers[i] > base) {
            moves += containers[i] - base;
        }
    }

    out << moves;
}

#ifndef UNIT_TESTS
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
    return 0;
}
#else
TEST(ContainerTest, SampleTest1) {
    std::istringstream input("4\n1 2 3 3\n");
    std::ostringstream output;
    solve(input, output);
    EXPECT_EQ(output.str(), "1");
}

TEST(ContainerTest, SampleTest2) {
    std::istringstream input("8\n5 6 7 2 3 4 2 6\n");
    std::ostringstream output;
    solve(input, output);
    EXPECT_EQ(output.str(), "5");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif