//=====================================================================
//   28732번:    Вырваться из окружения                   
//   @date:   2024-11-02              
//   @link:   https://www.acmicpc.net/problem/28732  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, a, b, d;
  cin >> n >> a >> b >> d;

  ll count = 0;
  if (d == 0) {
    if (a >= 1 && a <= n && b >= 1 && b <= n) {
      count = 1;
    }
  } else {
    auto compute = [&](ll d, ll min_val, ll max_val) -> ll {
      min_val = max(min_val, 0LL);
      max_val = min(max_val, d);
      if (min_val > max_val) {
        return 0;
      }
      return max_val - min_val + 1;
    };

    ll right_up_min = d - (n - b);
    ll right_up_max = d <= (n - a) ? d : (n - a);
    ll count_right_up = compute(d, right_up_min, right_up_max);

    ll left_up_min = d - (n - b);
    ll left_up_max = d <= (a - 1) ? d : (a - 1);
    ll count_left_up = compute(d, left_up_min, left_up_max);

    ll right_down_min = d - (b - 1);
    ll right_down_max = d <= (n - a) ? d : (n - a);
    ll count_right_down = compute(d, right_down_min, right_down_max);

    ll left_down_min = d - (b - 1);
    ll left_down_max = d <= (a - 1) ? d : (a - 1);
    ll count_left_down = compute(d, left_down_min, left_down_max);

    ll total = count_right_up + count_left_up + count_right_down + count_left_down;
    ll overlap = ((a + d <= n) ? 1 : 0) + ((a - d >= 1) ? 1 : 0) + ((b + d <= n) ? 1 : 0) + ((b - d >= 1) ? 1 : 0);

    count = total - overlap;
  }

  cout << count << endl;

  return 0;
}