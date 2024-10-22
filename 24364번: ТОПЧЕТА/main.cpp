//=====================================================================
//   24364번:    ТОПЧЕТА                   
//   @date:   2024-10-21              
//   @link:   https://www.acmicpc.net/problem/24364  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N, K;
	cin >> N >> K;

	vector<long long> a(N);
	for (auto &x : a) cin >> x;

	while (K--) {
		long long S = 0;
		for (auto x : a) S += x;
		for (auto &x : a) x = S - x;
	}

	long long mn = a[0], mx = a[0];
	for (auto x : a) {
		if (x < mn) mn = x;
		if (x > mx) mx = x;
	}

	cout << mx - mn << "\n";

	return 0;
}
