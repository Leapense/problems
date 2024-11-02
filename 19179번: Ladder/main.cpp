//=====================================================================
//   19179번:    Ladder                   
//   @date:   2024-10-13              
//   @link:   https://www.acmicpc.net/problem/19179  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int z;
	cin >> z;

	while (z--) {
		long long n, k, x, y;
		cin >> n >> k >> x >> y;

		long long count_x = 0, count_y = 0;

		for (long long i = 0; i < n; i++) {
			long long d;
			cin >> d;

			if (d >= x) count_x++;
			if (d >= y) count_y++;
		}

		if (x == y) {
			if (count_x >= k + 2) cout << "YES\n";
			else cout << "NO\n";
		}
		else if (x > y) {
			if (count_x >= 2 && count_y >= k + 2) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			if (count_y >= k && count_x >= k + 2) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}
