//=====================================================================
//   25288번:    영어 시험                   
//   @date:   2024-10-25              
//   @link:   https://www.acmicpc.net/problem/25288  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	string S;
	cin >> S;

	sort(S.begin(), S.end());
	long long total_length = (long long)S.size() * N;

	string T;
	T.reserve(total_length);

	for(int i = 0; i < N; i++) {
		T += S;
	}

	cout << T << "\n";

	return 0;
}
