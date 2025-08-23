#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char type;
    int position;
} Statement;

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    Statement* statements = (Statement*)malloc((size_t)n * sizeof(Statement));
    if (statements == NULL) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf(" %c %d", &statements[i].type, &statements[i].position) != 2) {
            free(statements);
            return 1;
        }
    }

    int min_liars = n;
    for (int i = 0; i < n; ++i) {
        int candidate_location = statements[i].position;
        int current_liars = 0;
        for (int j = 0; j < n; ++j) {
            if (statements[j].type == 'G') {
                if (candidate_location < statements[j].position) {
                    current_liars++;
                }
            } else {
                if (candidate_location > statements[j].position) {
                    current_liars++;
                }
            }
        }

        if (current_liars < min_liars) {
            min_liars = current_liars;
        }
    }

    printf("%d\n", min_liars);
    free(statements);
    return 0;
}