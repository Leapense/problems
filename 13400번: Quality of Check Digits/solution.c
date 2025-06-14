#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10
#define BASIC_IDS 10000U
#define SINGLE_DIGIT_ERRORS_PER_ID 45U
#define SWAP_ERRORS_PER_ID 4U
#define TOTAL_ERRORS_PER_ID 49U

static int check_number(const int table[TABLE_SIZE][TABLE_SIZE], const int digits[5]) {
    int state = 0;
    for (int i = 0; i < 5; ++i) {
        state = table[state][digits[i]];
    }
    return state;
}

static inline int compute_check_digit(const int table[TABLE_SIZE][TABLE_SIZE], int a, int b, int c, int d) {
    int state = 0;
    state = table[state][a];
    state = table[state][b];
    state = table[state][c];
    state = table[state][d];
    return state;
}

static bool has_undetected_error(const int table[TABLE_SIZE][TABLE_SIZE], int a, int b, int c, int d) {
    const int e = compute_check_digit(table, a, b, c, d);

    int digits[5] = {a, b, c, d, e};
    for (int pos = 0; pos < 5; ++pos) {
        const int original = digits[pos];
        for (int repl = 0; repl < TABLE_SIZE; ++repl) {
            if (repl == original) {
                continue;
            }

            digits[pos] = repl;
            if (check_number(table, digits) == 0) {
                return true;
            }
        }

        digits[pos] = original;
    }

    for (int pos = 0; pos < 4; ++pos) {
        if (digits[pos] == digits[pos + 1]) {
            continue;
        }

        const int tmp = digits[pos];
        digits[pos] = digits[pos + 1];
        digits[pos + 1] = tmp;

        if (check_number(table, digits) == 0) {
            return true;
        }

        digits[pos + 1] = digits[pos];
        digits[pos] = tmp;
    }

    return false;
}

int main(void)
{
    int table[TABLE_SIZE][TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (int j = 0; j < TABLE_SIZE; ++j) {
            if (scanf("%d", &table[i][j]) != 1) {
                return 0;
            }
        }
    }

    unsigned bad_id_counter = 0U;

    for (int a = 0; a < 10; ++a) {
        for (int b = 0; b < 10; ++b) {
            for (int c = 0; c < 10; ++c) {
                for (int d = 0; d < 10; ++d) {
                    if (has_undetected_error(table, a, b, c, d)) {
                        ++bad_id_counter;
                    }
                }
            }
        }
    }

    printf("%u\n", bad_id_counter);
    return 0;
}