#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static void pad_print(const char* g) {
    size_t L = strlen(g);
    for (size_t i = L; i < 4; ++i) putchar('0');
    fputs(g, stdout);
}

static int split_groups(char* buf, char out[8][5]) {
    int cnt = 0;
    if (buf[0] == '\0') return 0;
    char* tok = strtok(buf, ":");
    while (tok) {
        size_t L = strlen(tok);
        if (L > 4) L = 4;
        memcpy(out[cnt], tok, L);
        out[cnt][L] = '\0';
        cnt++;
        tok = strtok(NULL, ":");
    }

    return cnt;
}

int main(void)
{
    char s[64];
    if (!fgets(s, sizeof s, stdin)) return 0;

    size_t n = strlen(s);
    if (n && (s[n-1] == '\n' || s[n-1] == '\r')) {
        s[--n] = '\0';
        if (n && s[n-1] == '\r') s[--n] = '\0';
    }
    char left_groups[8][5], right_groups[8][5];
    int left_count = 0, right_count = 0;

    char* dbl = strstr(s, "::");
    int zeros_count = 0;

    if (dbl) {
        size_t left_len = (size_t)(dbl - s);
        char leftbuf[64];
        memcpy(leftbuf, s, left_len);
        leftbuf[left_len] = '\0';
        left_count = split_groups(leftbuf, left_groups);

        const char* rightstart = dbl + 2;
        char rightbuf[64];
        strcpy(rightbuf, rightstart);
        right_count = split_groups(rightbuf, right_groups);
        zeros_count = 8 - left_count - right_count;
    } else {
        char buf[64];
        strcpy(buf, s);
        left_count = split_groups(buf, left_groups);
        zeros_count = 0;
        right_count = 0;
    }

    for (int j = 0; j < 8; ++j) {
        if (j) putchar(':');
        if (j < left_count) {
            pad_print(left_groups[j]);
        } else if (j < left_count + zeros_count) {
            pad_print("0");
        } else {
            int idx = j - left_count - zeros_count;
            pad_print(right_groups[idx]);
        }
    }

    putchar('\n');
    return 0;
}