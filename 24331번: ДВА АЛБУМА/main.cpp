//=====================================================================
//   24331번:    ДВА АЛБУМА                   
//   @date:   2024-10-20              
//   @link:   https://www.acmicpc.net/problem/24331  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);

	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> res;
	int i = 0, j = 0;

	while (i < n && j < m) {
		if (a[i] == b[j]) {
			res.push_back(a[i]);
			i++;
			j++;
		}
		else if (a[i] < b[j]) {
			i++;
		}
		else {
			j++;
		}
	}
	cout << res.size() << "\n";

	if (res.size()) {
		for (int i = 0; i < res.size(); i++) cout << res[i] << (i < res.size() - 1 ? " " : "\n");
	}

	return 0;
}