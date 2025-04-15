#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

int calculate_min_moves(int n, const std::vector<std::string>& grid) {
    if (n <= 0) {
        return 0;
    }

    int min_r = n;
    int max_r = -1;
    int min_c = n;
    int max_c = -1;
    bool found_g = false;

    for (int r = 0; r < n; ++r) {
        if (grid.size() <= r || grid[r].length() != n) {
            continue;
        }

        for (int c = 0; c < n; ++c) {
            if (grid[r][c] == 'G') {
                min_r = std::min(min_r, r);
                max_r = std::max(max_r, r);
                min_c = std::min(min_c, c);
                max_c = std::max(max_c, c);
                found_g = true;
            }
        }
    }

    if (!found_g) {
        return 0;
    }

    if (min_r == max_r && min_c == max_c) {
        return 0;
    }

    int vertical_moves = 0;
    if (min_r < max_r) {
        vertical_moves = std::min(max_r, n - 1 - min_r);
    }

    int horizontal_moves = 0;
    if (min_c < max_c) {
        horizontal_moves = std::min(max_c, n - 1 - min_c);
    }

    return vertical_moves + horizontal_moves;
}

class GomgomTests : public ::testing::Test {
    protected:
};

TEST_F(GomgomTests, Sample1) {
    int n = 3;
    std::vector<std::string> grid = {
        ".G.",
        "G.G",
        ".G."
    };
    ASSERT_EQ(4, calculate_min_moves(n, grid));
}

TEST_F(GomgomTests, Sample2) {
    int n = 4;
    std::vector<std::string> grid = {
        "..G.",
        "G...",
        "...G",
        "...."
    };
    ASSERT_EQ(5, calculate_min_moves(n, grid));
}

TEST_F(GomgomTests, SingleGomgom) {
    int n = 2;
    std::vector<std::string> grid = {
        "G.",
        ".."
    };

    ASSERT_EQ(0, calculate_min_moves(n, grid));
}

TEST_F(GomgomTests, SingleGomgom2) {
    int n = 5;
    std::vector<std::string> grid = {
        ".....",
        ".....",
        "..G..",
        ".....",
        "....."
    };

    ASSERT_EQ(0, calculate_min_moves(n, grid));
}

TEST_F(GomgomTests, RowLine) {
    int n = 5;
    std::vector<std::string> grid = {
        ".....",
        ".GGG.",
        ".....",
        ".....",
        "....."
    };

    ASSERT_EQ(3, calculate_min_moves(n, grid));
}

TEST_F(GomgomTests, ColumnLine) {
    int n = 4;
    std::vector<std::string> grid = {
        "..G.",
        "..G.",
        "..G.",
        "..G."
    };

    ASSERT_EQ(3, calculate_min_moves(n, grid));
}

TEST_F(GomgomTests, Corners) {
    int n = 4;
    std::vector<std::string> grid = {
        "G..G",
        "....",
        "....",
        "G..G"
    };

    ASSERT_EQ(6, calculate_min_moves(n, grid));
}

TEST_F(GomgomTests, FilledSquare) {
    int n = 2;
    std::vector<std::string> grid = {
        "GG",
        "GG"
    };

    ASSERT_EQ(2, calculate_min_moves(n, grid));
}

TEST_F(GomgomTests, Diagonal) {
    int n = 3;
    std::vector<std::string> grid = {
        "G..",
        ".G.",
        "..G"
    };

    ASSERT_EQ(4, calculate_min_moves(n, grid));
}

TEST_F(GomgomTests, LargeSparse) {
    int n = 10;
    std::vector<std::string> grid(n, std::string(n, '.'));
    grid[2][3] = 'G';
    grid[7][8] = 'G';
    ASSERT_EQ(13, calculate_min_moves(n, grid));
}

TEST_F(GomgomTests, LargeEdges) {
    int n = 10;
    std::vector<std::string> grid(n, std::string(n, '.'));
    grid[0][0] = 'G';
    grid[9][9] = 'G';
    ASSERT_EQ(18, calculate_min_moves(n, grid));
}

TEST_F(GomgomTests, AlreadyConverged) {
    int n = 5;
    std::vector<std::string> grid = {
        ".....",
        ".....",
        "..G..",
        ".....",
        "....."
    };

    grid[2][2] = 'G';
    ASSERT_EQ(0, calculate_min_moves(n, grid));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}