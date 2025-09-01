#include <stdio.h>
#include <stdlib.h>

int cmp_desc(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int main(void) {
    char line[1000];
    while (fgets(line, sizeof(line), stdin)) {
        int capacity;
        int weights[1000];
        int n = 0;

        char *ptr = line;
        if (sscanf(ptr, "%d", &capacity) != 1) continue;

        ptr = line;
        int value;
        int first = 1;
        while (sscanf(ptr, "%d", &value) == 1) {
            if (first) {
                first = 0;
            } else {
                weights[n++] = value;
            }

            while (*ptr && *ptr != ' ') ptr++;
            while (*ptr == ' ') ptr++;
        }

        qsort(weights, n, sizeof(int), cmp_desc);

        int bins[1000];
        int binCount = 0;

        for (int i = 0; i < n; i++) {
            int placed = 0;
            for (int j = 0; j < binCount; j++) {
                if (bins[j] >= weights[i]) {
                    bins[j] -= weights[i];
                    placed = 1;
                    break;
                }
            }
            if (!placed) {
                bins[binCount++] = capacity - weights[i];
            }
        }

        printf("%d\n", binCount);
    }

    return 0;
}