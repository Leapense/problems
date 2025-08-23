#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Turtle {
    int r;
    int c;
    int dir;
};

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

bool is_valid(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

int main(void)
{
    char board[8][10];
    for (int i = 0; i < 8; ++i) {
        fgets(board[i], sizeof(board[i]), stdin);
    }

    char program[1024];
    fgets(program, sizeof(program), stdin);
    program[strcspn(program, "\n")] = 0;

    struct Turtle turtle = {7, 0, 0};
    bool bug_found = false;

    for (size_t i = 0; i < strlen(program); ++i) {
        char command = program[i];
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
        puts("Bug!");
    } else {
        if (board[turtle.r][turtle.c] == 'D') {
            puts("Diamond!");
        } else {
            puts("Bug!");
        }
    }

    return 0;
}