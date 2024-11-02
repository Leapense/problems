//=====================================================================
//   16955번:    오목, 이길 수 있을까?                   
//   @date:   2024-10-13              
//   @link:   https://www.acmicpc.net/problem/16955  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<string> board(10);

	for(auto &s : board) cin >> s;
	auto check = [&](const vector<string> &b) -> bool {
		int dirs[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (b[i][j] != 'X') continue;
				for (auto &d : dirs) {
					int cnt = 1, ni = i + d[0], nj = j + d[1];

					while(ni >= 0 && ni < 10 && nj >= 0 && nj < 10 && b[ni][nj] == 'X') {
						cnt++;
						ni += d[0];
						nj += d[1];
					}
					if (cnt >= 5) return true;
				}
			}
		}

		return false;
	};

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == '.') {
				board[i][j] = 'X';
				if (check(board)) {
					cout << 1;
					return 0;
				}
				board[i][j] = '.';
			}
		}
	}

	cout << "0\n";

	return 0;
}