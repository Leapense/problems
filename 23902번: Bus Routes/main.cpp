//=====================================================================
//   23902번:    Bus Routes                   
//   @date:   2024-10-20              
//   @link:   https://www.acmicpc.net/problem/23902  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		long long N, D;
		cin >> N >> D;
		vector<long long> X(N);
		for (auto &x : X) cin >> x;
		long long current_day = D;

		for (int i = N - 1; i >= 0; i--) {
			current_day = (current_day / X[i]) * X[i];
		}
		cout << "Case #" << tc << ": " << current_day << "\n";
	}

	return 0;
}