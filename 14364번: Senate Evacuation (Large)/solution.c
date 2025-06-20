#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PARTY 26
#define MAX_STEP 2000

typedef struct {
    int count;
    int index;
} party_t;

static int cmp_desc(const void *a, const void *b)
{
    const party_t *lhs = a;
    const party_t *rhs = b;
    return rhs->count - lhs->count;
}

static bool has_majority(const int *arr, int n, int total)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > total / 2)
        {
            return true;
        }
    }
    return false;
}

static void solve_single_case(int tc)
{
    int n = 0;
    if (scanf("%d", &n) != 1)
    {
        return;
    }

    int remain[MAX_PARTY] = {0};
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &remain[i]);
        total += remain[i];
    }

    char plan[MAX_STEP][3];
    int step = 0;

    while (total > 0)
    {
        party_t list[MAX_PARTY];
        for (int i = 0; i < n; ++i)
        {
            list[i].count = remain[i];
            list[i].index = i;
        }

        qsort(list, n, sizeof(list[0]), cmp_desc);

        char action[3] = {0};

        remain[list[0].index]--;
        action[0] = (char)('A' + list[0].index);
        total--;

        if (total > 0 && has_majority(remain, n, total)) {
            remain[list[1].index]--;
            action[1] = (char)('A' + list[1].index);
            total--;
        }
        strcpy(plan[step++], action);
    }

    printf("Case #%d:", tc);
    for (int i = 0; i < step; ++i)
    {
        printf(" %s", plan[i]);
    }
    puts("");
}

int main(void)
{
    int t = 0;
    if (scanf("%d", &t) != 1)
    {
        return EXIT_FAILURE;
    }
    for (int tc = 1; tc <= t; ++tc)
    {
        solve_single_case(tc);
    }

    return EXIT_SUCCESS;
}