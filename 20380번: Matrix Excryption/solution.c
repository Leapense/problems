#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_D 10
#define MAX_LEN 80
#define ALPHABET 30

static int char_to_val(char c)
{
    if (c >= 'A' && c <= 'Z') return c - 'A' + 1;
    if (c == ' ') return 27;
    if (c == ',') return 28;
    if (c == '.') return 29;
    return 30;
}

static char val_to_char(int v)
{
    if (v >= 1 && v <= 26) return (char)('A' + v - 1);
    if (v == 27) return ' ';
    if (v == 28) return ',';
    if (v == 29) return '.';
    return '?';
}

static int normalize(int x)
{
    int v = x % ALPHABET;
    if (v <= 0) v += ALPHABET;
    return v;
}

int main(void)
{
    int d;
    while (scanf("%d", &d) == 1 && d) {
        int m[MAX_D][MAX_D];
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j < d; ++j) {
                scanf("%d", &m[i][j]);
            }
        }

        int ch = getchar();
        (void)ch;

        char raw[MAX_LEN + 2];
        if (!fgets(raw, sizeof raw, stdin)) return 0;
        size_t len = strcspn(raw, "\n");
        raw[len] = '\0';

        int values[(MAX_LEN + MAX_D) * 2];
        size_t vlen = 0;
        for (size_t i = 0; i < len; ++i) {
            values[vlen++] = char_to_val(raw[i]);
        }

        while (vlen % d) values[vlen++] = 27;
        char output[(MAX_LEN + MAX_D) * 2];
        size_t out_len = 0;
        for (size_t idx = 0; idx < vlen; idx += d)
        {
            for (int row = 0; row < d; ++row)
            {
                int sum = 0;
                for (int col = 0; col < d; ++col)
                {
                    sum += m[row][col] * values[idx + col];
                }
                output[out_len++] = val_to_char(normalize(sum));
            }
        }

        output[out_len] = '\0';
        printf("'%s'\n", output);
    }

    return 0;
}