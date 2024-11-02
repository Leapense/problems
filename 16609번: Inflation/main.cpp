//=====================================================================
//   16609번:    Inflation                   
//   @date:   2024-10-13              
//   @link:   https://www.acmicpc.net/problem/16609  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
#define REP(start, end, step) for (int i = start; i < end; i += step)

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> c(n);

	for (auto &x : c) cin >> x;
	sort(c.begin(), c.end());

	double min_f = 1.0;
	bool impossible = false;

	REP(1, n + 1, 1)
	{
		int cj = c[i - 1];
		if (cj > i) {
			impossible = true;
			break;
		}

		double fi = (double)cj / i;
		min_f = min(min_f, fi);
	}

	if (impossible) {
		cout << "impossible\n";
	} else {
		cout << fixed << setprecision(10) << min_f << "\n";
	}

	return 0;
}
