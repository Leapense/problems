#include <gtest/gtest.h>
#include <vector>
using ll = long long;

extern std::pair<bool, ll> solve(int, int, const std::vector<std::vector<ll>>&, ll);

TEST(Sample1, YesCase){
    int N=4, M=2; ll H=9;
    std::vector<std::vector<ll>> A = {
        {4,0},
        {0,0},
        {0,2},
        {3,1}
    };
    auto [ok, val] = solve(N, M, A, H);
    EXPECT_TRUE(ok);
    EXPECT_EQ(val, 7);
}

TEST(Sample2, NoCase){
    int N=3, M=5; ll H=5;
    std::vector<std::vector<ll>> A = {
        {5,5,1,2,4},
        {2,4,2,1,4},
        {4,2,1,3,3}
    };
    auto [ok, val] = solve(N, M, A, H);
    EXPECT_FALSE(ok);
}

TEST(Sample3, NoCase2){
    int N=5, M=5; ll H=5;
    std::vector<std::vector<ll>> A = {
        {0,0,0,1,2},
        {0,4,0,0,0},
        {0,0,0,0,0},
        {2,3,1,0,6},
        {6,0,0,7,0}
    };
    auto [ok, val] = solve(N, M, A, H);
    EXPECT_FALSE(ok);
}

TEST(Sample4, YesCase2){
    int N=5, M=5; ll H=5;
    std::vector<std::vector<ll>> A = {
        {0,1,0,5,3},
        {0,3,2,0,6},
        {2,0,0,4,0},
        {0,3,0,2,0},
        {3,0,6,0,0}
    };
    auto [ok, val] = solve(N, M, A, H);
    EXPECT_TRUE(ok);
    EXPECT_EQ(val, 4);
}

TEST(Sample5, YesZero){
    int N=5, M=6; ll H=4;
    std::vector<std::vector<ll>> A = {
        {0,0,1,0,0,5},
        {0,0,0,0,0,0},
        {0,3,0,0,0,2},
        {0,4,4,0,3,0},
        {4,0,2,0,0,0}
    };
    auto [ok, val] = solve(N, M, A, H);
    EXPECT_TRUE(ok);
    EXPECT_EQ(val, 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
