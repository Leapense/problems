#include <iostream>
#include <vector>

using namespace std;

int main() {
  int x;
  if (!(cin >> x))
    return 0;
  int limit = max(x, 2);
  vector<bool> isPrime(limit + 1, true);
  isPrime[0] = false;
  isPrime[1] = false;

  for (int i = 2; (long long)i * i <= limit; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= limit; j += i) {
        isPrime[j] = false;
      }
    }
  }

  int count = 0;
  while (x > 2) {
    int p = 2;
    for (; p <= x; p++) {
      if (isPrime[p] && isPrime[x - p])
        break;
    }
    x = (x - p) - p;
    count++;
  }

  cout << count << "\n";

  return 0;
}