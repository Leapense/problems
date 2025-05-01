#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "solution.cpp"

int solve_from_stream(std::istream &in, std::ostream &out);

TEST(FruitTanghulu, AllSame)
{
    istringstream in("3\n1 1 1\n");
    ostringstream out;
    solve_from_stream(in, out);
    EXPECT_EQ(out.str(), "3\n");
}

TEST(FruitTanghulu, TwoTypesOptimal)
{
    istringstream in("5\n5 1 1 2 1\n");
    ostringstream out;
    solve_from_stream(in, out);
    EXPECT_EQ(out.str(), "4\n");
}

TEST(FruitTanghulu, AllDistinct)
{
    istringstream in("9\n1 2 3 4 5 6 7 8 9\n");
    ostringstream out;
    solve_from_stream(in, out);
    EXPECT_EQ(out.str(), "2\n");
}

TEST(FruitTanghulu, MixedMiddle)
{
    istringstream in("8\n3 3 4 5 3 3 4 4\n");
    ostringstream out;
    solve_from_stream(in, out);
    EXPECT_EQ(out.str(), "4\n");
}

int solve_from_stream(istream &in, ostream &out)
{
    int N;
    in >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++)
    {
        in >> S[i];
    }

    array<int, 10> freq{};
    int distinct = 0, left = 0, best = 0;

    for (int right = 0; right < N; right++)
    {
        if (freq[S[right]]++ == 0)
        {
            distinct++;
        }
        while (distinct > 2)
        {
            if (--freq[S[left]] == 0)
            {
                distinct--;
            }
            left++;
        }
        best = max(best, right - left + 1);
    }

    out << best << "\n";
    return 0;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}