//=====================================================================
//   24362번:    МАГАЗИН                   
//   @date:   2024-10-21              
//   @link:   https://www.acmicpc.net/problem/24362  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, k;
	cin >> n >> k;

	vector<long long> a(n);
	for(auto &x : a) cin >> x;

	sort(a.begin(), a.end(), greater<long long>());
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if((i + 1) % k != 0) {
			sum += a[i];
		}
	}

	cout << sum;

	return 0;
}
