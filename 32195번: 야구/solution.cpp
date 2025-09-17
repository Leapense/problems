#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	if (!(cin >> N)) return 0;

	vector<unsigned long long> A;
	A.reserve(N);

	long long x, y;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		if (y >= llabs(x)) {
			unsigned long long s = (unsigned long long)(x * x) + (unsigned long long)(y * y);
			A.push_back(s);
		}
	}

	sort(A.begin(), A.end());
	const int K = (int)A.size();
	const int foul = N - K;

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		long long R;
		cin >> R;
		unsigned long long t = (unsigned long long)(R) * (unsigned long long)(R);
		
		int infield = upper_bound(A.begin(), A.end(), t) - A.begin();
		int homerun = K - infield;
		cout << foul << ' ' << infield << ' ' << homerun << '\n';
	}
	return 0;
}
