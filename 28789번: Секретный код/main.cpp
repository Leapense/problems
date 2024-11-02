//=====================================================================
//   28789번:    Секретный код                   
//   @date:   2024-11-02              
//   @link:   https://www.acmicpc.net/problem/28789  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	ll n = s.size();

	ll freq[26] = {0};
	for (char c : s) {
		freq[c - 'a']++;
	}

	ll total = (n * (n - 1)) / 2;
	ll same_swap = 0;
	for (int i = 0; i < 26; i++) {
		if (freq[i] >= 2) {
			same_swap += (freq[i] * (freq[i] - 1)) / 2;
		}
	}

	ll unique_t;
	if (same_swap > 0) {
		unique_t = total - same_swap + 1;
	} else {
		unique_t = total;
	}

	if (same_swap > 0 && (total - same_swap + 1) <= 0) {
		unique_t = 1;
	}
	if (total == 0 && same_swap == 0) {
		unique_t = 0;
	}

	cout << unique_t << "\n";

	return 0;
}
