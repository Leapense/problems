//=====================================================================
//   20868번:    Fluortanten                   
//   @date:   2024-10-17              
//   @link:   https://www.acmicpc.net/problem/20868  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.exceptions(ios_base::failbit);

	int n;
	cin >> n;

	vector<int> a(n);

	int k = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			k = i;
		}
	}

	vector<int> b;
	b.reserve(n - 1);

	for (int i = 0; i < n; i++) {
		if (i != k) {
			b.push_back(a[i]);
		}
	}

	long long S = 0;

	for (int i = 0; i < b.size(); i++) {
		S += (long long)(i + 1) * b[i];
	}

	long long sum = 0;
	long long max_suffix_sum = 0;

	for (int i = b.size() - 1; i >= 0; i--) {
		sum += b[i];
		if (sum > max_suffix_sum) {
			max_suffix_sum = sum;
		}
	}

	cout << (S + max_suffix_sum) << "\n";

	return 0;
}
