#include <iostream>
#include <vector>
#include <gtest/gtest.h>
using namespace std;

vector<int> findNextDifferentIndices(const vector<int>& A) {
    int N = A.size();
    vector<int> ans(N, -1);

    ans[N - 1] = -1;

    for (int i = N - 2; i >= 0; i--) 
    {
        if (A[i] != A[i + 1]) {
            ans[i] = i + 2;
        } else {
            ans[i] = ans[i + 1];
        }
    }

    return ans;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> ans = findNextDifferentIndices(A);
    for (int i = 0; i < N; i++) {
        cout << ans[i] << (i == N - 1 ? "\n" : " ");
    }

    return 0;
}
#endif

TEST(FindNextDifferentIndicesTest, SampleTest) {
    vector<int> input = {3, 3, 1, 1, 4, 4};
    vector<int> expected = {3, 3, 5, 5, -1, -1};
    vector<int> output = findNextDifferentIndices(input);
    EXPECT_EQ(output, expected);
}

TEST(FindNextDifferentIndicesTest, AllSame) {
    vector<int> input = {5, 5, 5, 5};
    vector<int> expected = {-1, -1, -1, -1};
    vector<int> output = findNextDifferentIndices(input);
    EXPECT_EQ(output, expected);
}

TEST(FindNextDifferentIndicesTest, StrictlyIncreasing) {
    vector<int> input = {1, 2, 3, 4, 5};
    vector<int> expected = {2, 3, 4, 5, -1};
    vector<int> output = findNextDifferentIndices(input);
    EXPECT_EQ(output, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
