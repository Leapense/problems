#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, a, b;
  if (!(std::cin >> N >> a >> b))
    return 0;
  std::vector<int> dp(N + 1);
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

  std::cout << dp[N] << "\n";
  return 0;
}