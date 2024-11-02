//=====================================================================
//   24300번:    НАЙ-ГОЛЯМ ОСТАТЪК                   
//   @date:   2024-10-20              
//   @link:   https://www.acmicpc.net/problem/24300  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<string> A(N);
	for (auto &s : A) cin >> s;

	sort(A.begin(), A.end(), [&](const string &a, const string &b) -> bool {
		if (a.size() != b.size()) return a.size() > b.size();
		return a > b;
	});

	string max_val = A[0];
	string second_max = "";

	for (int i = 1; i < N; i++) {
		if (A[i] != max_val) {
			second_max = A[i];
			break;
		}
	}

	cout << second_max << "\n";

	return 0;
}