//=====================================================================
//   23595번:    Quadratic equation                   
//   @date:   2024-10-19              
//   @link:   https://www.acmicpc.net/problem/23595  
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

	while (T--) {
		long long Y;
		cin >> Y;
		
		long long Z;

		if (Y == 1) {
			Z = 2;
		} else if (Y == -1) {
			Z = -2;
		} else {
			if (Y > 0) {
				Z = -1;
			} else {
				Z = 1;
			}
		}

		long long A = 1;
		long long B = -(Y + Z);
		long long C = Y * Z;

		cout << A << " " << B << " " << C << "\n";
	}

	return 0;
}
