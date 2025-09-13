#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1) return 0;
    char S[205];
    if (scanf("%s", S) != 1) return 0;

    int p = N;
    for (int d = 1; d < N; ++d) {
        bool ok = true;
        for (int i = d; i < N; ++i) {
            if (S[i] != S[i - d]) { ok = false; break; }
        }
        if (ok) { p = d; break; }
    }

    int ans = 1 + (N - 1) / p;
    printf("%d\n", ans);
    return 0;
}