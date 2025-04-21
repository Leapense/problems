#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int N, int M, const vector<long long> &A, const vector<long long> &B)
{
    vector<long long> pref(M);

    pref[0] = A[0];
    for (int i = 1; i < M; i++)
        pref[i] = pref[i - 1] + A[i];

    vector<string> res(N);
    for (int i = 0; i < N; i++)
    {
        long long b = B[i];
        auto it = lower_bound(pref.begin(), pref.end(), b);
        if (it == pref.end())
            res[i] = "Go away!";
        else
            res[i] = to_string(distance(pref.begin(), it) + 1);
    }

    return res;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M))
        return 0;

    vector<long long> A(M);
    for (int i = 0; i < M; i++)
        cin >> A[i];
    vector<long long> B(N);
    for (int i = 0; i < N; i++)
        cin >> B[i];

    auto res = solve(N, M, A, B);
    for (const auto &s : res)
        cout << s << "\n";
    return 0;
}
#endif

#ifdef UNIT_TEST
#include <gtest/gtest.h>

TEST(Sample1, Basic)
{
    int N = 10, M = 10;
    vector<long long> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<long long> B = {3, 6, 10, 15, 21, 28, 37, 45, 55, 66};
    vector<string> exp = {"2", "3", "4", "5", "6", "7", "9", "9", "10", "Go away!"};
    EXPECT_EQ(solve(N, M, A, B), exp);
}

TEST(Sample2, Large)
{
    int N = 4, M = 10;
    vector<long long> A(10, 1000000000LL);
    vector<long long> B = {1000000000LL, 1000000000000LL, 10000000001LL, 10000000000LL};
    vector<string> exp = {"1", "Go away!", "Go away!", "10"};
    EXPECT_EQ(solve(N, M, A, B), exp);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif