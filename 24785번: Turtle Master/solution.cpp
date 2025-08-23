#include <iostream>
#include <vector>
#include <string>
#include <string_view>

struct Turtle {
    int r = 7;
    int c = 0;
    int dir = 0;
};

constexpr int dr[] = {0, 1, 0, -1};
constexpr int dc[] = {1, 0, -1, 0};
bool is_valid(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::string> board(8);
    for (int i = 0; i < 8; ++i) {
        std::getline(std::cin, board[i]);
    }

    std::string program_str;
    std::getline(std::cin, program_str);
    std::string_view program(program_str);

    Turtle turtle;
    bool bug_found = false;

    for (const char command : program) {
        if (command == 'F') {
            int next_r = turtle.r + dr[turtle.dir];
            int next_c = turtle.c + dc[turtle.dir];
            if (!is_valid(next_r, next_c) || board[next_r][next_c] == 'C' || board[next_r][next_c] == 'I') {
                bug_found = true;
                break;
            }

            turtle.r = next_r;
            turtle.c = next_c;
        } else if (command == 'R') {
            turtle.dir = (turtle.dir + 1) % 4;
        } else if (command == 'L') {
            turtle.dir = (turtle.dir + 3) % 4;
        } else if (command == 'X') {
            int next_r = turtle.r + dr[turtle.dir];
            int next_c = turtle.c + dc[turtle.dir];
            if (!is_valid(next_r, next_c) || board[next_r][next_c] != 'I') {
                bug_found = true;
                break;
            }
            board[next_r][next_c] = '.';
        }
    }

    if (bug_found) {
        std::cout << "Bug!\n";
    } else {
        if (board[turtle.r][turtle.c] == 'D') {
            std::cout << "Diamond!\n";
        } else {
            std::cout << "Bug!\n";
        }
    }

    return 0;
}