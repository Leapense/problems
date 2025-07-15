#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INF 2147483647
#define MAX_M 100000
#define MAX_W 1000

int min(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    // 코드 작성
    int n;
    int m;
    scanf("%d %d", &n, &m);

    int snacks[100][2];
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &snacks[i][0], &snacks[i][1]);
    }

    int* dp = (int*)malloc(sizeof(int) * (m + MAX_W));
    if (dp == NULL) {
        return 1;
    }

    for (int i = 1; i < m + MAX_W; ++i) {
        dp[i] = INF;
    }

    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        int w = snacks[i][0];
        int h = snacks[i][1];
        for (int j = m + MAX_W - 1; j >= w; --j) {
            if (dp[j - w] != INF) {
                dp[j] = min(dp[j], dp[j - w] + h);
            }
        }
    }

    int min_satisfaction = INF;
    for (int i = m; i < m + MAX_W; ++i) {
        min_satisfaction = min(min_satisfaction, dp[i]);
    }

    if (min_satisfaction == INF) {
        printf("죄송합니다 한승엽 병장님\n");
    } else {
        printf("%d\n", min_satisfaction);
    }

    free(dp);
    return 0;
}