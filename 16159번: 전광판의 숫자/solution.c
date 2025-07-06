#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char glyph[10][7][7] = {
    {"000000","011110","010010","010010","010010","011110","000000"},
    {"000000","000100","001100","000100","000100","000100","000000"},
    {"000000","011110","000010","011110","010000","011110","000000"},
    {"000000","011110","000010","011110","000010","011110","000000"},
    {"000000","000100","001100","010100","111110","000100","000000"},
    {"000000","011110","010000","011110","000010","011110","000000"},
    {"000000","011110","010000","011110","010010","011110","000000"},
    {"000000","011110","000010","000100","001000","001000","000000"},
    {"000000","011110","010010","011110","010010","011110","000000"},
    {"000000","011110","010010","011110","000010","011110","000000"}
};

static int match_digit(const char src[7][7]) {
    for (int d = 0; d < 10; ++d) {
        int ok = 1;
        for (int r = 0; r < 7 && ok; ++r) {
            if (memcmp(src[r], glyph[d][r], 6) != 0) ok = 0;
        }
        if (ok) return d;
    }

    return -1;
}

static int next_perm(int *a, int n) {
    int i = n - 2;
    while (i >= 0 && a[i] > a[i + 1]) --i;
    if (i < 0) return 0;

    int j = n - 1;
    while (a[j] < a[i]) --j;
    int t = a[i]; a[i] = a[j]; a[j] = t;
    for (int l = i + 1, r = n - 1; l < r; ++l, --r) {
        int tmp = a[l]; a[l] = a[r]; a[r] = tmp;
    }

    return 1;
}

int main(void) {
    char rows[7][61] = {0};
    if (scanf("%60s", rows[0]) != 1) return 0;
    int len = strlen(rows[0]);
    for (int i = 1; i < 7; ++i) scanf("%60s", rows[i]);
    int n = len / 6;
    int digits[10];
    char buf[7][7];
    for (int k = 0; k < n; ++k) {
        for (int r = 0; r < 7; ++r) {
            memcpy(buf[r], rows[r] + k * 6, 6);
            buf[r][6] = '\0';
        }

        digits[k] = match_digit(buf);
    }

    if (!next_perm(digits, n)) {
        puts("The End");
        return 0;
    }

    for (int r = 0; r < 7; ++r) {
        for (int k = 0; k < n; ++k) fputs(glyph[digits[k]][r], stdout);
        putchar('\n');
    }

    return 0;
}