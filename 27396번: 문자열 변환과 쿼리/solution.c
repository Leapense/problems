#include <stdio.h>
#include <string.h>

static inline int id(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    return 26 + (c - 'a');
}

static inline char ch(int v) {
    if (v < 26) return (char)('A' + v);
    return (char)('a' + (v - 26));
}

int main(void) {
    static char S[100000 + 5];
    int n;
    if (scanf("%s %d", S, &n) != 2) return 0;

    int p[52];
    for (int i = 0; i < 52; i++) p[i] = i;

    for (int qi = 0; qi < n; ++qi) {
        int typ;
        scanf("%d", &typ);
        if (typ == 1) {
            char c1, c2;
            scanf(" %c %c", &c1, &c2);
            int a = id(c1), b = id(c2);
            for (int x = 0; x < 52; x++) if (p[x] == a) p[x] = b;
        } else {
            for (size_t i = 0, L = strlen(S); i < L; ++i) {
                int v = p[id(S[i])];
#if defined(_WIN32) || defined(_WIN64)
                putchar(ch(v));
#else
                putchar_unlocked(ch(v));
#endif
            }
#if defined(_WIN32) || defined(_WIN64)
            putchar('\n');
#else
            putchar_unlocked('\n');
#endif
        }
    }
    return 0;
}