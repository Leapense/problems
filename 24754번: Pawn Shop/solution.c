#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int* binary_search(int key, int* base, size_t num) {
    return (int*)bsearch(&key, base, num, sizeof(int), compare_ints);
}

void solve() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        return;
    }
    int* a = (int*)malloc(sizeof(int) * n);
    int* b = (int*)malloc(sizeof(int) * n);
    int* all_values = (int*)malloc(sizeof(int) * 2 * n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        all_values[i] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        all_values[n + i] = b[i];
    }

    qsort(all_values, 2 * n, sizeof(int), compare_ints);

    int unique_count = 0;
    if (2 * n > 0) {
        unique_count = 1;
        for (int i = 1; i < 2 * n; ++i) {
            if (all_values[i] != all_values[i - 1]) {
                all_values[unique_count++] = all_values[i];
            }
        }
    }

    int* a_comp = (int*)malloc(sizeof(int) * n);
    int* b_comp = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i) {
        a_comp[i] = (int)(binary_search(a[i], all_values, unique_count) - all_values);
        b_comp[i] = (int)(binary_search(b[i], all_values, unique_count) - all_values);
    }

    free(all_values);

    int* balance = (int*)calloc(unique_count, sizeof(int));
    int unbalanced_count = 0;

    int* partition_points = (int*)malloc(sizeof(int) * n);
    int partition_count = 0;

    for (int i = 0; i < n; ++i) {
        int idx_a = a_comp[i];
        if (balance[idx_a] == 0) unbalanced_count++;
        balance[idx_a]++;
        if (balance[idx_a] == 0) unbalanced_count--;

        int idx_b = b_comp[i];
        if (balance[idx_b] == 0) unbalanced_count++;
        balance[idx_b]--;
        if (balance[idx_b] == 0) unbalanced_count--;

        if (unbalanced_count == 0) {
            partition_points[partition_count++] = i;
        }
    }

    int current_partition = 0;
    for (int i = 0; i < n; ++i) {
        printf("%d", b[i]);
        if (current_partition < partition_count && i == partition_points[current_partition]) {
            if (i < n - 1) {
                printf(" #");
            }
            current_partition++;
        }
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    free(a);
    free(b);
    free(a_comp);
    free(b_comp);
    free(balance);
    free(partition_points);
}

int main() {
    solve();
    return 0;
}