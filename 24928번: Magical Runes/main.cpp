//=====================================================================
//   24928번:    Magical Runes                   
//   @date:   2024-10-24              
//   @link:   https://www.acmicpc.net/problem/24928  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main()
{
	string S;
	ull D;
	cin >> S >> D;

	int N = S.length();

	ull num = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'B') {
			num |= (1ULL << i);
		}
	}
	num += D;
	ull mask = (N == 64) ? ~0ULL : ((1ULL << N) - 1);
	num &= mask;
	string res = "";

	for (int i = 0; i < N; i++) {
		if (num & (1ULL << i)) res += 'B';
		else res += 'A';
	}

	cout << res << "\n";

	return 0;
}
