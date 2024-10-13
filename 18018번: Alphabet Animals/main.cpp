//=====================================================================
//   18018번:    Alphabet Animals                   
//   @date:   2024-10-13              
//   @link:   https://www.acmicpc.net/problem/18018  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string last_animal;
	cin >> last_animal;

	char last_char = last_animal.back();
	int n;

	cin >> n;

	vector<string> animals(n);
	vector<int> count(26, 0);

	for (auto &s : animals) {
		cin >> s;
		count[s[0] - 'a']++;
	}

	for (int i = 0; i < n; i++) {
		if (animals[i][0] == last_char) {
			char end_char = animals[i].back();
			int cnt = count[end_char - 'a'];
			if (animals[i][0] == end_char) {
				cnt--;
			}
			if (cnt == 0) {
				cout << animals[i] << "!\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (animals[i][0] == last_char) {
			cout << animals[i] << "\n";
			return 0;
		}
	}

	cout << "?\n";

	return 0;
}
