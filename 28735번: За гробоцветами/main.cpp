//=====================================================================
//   28735번:    За гробоцветами                   
//   @date:   2024-11-02              
//   @link:   https://www.acmicpc.net/problem/28735  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<ll, ll>> points(n);

	for (int i = 0; i < n; ++i) {
		cin >> points[i].first >> points[i].second;
	}

	auto p1 = points[0];
	auto p2 = points[1];

	if (n == 3) {
		if ((p2.first - p1.first) * (points[2].second - p1.second) != (p2.second - p1.second) * (points[2].first - p1.first)) {
			cout << "Yes\n1 2 3";
		} else {
			cout << "No\n";
		}

		return 0;
	}

	if ((p2.first - p1.first) * (points[2].second - p1.second) != (p2.second - p1.second) * (points[2].first - p1.first)) {
		cout << "Yes\n1 2 3";
		return 0;
	}

	int idx = -1;
	for (int i = 3; i < n; ++i) {
		if ((p2.first - p1.first) * (points[i].second - p1.second) != (p2.second - p1.second) * (points[i].first - p1.first)) {
			idx = i + 1;
			break;
		}
	}

	if (idx != -1) {
		cout << "Yes\n1 2 " << idx;
	} else {
		cout << "No\n";
	}

	return 0;
}