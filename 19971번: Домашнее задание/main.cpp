//=====================================================================
//   19971번:    Домашнее задание                   
//   @date:   2024-10-15              
//   @link:   https://www.acmicpc.net/problem/19971  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m;
	cin >> n >> m;

	vector<ll> t(n+1, 0);

	for (int i = 1; i <= n; i++) cin >> t[i];
	vector<int> out_degree(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		out_degree[a]++;
	}

	ll total = 0;
	for (int i = 1; i <= n; i++) total += t[i];
	ll min_sum = LLONG_MAX;

	for (int i = 1; i <= n; i++) {
		if (out_degree[i] == 0) {
			min_sum = min(min_sum, total - t[i]);
		}
	}

	cout << min_sum << "\n";

	return 0;
}