#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int k, n;
    if (scanf("%d %d", &k, &n) != 2) {
        return 0;
    }

    int* first_residue_index = (int*)malloc((size_t)k * sizeof(int));
    if (first_residue_index == NULL) {
        return 0;
    }
    for (int i = 0; i < k; ++i) {
        first_residue_index[i] = -1;
    }

    int prefix = 0;
    int start_index = -1;
    int end_index = -1;

    for (int i = 0; i < k; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            free(first_residue_index);
            return 0;
        }
        prefix = (prefix + (value % k)) % k;
        if (prefix == 0) {
            start_index = 0;
            end_index = i;
            break;
        }
        if (first_residue_index[prefix] != -1) {
            start_index = first_residue_index[prefix] + 1;
            end_index = i;
            break;
        }
        first_residue_index[prefix] = i;
    }

    for (int i = k; i < n; ++i) {
        int discard;
        if (scanf("%d", &discard) != 1) {
            free(first_residue_index);
            return 0;
        }
    }

    if (start_index == -1 || end_index == -1) {
        printf("no kravaiche\n");
        free(first_residue_index);
        return 0;
    }

    for (int i = start_index; i <= end_index; ++i) {
        if (i > start_index) {
            putchar(' ');
        }
        printf("%d", i + 1);
    }
    putchar('\n');

    free(first_residue_index);
    return 0;
}