#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
  int64_t m;
  if (scanf("%" SCNd64, &m) != 1)
    return 0;
  int64_t a = (m - 1) * m / 2;
  for (int64_t x = m + 1;; ++x) {
    int64_t rhs = x * x - a;
    if (rhs <= 0)
      continue;
    long double root = sqrtl((long double)8 * rhs + 1);
    int64_t n = (int64_t)((root - 1) / 2);
    if (n >= x + 1 && n * (n + 1) / 2 == rhs) {
      printf("%" PRId64 " %" PRId64 " %" PRId64 "\n", m, x, n);
      break;
    }
  }

  return 0;
}