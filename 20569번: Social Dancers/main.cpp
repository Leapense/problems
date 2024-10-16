//=====================================================================
//   20569번:    Social Dancers                   
//   @date:   2024-10-16              
//   @link:   https://www.acmicpc.net/problem/20569  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long L, F, M;
	cin >> L >> F >> M;

	vector<long long> leads(8, 0);
	vector<long long> follows(8, 0);

	auto get_bitmask = [&](int k) -> int {
		int mask = 0;
		for (int i = 0; i < k; i++) {
			string dance;
			cin >> dance;
			if (dance == "swing") mask |= (1 << 0);
			else if (dance == "country") mask |= (1 << 1);
			else if (dance == "bachata") mask |= (1 << 2);
		}
		return mask;
	};

	for (long long i = 0; i < L; i++) {
		int k;
		cin >> k;

		int mask = get_bitmask(k);
		leads[mask]++;
	}

	for (long long i = 0; i < F; i++) {
		int k;
		cin >> k;

		int mask = get_bitmask(k);
		follows[mask]++;
	}

	long long sum_sum = 0;

	for (int s = 0; s < 8; s++) {
		long long pairs = min(leads[s], follows[s]);

		if (pairs > 0) {
			int pop = __builtin_popcount(s);
			sum_sum += pairs * (long long)pop;
		}
	}

	double expected = ((double)sum_sum * (double)M) / 3.0;

	cout << fixed << setprecision(15) << expected;

	return 0;
}
