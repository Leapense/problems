//=====================================================================
//   21650번:    Чемпионат по стрельбе                   
//   @date:   2024-10-19              
//   @link:   https://www.acmicpc.net/problem/21650  
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

	vector<int> A(n);

	for (auto &x : A) cin >> x;
	int max_score = *max_element(A.begin(), A.end());

	vector<int> freq(1001, 0);

	for (auto x : A) freq[x]++;

	vector<int> count_freq(1001, 0);
	int cumulative = 0;

	for (int x = 1000; x >= 0; x--) {
		count_freq[x] = cumulative;
		cumulative += freq[x];
	}

	vector<bool> has_max_before(n + 1, false);
	for (int i = 1; i <= n; i++) {
		has_max_before[i] = has_max_before[i - 1] || (A[i - 1] == max_score);
	}

	vector<int> candidates;
	for (int i = 0; i < n - 1; i++) {
		if (A[i] % 10 == 5 && A[i + 1] < A[i] && has_max_before[i]) {
			candidates.push_back(A[i]);
		}
	}
	if (candidates.empty()) {
		cout << "0";
		return 0;
	}

	int min_rank = INT32_MAX;
	for (auto x : candidates) {
		int rank = count_freq[x] + 1;
		if (rank < min_rank) {
			min_rank = rank;
		}
	}
	cout << min_rank;

	return 0;
}
