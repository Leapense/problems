#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int R, C, Q;
  std::cin >> R >> C >> Q;
  std::vector<std::vector<long long>> P(R + 1,
                                        std::vector<long long>(C + 1, 0));
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      int v;
      std::cin >> v;
      P[i][j] = v + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
    }
  }
  while (Q--) {
    int r1, c1, r2, c2;
    std::cin >> r1 >> c1 >> r2 >> c2;
    long long sum =
        P[r2][c2] - P[r1 - 1][c2] - P[r2][c1 - 1] + P[r1 - 1][c1 - 1];
    int area = (r2 - r1 + 1) * (c2 - c1 + 1);
    std::cout << (sum / area) << "\n";
  }

  return 0;
}