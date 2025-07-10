#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int N, a, b;
  if (scanf("%d %d %d", &N, &a, &b) != 3)
    return 0;

  int *dp = (int *)malloc((N + 1) * sizeof(int));
  if (!dp)
    return 0;

  dp[0] = 0;
  for (int i = 1; i <= N; ++i) {
    int best = dp[i - 1] + 1;
    if (i >= a + 1) {
      int cand = dp[i - 1 - a] + 1;
      if (cand < best)
        best = cand;
    }
    if (i >= b + 1) {
      int cand = dp[i - 1 - b] + 1;
      if (cand < best)
        best = cand;
    }
    dp[i] = best;
  }

  printf("%d\n", dp[N]);
  free(dp);
  return 0;
}