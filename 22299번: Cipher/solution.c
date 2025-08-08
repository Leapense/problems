#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 4096
#define ALPHABET 26
#define MAX_WORD_LEN 20

static void trim_newline(char *s) {
    if (!s) return;
    size_t n = strlen(s);
    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r')) {
        s[n - 1] = '\0';
        n--;
    }
}

static int parse_int(const char *s) {
    if (!s) return 0;
    char *end = NULL;
    long v = strtol(s, &end, 10);
    return (int)v;
}

static int is_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

static char shift_char(char c, int s) {
    if (c >= 'A' && c <= 'Z') {
        int idx = c - 'A';
        idx = (idx - s) % ALPHABET;
        if (idx < 0) idx += ALPHABET;
        return (char)('A' + idx);
    }
    if (c >= 'a' && c <= 'z') {
        int idx = c - 'a';
        idx = (idx - s) % ALPHABET;
        if (idx < 0) idx += ALPHABET;
        return (char)('a' + idx);
    }
    return c;
}

static char *xstrdup(const char *s) {
    size_t n = strlen(s);
    char *p = (char *)malloc(n + 1);
    if (!p) exit(1);
    memcpy(p, s, n + 1);
    return p;
}

static char *decrypt(const char *cipher, int s) {
    size_t n = strlen(cipher);
    char *out = (char *)malloc(n + 1);
    if (!out) exit(1);
    for (size_t i = 0; i < n; i++) out[i] = shift_char(cipher[i], s);
    out[n] = '\0';
    return out;
}

static void to_lower_ascii(char *s) {
    for (; *s; ++s) {
        unsigned char c = (unsigned char)*s;
        if (c >= 'A' && c <= 'Z') *s = (char)(c - 'A' + 'a');
    }
}

static int in_list(const char *w, char **list, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(w, list[i]) == 0) return 1;
    }
    return 0;
}

static void evaluate(const char *plain, char **good, int g, char **bad, int b, int *matches, int *threats, int *totalWords) {
    int total = 0;
    int m = 0;
    int t = 0;
    size_t i = 0;
    size_t n = strlen(plain);
    while (i < n) {
        if (is_letter(plain[i])) {
            size_t j = i;
            while (j < n && is_letter(plain[j])) j++;
            size_t len = j - i;
            if (len >= 1 && len <= MAX_WORD_LEN) {
                char buf[MAX_WORD_LEN + 1];
                for (size_t k = 0; k < len && k < MAX_WORD_LEN; k++) {
                    char c = plain[i + k];
                    if (c >= 'A' && c <= 'Z') c = (char)(c - 'A' + 'a');
                    buf[k] = c;
                }
                buf[len] = '\0';
                int inBad = in_list(buf, bad, b);
                int inGood = in_list(buf, good, g);
                if (inBad || inGood) m++;
                if (inBad) t++;
                total++;
            }
            i = j;
        } else {
            i++;
        }
    }
    *matches = m;
    *threats = t;
    *totalWords = total;
}

int main(void) {
    char line[MAX_LINE];
    if (!fgets(line, sizeof(line), stdin)) return 0;
    trim_newline(line);
    int cases = parse_int(line);
    for (int tc = 0; tc < cases; tc++) {
        if (!fgets(line, sizeof(line), stdin)) return 0;
        trim_newline(line);
        int g = parse_int(line);
        char **good = (char **)malloc(sizeof(char *) * (size_t)g);
        if (!good) return 1;
        for (int i = 0; i < g; i++) {
            if (!fgets(line, sizeof(line), stdin)) return 0;
            trim_newline(line);
            good[i] = xstrdup(line);
        }
        if (!fgets(line, sizeof(line), stdin)) return 0;
        trim_newline(line);
        int b = parse_int(line);
        char **bad = (char **)malloc(sizeof(char *) * (size_t)b);
        if (!bad) return 1;
        for (int i = 0; i < b; i++) {
            if (!fgets(line, sizeof(line), stdin)) return 0;
            trim_newline(line);
            bad[i] = xstrdup(line);
        }
        if (!fgets(line, sizeof(line), stdin)) return 0;
        trim_newline(line);
        char *cipher = xstrdup(line);

        int bestMatch = -1;
        int bestThreat = 0;
        int bestTotal = 0;
        int bestShift = -1;
        int bestCountTies = 0;
        char *bestPlain = NULL;

        for (int s = 0; s < ALPHABET; s++) {
            char *plain = decrypt(cipher, s);
            int m = 0, t = 0, tot = 0;
            evaluate(plain, good, g, bad, b, &m, &t, &tot);
            if (m > bestMatch) {
                if (bestPlain) free(bestPlain);
                bestPlain = plain;
                bestMatch = m;
                bestThreat = t;
                bestTotal = tot;
                bestShift = s;
                bestCountTies = 1;
            } else if (m == bestMatch) {
                bestCountTies++;
                free(plain);
            } else {
                free(plain);
            }
        }

        if (bestCountTies != 1) {
            printf("Unable to decipher\n");
            if (bestPlain) free(bestPlain);
        } else {
            printf("%s\n", bestPlain);
            int M = 0;
            int T = 0;
            if (bestTotal > 0) {
                M = (bestMatch * 100 + bestTotal / 2) / bestTotal;
                T = (bestThreat * 100 + bestTotal / 2) / bestTotal;
            }
            printf("Shift: %d, Match: %d%%, Threat: %d%%\n", bestShift, M, T);
            free(bestPlain);
        }

        free(cipher);
        for (int i = 0; i < g; i++) free(good[i]);
        for (int i = 0; i < b; i++) free(bad[i]);
        free(good);
        free(bad);
    }
    return 0;
}