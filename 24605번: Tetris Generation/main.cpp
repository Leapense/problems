//=====================================================================
//   24605번:    Tetris Generation
//   @date:   2024-10-22
//   @link:   https://www.acmicpc.net/problem/24605
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// Map tetromino characters to bits
	unordered_map<char, int> tetromino_map = {
		{'J', 0},
		{'L', 1},
		{'S', 2},
		{'Z', 3},
		{'I', 4},
		{'O', 5},
		{'T', 6}};

	int t;
	cin >> t;

	while (t--)
	{
		string s;
		cin >> s;
		int m = s.size();
		bool possible = false;

		for (int k = 0; k < 7 && !possible; ++k)
		{
			// Calculate the number of bags needed
			int last_pos = k + m - 1;
			int num_bags = (last_pos / 7) + 1;
			// Initialize bag bitmask
			vector<int> bags(num_bags, 0);
			bool valid = true;
			for (int i = 0; i < m && valid; ++i)
			{
				int bag_rel = (i + k) / 7;
				char c = s[i];
				int bit = tetromino_map[c];
				if (bags[bag_rel] & (1 << bit))
				{
					valid = false;
					break;
				}
				bags[bag_rel] |= (1 << bit);
			}
			if (valid)
			{
				possible = true;
			}
		}
		cout << (possible ? "1" : "0") << "\n";
	}
}
