//=====================================================================
//   23785번:    Organ-free Man                   
//   @date:   2024-10-20              
//   @link:   https://www.acmicpc.net/problem/23785  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<long long> fac = {1, 1};
	for (long long i = 2; i < 10; ++i) {
		fac.push_back(fac.back() * i);
	}

	long long N;
	cin >> N;

	if (N == 1) {
		cout << "0" << endl;

		return 0;
	}

	string res;
	for (long long i = fac.size()-1; i >= 1; --i) {
		long long f = fac[i];
		while (N >= f) {
			N -= f;
			res += to_string(i);
		}
	}

	reverse(res.begin(), res.end());

	cout << res << "\n";

	return 0;
}