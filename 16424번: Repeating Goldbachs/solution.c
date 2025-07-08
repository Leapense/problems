#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int x;
  if (scanf("%d", &x) != 1)
    return 0;
  int limit = x > 2 ? x : 2;
  bool *is_prime = malloc((limit + 1) * sizeof(bool));
  for (int i = 0; i <= limit; i++)
    is_prime[i] = true;
  is_prime[0] = false;
  is_prime[1] = false;

  for (int i = 2; (long long)i * i <= limit; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= limit; j += i) {
        is_prime[j] = false;
      }
    }
  }

  int count = 0;
  while (x > 2) {
    int p;
    for (p = 2; p <= x; p++) {
      if (is_prime[p] && is_prime[x - p])
        break;
    }
    x = (x - p) - p;
    count++;
  }

  printf("%d\n", count);
  free(is_prime);
  return 0;
}