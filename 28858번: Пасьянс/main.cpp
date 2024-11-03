//=====================================================================
//   28858번:    Пасьянс                   
//   @date:   2024-11-03              
//   @link:   https://www.acmicpc.net/problem/28858  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int getParity(long long num) {
	return num % 2;
}

int longestAlternatingSubsequence(int n, vector<long long> cards) {

	sort(cards.begin(), cards.end());
	cards.erase(unique(cards.begin(), cards.end()), cards.end());
    n = cards.size();
	
	vector<vector<int>> dp(n, vector<int>(2, 1));

	for (int i = 0; i < n; ++i) {
		int currentParity = getParity(cards[i]);

		for (int j = 0; j < i; ++j) {
			if (cards[j] < cards[i] && getParity(cards[j]) != currentParity) {
				dp[i][currentParity] = max(dp[i][currentParity], dp[j][1 - currentParity] + 1);
			}
		}
	}

	int maxLength = 1;
	for (int i = 0; i < n; ++i) {
		maxLength = max({maxLength, dp[i][0], dp[i][1]});
	}

	return maxLength;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<long long> cards(n);
	for (auto &x : cards) cin >> x;

	int result = longestAlternatingSubsequence(n, cards);
	cout << result << "\n";

	return 0;
}
