#include <iostream>
#include <vector>
#include <string>

static void process_line(std::vector<int> &line) {
    std::vector<int> buffer;
    buffer.reserve(line.size());

    for (auto v : line) {
        if (v != 0) {
            buffer.push_back(v);
        }
    }

    for (size_t i = 0; i + 1 < buffer.size(); ++i) {
        if (buffer[i] == buffer[i + 1]) {
            buffer[i] *= 2;
            buffer[i + 1] = 0;
            ++i;
        }
    }

    std::vector<int> result;
    result.reserve(line.size());
    for (auto v : buffer) {
        if (v != 0) {
            result.push_back(v);
        }
    }
    result.resize(line.size(), 0);
    line.swap(result);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        std::string dir;
        std::cin >> N >> dir;

        std::vector<std::vector<int>> board(N, std::vector<int>(N));
        for (auto &row : board) {
            for (auto &cell : row) {
                std::cin >> cell;
            }
        }

        if (dir == "left") {
            for (auto &row : board) {
                process_line(row);
            }
        } else if (dir == "right") {
            for (auto &row : board) {
                std::reverse(row.begin(), row.end());
                process_line(row);
                std::reverse(row.begin(), row.end());
            }
        } else if (dir == "up") {
            for (int j = 0; j < N; ++j) {
                std::vector<int> col(N);
                for (int i = 0; i < N; ++i) {
                    col[i] = board[i][j];
                }
                process_line(col);
                for (int i = 0; i < N; ++i) {
                    board[i][j] = col[i];
                }
            }
        } else {
            for (int j = 0; j < N; ++j) {
                std::vector<int> col(N);
                for (int i = 0; i < N; ++i) {
                    col[i] = board[N - 1 - i][j];
                }
                process_line(col);
                for (int i = 0; i < N; ++i) {
                    board[N - 1 - i][j] = col[i];
                }
            }
        }

        std::cout << "Case #" << tc << ":\n";
        for (const auto &row : board) {
            for (size_t j = 0; j < row.size(); ++j) {
                std::cout << row[j] << (j + 1 < row.size() ? ' ' : '\n');
            }
        }
    }

    return 0;
}