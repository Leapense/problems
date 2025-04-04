#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(istream &in, ostream &out) {
    int N;
    in >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        in >> A[i];
    }

    const int MAX_BIT = 20;
    vector<int> bitCount(MAX_BIT, 0);

    for (int x : A) {
        for (int bit = 0; bit < MAX_BIT; bit++) {
            if (x & (1 << bit)) {
                bitCount[bit]++;
            }
        }
    }

    int ans = 0;
    for (int cnt : bitCount) {
        ans = max(ans, cnt);
    }

    out << ans << "\n";
}

#ifdef UNIT_TESTS
#include <gtest/gtest.h>

TEST(SampleTest, ExampleTest) {
    string input = "5\n5 6 7 11 15\n";
    string expected_output = "4\n";

    istringstream iss(input);
    ostringstream oss;

    solve(iss, oss);
    EXPECT_EQ(oss.str(), expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#else
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
#endif
