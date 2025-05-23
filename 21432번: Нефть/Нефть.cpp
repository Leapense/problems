#pragma GCC optimize ("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<pair<int, int>> prices(n);
  for (int i = 0; i < n; ++i) {
    cin >> prices[i].first >> prices[i].second;
  }

  double max_oil = 0;
  for (int i = 0; i < n; ++i) {
    max_oil = max(max_oil, (double)a / prices[i].first);
    max_oil = max(max_oil, (double)b / prices[i].second);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      double oil1 = min((double)a / prices[i].first, (double)b / prices[j].second);
      double oil2 = min((double)a / prices[j].first, (double)b / prices[i].second);
      max_oil = max(max_oil, oil1);
      max_oil = max(max_oil, oil2);

      for (int k=0; k<n; ++k){
          if (k==i || k==j) continue;
          double oil3 = min((double)a/prices[i].first, (double)0.0);
          oil3 += min((double)0.0, (double)b/prices[j].second);
          oil3 += min((double)(a - min((double)a, (double)prices[i].first * oil3))/prices[k].first, (double)(b - min((double)b, (double)prices[j].second * oil3))/prices[k].second);

          
          double oil4 = min((double)0.0, (double)a/prices[i].first);
          oil4 += min((double)b/prices[j].second, (double)0.0);
          oil4 += min((double)(a - min((double)a, (double)prices[i].first * oil4))/prices[k].first, (double)(b - min((double)b, (double)prices[j].second * oil4))/prices[k].second);
          max_oil = max(max_oil, oil3);
          max_oil = max(max_oil, oil4);
      }
    }
  }

  cout << fixed << setprecision(2) << max_oil << endl;

  return 0;
}