#include <stdio.h>
#include <string.h>

#define MAX_GROUPS 1000
#define MAX_NAME_LEN 21

typedef struct {
    char name[MAX_NAME_LEN];
    long long left_count;
    long long right_count;
    long long any_count;
} TypeCount;

static int find_index(TypeCount types[], int size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(types[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    TypeCount types[MAX_GROUPS];
    int unique_types = 0;
    for (int i = 0; i < MAX_GROUPS; i++) {
        types[i].name[0] = '\0';
        types[i].left_count = 0;
        types[i].right_count = 0;
        types[i].any_count = 0;
    }

    for (int i = 0; i < n; i++) {
        char type_name[MAX_NAME_LEN];
        char fit[6];
        long long k;
        if (scanf("%20s %5s %lld", type_name, fit, &k) != 3) {
            return 0;
        }

        int idx = find_index(types, unique_types, type_name);
        if (idx == -1) {
            idx = unique_types++;
            strncpy(types[idx].name, type_name, MAX_NAME_LEN - 1);
            types[idx].name[MAX_NAME_LEN - 1] = '\0';
        }
        if (strcmp(fit, "left") == 0) {
            types[idx].left_count += k;
        } else if (strcmp(fit, "right") == 0) {
            types[idx].right_count += k;
        } else {
            types[idx].any_count += k;
        }
    }

    long long safe_without_pair = 0;
    int pair_exists = 0;

    for (int i = 0; i < unique_types; i++) {
        long long l = types[i].left_count;
        long long r = types[i].right_count;
        long long a = types[i].any_count;

        if ((l > 0 && r > 0) || (a >= 2) || (a > 0 && (l > 0 || r > 0))) {
            pair_exists = 1;
        }

        if (l + r > 0) {
            safe_without_pair += (l > r ? l : r);
        } else if (a > 0) {
            safe_without_pair += 1;
        }
    }

    if (!pair_exists) {
        printf("impossible\n");
    } else {
        printf("%lld\n", safe_without_pair + 1);
    }

    return 0;
}