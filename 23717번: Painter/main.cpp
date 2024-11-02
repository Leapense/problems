//=====================================================================
//   23717번:    Painter                   
//   @date:   2024-10-19              
//   @link:   https://www.acmicpc.net/problem/23717  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	unordered_map<char, int> color_map = {
		{'U', 0}, {'R', 1}, {'Y', 2}, {'B', 4}, {'O', 1 | 2}, {'P', 1 | 4}, {'G', 2 | 4}, {'A', 1 | 2 | 4}
	};

	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		string P;
		cin >> P;

		vector<int> required_mask(N, 0);
		for (int i = 0; i < N; i++) {
			if (color_map.find(P[i]) != color_map.end()) {
				required_mask[i] = color_map[P[i]];
			} else {
				required_mask[i] = 0;
			}
		}

		int primary_colors[3] = {1, 2, 4};
		int total_strokes = 0;

		for (int c = 0; c < 3; c++) {
			int color = primary_colors[c];
			bool prev = false;

			int count = 0;

			for (int i = 0; i < N; i++) {
				if((required_mask[i] & color)) {
					if (!prev) {
						count++;
						prev = true;
					}
				} else {
					prev = false;
				}
			}
			total_strokes += count;
		}
		cout << "Case #" << tc << ": " << total_strokes << "\n";
	}
}
