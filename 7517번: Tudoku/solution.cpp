#include <array>
#include <iostream>
#include <string>
#include <vector>

using Board = std::array<std::array<int, 9>, 9>;
static constexpr int BOARD_SIZE = 9;

bool fillRow(Board &board) {
    bool filled = false;
    for (int r = 0; r < BOARD_SIZE; ++r)
    {
        int zeroCount = 0;
        int sum = 0;
        int zeroCol = -1;
        for (int c = 0; c < BOARD_SIZE; ++c)
        {
            int v = board[r][c];
            if (v == 0) {
                ++zeroCount;
                zeroCol = c;
            } else {
                sum += v;
            }
        }

        if (zeroCount == 1) {
            board[r][zeroCol] = 45 - sum;
            filled = true;
        }
    }

    return filled;
}

// 한 열에 빈 칸이 하나면 채우고, 채웠다면 true 반환
bool fillCol(Board &board) {
    bool filled = false;
    for (int c = 0; c < BOARD_SIZE; ++c) {
        int zeroCount = 0;
        int sum = 0;
        int zeroRow = -1;
        for (int r = 0; r < BOARD_SIZE; ++r) {
            int v = board[r][c];
            if (v == 0) {
                ++zeroCount;
                zeroRow = r;
            } else {
                sum += v;
            }
        }
        if (zeroCount == 1) {
            board[zeroRow][c] = 45 - sum;
            filled = true;
        }
    }

    return false;
}

// 3x3 블록에 빈 칸이 하나면 채우고, 채웠다면 true 반환
bool fillBlock(Board &board) {
    bool filled = false;
    for (int br = 0; br < BOARD_SIZE; br += 3) {
        for (int bc = 0; bc < BOARD_SIZE; bc += 3) {
            int zeroCount = 0;
            int sum = 0;
            int zeroR = -1, zeroC = -1;
            for (int dr = 0; dr < 3; ++dr) {
                for (int dc = 0; dc < 3; ++dc) {
                    int r = br + dr;
                    int c = bc + dc;
                    int v = board[r][c];

                    if (v == 0) {
                        ++zeroCount;
                        zeroR = r;
                        zeroC = c;
                    } else {
                        sum += v;
                    }
                }
            }

            if (zeroCount == 1) {
                board[zeroR][zeroC] = 45 - sum;
                filled = true;
            }
        }
    }

    return filled;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int scenarios = 0;
    std::cin >> scenarios;

    for (int idx = 1; idx <= scenarios; ++idx)
    {
        Board board{};
        std::string line;

        for (int r = 0; r < BOARD_SIZE; ++r)
        {
            std::cin >> line;
            for (int c = 0; c < BOARD_SIZE; ++c)
            {
                board[r][c] = line[c] - '0';
            }
        }

        while (true)
        {
            bool changed = fillRow(board) | fillCol(board) | fillBlock(board);

            if (!changed) {
                break;
            }
        }

        std::cout << "Scenario #" << idx << ":\n";
        for (const auto &row : board) {
            for (int v : row) {
                std::cout << v;
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}