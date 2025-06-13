#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* pattern;
    int index;
} PatternInfo;

int compare_patterns(const void *a, const void *b) {
    const PatternInfo *pa = (const PatternInfo*)a;
    const PatternInfo *pb = (const PatternInfo*)b;
    return strcmp(pa->pattern, pb->pattern);
}

char to_base36(int n) {
    if (n < 10) {
        return (char)('0' + n);
    }
    return (char)('A' + (n - 10));
}

void solve() {
    int n, m, q;
    while (scanf("%d %d %d", &n, &m, &q) == 3 && (n != 0 || m != 0 || q != 0)) {
        char** s = NULL;
        char** b = NULL;

        if (q > 0) {
            s = (char**)malloc(q * sizeof(char*));
            b = (char**)malloc(q * sizeof(char*));
            for (int i = 0; i < q; ++i) {
                s[i] = (char*)malloc((n + 2) * sizeof(char));
                b[i] = (char*)malloc((m + 2) * sizeof(char));
                scanf("%s %s", s[i], b[i]);
            }
        }

        PatternInfo switch_info[36];
        for (int k = 0; k < n; ++k) {
            switch_info[k].index = k;
            switch_info[k].pattern = (char*)calloc(q + 1, sizeof(char));
        }

        if (q > 0) {
            int cumul_s[36] = {0};
            for (int i = 0; i < q; ++i) {
                for (int k = 0; k < n; ++k) {
                    cumul_s[k] ^= (s[i][k] - '0');
                    switch_info[k].pattern[i] = (char)('0' + cumul_s[k]);
                }
            }
        }

        PatternInfo* bulb_info = NULL;
        if (m > 0) {
            bulb_info = (PatternInfo*)malloc(m * sizeof(PatternInfo));
            for (int j = 0; j < m; ++j) {
                bulb_info[j].index = j;
                bulb_info[j].pattern = (char*)calloc(q + 1, sizeof(char));
                if (q > 0) {
                    for (int i = 0; i < q; ++i) {
                        bulb_info[j].pattern[i] = b[i][j];
                    }
                }
            }
        }

        if (n > 0) qsort(switch_info, n, sizeof(PatternInfo), compare_patterns);
        if (m > 0) qsort(bulb_info, m, sizeof(PatternInfo), compare_patterns);

        char* result = (char*)calloc(m + 1, sizeof(char));
        int i = 0;
        int j = 0;
        while (j < m) {
            int j_end = j;
            while (j_end < m && strcmp(bulb_info[j_end].pattern, bulb_info[j].pattern) == 0) {
                j_end++;
            }

            const char* current_bulb_pattern = bulb_info[j].pattern;

            while (i < n && strcmp(switch_info[i].pattern, current_bulb_pattern) < 0) {
                i++;
            }

            int i_start = i;
            while (i < n && strcmp(switch_info[i].pattern, current_bulb_pattern) == 0) {
                i++;
            }
            int num_matches = i - i_start;
            char res_char;

            if (num_matches == 1) {
                res_char = to_base36(switch_info[i_start].index);
            } else {
                res_char = '?';
            }

            for (int k = j; k < j_end; ++k) {
                result[bulb_info[k].index] = res_char;
            }

            j = j_end;
        }

        printf("%s\n", result);

        if (q > 0) {
            for (int i = 0; i < q; ++i) {
                free(s[i]);
                free(b[i]);
            }

            free(s);
            free(b);
        }

        for (int k = 0; k < n; ++k) {
            free(switch_info[k].pattern);
        }

        if (m > 0) {
            for (int j = 0; j < m; ++j) {
                free(bulb_info[j].pattern);
            }
            free(bulb_info);
        }
        free(result);
    }
}

int main() {
    solve();
    return 0;
}