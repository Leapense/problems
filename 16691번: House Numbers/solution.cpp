#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long m;
  if (!(cin >> m))
    return 0;

  long long a = (m - 1) * m / 2;
  for (long long x = m + 1;; ++x) {
    long long rhs = x * x - a;
    if (rhs <= 0)
      continue;
    long double root = sqrt(static_cast<long double>(8) * rhs + 1);
    long long n = static_cast<long long>((root - 1) / 2);
    if (n >= x + 1 && n * (n + 1) / 2 == rhs) {
      cout << m << ' ' << x << ' ' << n << '\n';
      break;
    }
  }

  return 0;
}