#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <gtest/gtest.h>

using namespace std;

void solve(istream &in, ostream &out) {
    int N, M;
    long long K;
    int X;
    in >> N >> M >> K >> X;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        in >> A[i];
    }

    vector<int> rating(N + 1);
    rating[0] = X;

    for (int i = 1; i <= N; i++) {
        rating[i] = rating[i - 1] + A[i - 1];
    }

    vector<int> prefix(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + (rating[i] < K ? 1 : 0);
    }

    for (int i = 0; i < M; i++) {
        int l, r;
        in >> l >> r;
        int ans = prefix[r - 1] - prefix[l - 1];
        out << ans << "\n";
    }
}

TEST(CodepowersTest, SampleTest1) {
    string input = R"(10 6 1019 1000
7 -5 5 8 1 3 6 -7 7 10
3 6
1 5
4 5
5 9
3 8
9 11
)";
    string expected_output = R"(3
4
1
2
3
0
)";
    stringstream ss_in(input), ss_out;
    solve(ss_in, ss_out);
    EXPECT_EQ(ss_out.str(), expected_output);
}

TEST(CodepowersTest, SampleTest2) {
    string input = R"(1 1 0 -5
3
1 2
)";
    string expected_output = "1\n";
    stringstream ss_in(input), ss_out;
    solve(ss_in, ss_out);
    EXPECT_EQ(ss_out.str(), expected_output);
}

TEST(CodepowersTest, AllAboveThreshold) {
    string input = R"(4 1 10 10
5 5 5 5
1 5
)";
    string expected_output = "0\n";
    stringstream ss_in(input), ss_out;
    solve(ss_in, ss_out);
    EXPECT_EQ(ss_out.str(), expected_output);
}

TEST(CodepowersTest, MixedValuesTest) {
    string input = R"(5 2 0 0
-5 10 -10 5 -1
1 6
2 4
)";
    string expected_output = R"(3
1
)";
    stringstream ss_in(input), ss_out;
    solve(ss_in, ss_out);
    EXPECT_EQ(ss_out.str(), expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}