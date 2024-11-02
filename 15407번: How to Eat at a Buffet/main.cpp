//=====================================================================
//   15407번:    How to Eat at a Buffet                   
//   @date:   2024-10-12              
//   @link:   https://www.acmicpc.net/problem/15407  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  long long a;

  cin >> n >> a;

  vector<pair<int, long long>> items(n);

  for (auto &p : items) cin >> p.first >> p.second;
  sort(items.begin(), items.end(), [&](const pair<int, long long> &x, const pair<int, long long> &y)->bool {
    return x.first > y.first;
  });

  double total = 0.0;
  long long rem = a;

  for (auto &[v, area] : items) {
    if (rem == 0) break;
    long long take = min(area, rem);
    total += (double)v * take;
    rem -= take;
  }

  cout << fixed << setprecision(0) << (long long) total << "\n";

  return 0;
}
