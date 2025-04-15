#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "K-Queen.cpp"

TEST(KQueenTest, KingInCheck) {
    ll N = 8, K = 1;
    ll king_r = 4, king_c = 4;
    std::vector<Pos> queens = {{4, 8}};
    EXPECT_EQ(kqueen_status(N, K, king_r, king_c, queens), "CHECK");
}

TEST(KQueenTest, KingInCheckmate) {
    ll N = 8, K = 2;
    ll king_r = 1, king_c = 1;
    std::vector<Pos> queens = {{2, 2}, {1, 2}};
    EXPECT_EQ(kqueen_status(N, K, king_r, king_c, queens), "CHECKMATE");
}

TEST(KQueenTest, KingInStalemate) {
    ll N = 8, K = 2;
    ll king_r = 2, king_c = 2;
    std::vector<Pos> queens = {{1, 1}, {1, 3}};
    EXPECT_EQ(kqueen_status(N, K, king_r, king_c, queens), "STALEMATE");
}

TEST(KQueenTest, KingSafe) {
    ll N = 8, K = 1;
    ll king_r = 4, king_c = 4;
    std::vector<Pos> queens = {{8, 8}};
    EXPECT_EQ(kqueen_status(N, K, king_r, king_c, queens), "NONE");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}