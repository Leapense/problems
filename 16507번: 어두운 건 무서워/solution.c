#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int R, C, Q;
  if (scanf("%d %d %d", &R, &C, &Q) != 3) {
    return 0;
  }

  static long long P[1001][1001];
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      int v;
      scanf("%d", &v);
      P[i][j] = v + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
    }
  }

  while (Q--) {
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    long long s = P[r2][c2] - P[r1 - 1][c2] - P[r2][c1 - 1] + P[r1 - 1][c1 - 1];
    int area = (r2 - r1 + 1) * (c2 - c1 + 1);
    printf("%lld\n", s / area);
  }

  return 0;
}