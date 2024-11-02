//=====================================================================
//   21680번:    Неправильное сложение                   
//   @date:   2024-10-19              
//   @link:   https://www.acmicpc.net/problem/21680  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll volodya_add(ll a, ll b) {
	string sa = to_string(a);
	string sb = to_string(b);
	reverse(sa.begin(), sa.end());
	reverse(sb.begin(), sb.end());
	int n = max(sa.size(), sb.size());

	string sum_str = "";

	for (int i = 0; i < n; ++i) {
		int digit_a = (i < sa.size()) ? (sa[i] - '0') : 0;
		int digit_b = (i < sb.size()) ? (sb[i] - '0') : 0;
		int digit_sum = digit_a + digit_b;
		sum_str = to_string(digit_sum) + sum_str;
	}

	return stoll(sum_str);
}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	
	vector<ll> sums;

	sums.push_back(volodya_add(volodya_add(a, b), c));
	sums.push_back(volodya_add(volodya_add(a, c), b));
	sums.push_back(volodya_add(volodya_add(b, a), c));
	sums.push_back(volodya_add(volodya_add(b, c), a));
	sums.push_back(volodya_add(volodya_add(c, a), b));
	sums.push_back(volodya_add(volodya_add(c, b), a));

	set<ll> distinct_sums(sums.begin(), sums.end());

	if (distinct_sums.size() > 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	for (auto sum : distinct_sums) {
		cout << sum << "\n";
	}

	return 0;
}