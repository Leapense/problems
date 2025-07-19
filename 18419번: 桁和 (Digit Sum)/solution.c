#include <stdio.h>
#include <stdbool.h>
#define MAX_N 1000000
#define MAX_DIGIT_SUM 54

static int digit_sum(int x)
{
    int s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }

    return s;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    static bool visited[MAX_N + 1] = {false};
    static int queue[MAX_N + 1];
    int front = 0;
    int back = 0;

    visited[n] = true;
    queue[back++] = n;

    while (front < back) {
        int cur = queue[front++];
        for (int y = cur - 1; y >= cur - MAX_DIGIT_SUM && y >= 1; --y) {
            if (!visited[y] && y + digit_sum(y) == cur) {
                visited[y] = true;
                queue[back++] = y;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) {
            ++cnt;
        }
    }

    printf("%d\n", cnt);
    return 0;
}