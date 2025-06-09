#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_S 100
#define MAX_LEN 101

int main(void)
{
    int N = 0;
    if (scanf("%d", &N) != 1) {
        return EXIT_FAILURE;
    }

    for (int tc = 1; tc <= N; ++tc) {
        int S = 0;
        scanf("%d\n", &S);

        char engines[MAX_S][MAX_LEN];
        for (int i = 0; i < S; ++i) {
            fgets(engines[i], MAX_LEN, stdin);
            size_t len = strlen(engines[i]);
            if (len > 0 && engines[i][len - 1] == '\n') {
                engines[i][len - 1] = '\0';
            }
        }

        int Q = 0;
        scanf("%d\n", &Q);

        bool seen[MAX_S] = { false };
        int countSeen = 0;
        int switches = 0;

        char query[MAX_LEN];
        for (int i = 0; i < Q; ++i) {
            fgets(query, MAX_LEN, stdin);
            size_t len = strlen(query);
            if (len > 0 && query[len - 1] == '\n') {
                query[len - 1] = '\0';
            }

            int id = -1;
            for (int j = 0; j < S; ++j) {
                if (strcmp(engines[j], query) == 0) {
                    id = j;
                    break;
                }
            }

            if (id < 0) {
                continue;
            }

            if (!seen[id]) {
                seen[id] = true;
                ++countSeen;
            }

            if (countSeen == S) {
                ++switches;
                for (int j = 0; j < S; ++j) {
                    seen[j] = false;
                }

                seen[id] = true;
                countSeen = 1;
            }
        }

        printf("Case #%d: %d\n", tc, switches);
    }

    return EXIT_SUCCESS;
}