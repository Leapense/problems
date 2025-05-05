#define UNIT_TEST
#include "solution.cpp"
#undef main

#include <gtest/gtest.h>
#include <random>

int64 run(const vector<int64> &h)
{
    vector<int64> v = h;
    sort(v.begin(), v.end(), greater<>());

    int n = (int)v.size();
    auto pow2 = buildPow2(n);

    int64 ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = (ans + v[i] % MOD * pow2[n - 1 - i]) % MOD;
    }

    return ans;
}

TEST(Sample, Provided)
{
    vector<int64> h = {2, 10};
    EXPECT_EQ(run(h), 22);
}

TEST(Single, N1)
{
    vector<int64> h = {123456789};
    EXPECT_EQ(run(h), 123456789 % MOD);
}

TEST(RandomSmall, Brute)
{
    std::mt19937_64 rng(0);
    for (int n = 1; n <= 9; ++n)
    {
        for (int it = 0; it < 200; ++it)
        {
            vector<int64> h(n);
            for (auto &x : h)
                x = rng() % 50 + 1;

            int64 best = 0;
            vector<int> idx(n);

            iota(idx.begin(), idx.end(), 0);
            do
            {
                vector<int64> cur = h;
                vector<int64> order(n);
                for (int i = 0; i < n; ++i)
                    order[i] = cur[idx[i]];

                vector<int64> ht = h;
                for (int i = 0; i < n; ++i)
                {
                    int pos = idx[i];
                    int64 val = ht[pos];
                    for (int j = 0; j < n; ++j)
                    {
                        if (j != pos)
                            ht[j] += val;
                    }
                }

                best = max(best, *max_element(ht.begin(), ht.end()));
            } while (next_permutation(idx.begin(), idx.end()));

            EXPECT_EQ(best % MOD, run(h));
        }
    }
}