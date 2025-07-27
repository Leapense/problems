#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 0;
    const int MAX_ID = 100000;
    int *last = (int *)calloc(MAX_ID + 1, sizeof(int));
    int *dp = (int *)calloc(n + 1, sizeof(int));
    int answer = 0;
    for (int day = 1; day <= n; ++day) {
        dp[day] = 1;
        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            int id;
            scanf("%d", &id);
            int prev = last[id];
            if (prev && dp[prev] + 1 > dp[day]) dp[day] = dp[prev] + 1;
            last[id] = day;
        }
        if (dp[day] > answer) answer = dp[day];
    }

    printf("%d\n", answer);
    free(last);
    free(dp);

    return 0;
}