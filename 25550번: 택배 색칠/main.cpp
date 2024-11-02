//=====================================================================
//   25550번:    택배 색칠                   
//   @date:   2024-10-26              
//   @link:   https://www.acmicpc.net/problem/25550  
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

	int N, M;
	cin >> N >> M;
	vector<vector<ll>> A(N + 2, vector<ll>(M + 2, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}

	ll ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			ll current = A[i][j];
			ll up = A[i - 1][j];
			ll down = A[i + 1][j];
			ll left = A[i][j - 1];
			ll right = A[i][j + 1];

			ll temp = min({current - 1, up, down, left, right});

			if (temp >= 1) {
				ans += temp;
			}
		}
	}

	cout << ans;

	return 0;
}
