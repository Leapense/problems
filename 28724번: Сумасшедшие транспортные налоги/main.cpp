//=====================================================================
//   28724번:    Сумасшедшие транспортные налоги                   
//   @date:   2024-11-02              
//   @link:   https://www.acmicpc.net/problem/28724  
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

	int n;
	cin >> n;

	vector<pair<ll, ll>> table(n);

	for (int i = 0; i < n; i++) cin >> table[i].first >> table[i].second;

	int m;
	cin >> m;

	vector<ll> queries(m);

	for (auto &x: queries) cin >> x;

	vector<ll> b(n);
	vector<ll> t(n);

	for (int i = 0; i < n; i++) {
		b[i] = table[i].first;
		t[i] = table[i].second;
	}

	for (auto q : queries) {
		int pos = lower_bound(b.begin(), b.end(), q) - b.begin();

		if (pos == 0) {
			cout << t[0] * q << "\n";
		} else {
			ll rate = t[pos - 1];
			cout << rate * q << "\n";
		}
	}
}
