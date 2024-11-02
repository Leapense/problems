//=====================================================================
//   21508번:    Список школ                   
//   @date:   2024-10-18              
//   @link:   https://www.acmicpc.net/problem/21508  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	map<string, int> cnt;
	regex re("([1-9][0-9]*)");

	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		smatch match;
		if (regex_search(s, match, re)) {
			string num = match.str(1);
			cnt[num]++;
		}
	}
	vector<string> result;

	for(auto &[num, c] : cnt) {
		if (c >= 1 && c <= 5) {
			result.push_back(num);
		}
	}

	cout << result.size() << "\n";
	for (auto num : result) {
		cout << num << '\n';
	}

	return 0;
}
