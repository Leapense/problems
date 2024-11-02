//=====================================================================
//   28768번:    Выживание и шоколад                   
//   @date:   2024-11-02              
//   @link:   https://www.acmicpc.net/problem/28768  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int count_div2(ll x) {
	int cnt = 0;
	while (x % 2 == 0) {
		cnt++;
		x /= 2;
	}

	return cnt;
}

int main() {
	ll n, m;
	cin >> n >> m;

	int k1 = count_div2(m);
	ll a1 = n;
	ll factor = 1;

	for (int i = 0; i < k1; i++) factor *= 2;
	a1 *= factor;
	ll b1 = m / factor;
	ll sum1 = a1 + b1;

	int k2 = count_div2(n);
	ll a2 = n;
	factor = 1;

	for (int i = 0; i < k2; i++) factor *= 2;
	a2 /= factor;
	ll b2 = m * factor;
	ll sum2 = a2 + b2;

	ll max_sum = max(sum1, sum2);

	cout << 2 * max_sum;

	return 0;
}