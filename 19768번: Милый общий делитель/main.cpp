//=====================================================================
//   19768번:    Милый общий делитель                   
//   @date:   2024-10-13              
//   @link:   https://www.acmicpc.net/problem/19768  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd_custom(ll a, ll b) {
	while (b) {
		ll temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

ll digit_sum(ll n) {
	ll sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

int main()
{
	ll a, b;
	cin >> a >> b;
	ll g = gcd_custom(a, b);
	vector<ll> divisors;

	for (ll i = 1; i * i <= g; ++i) {
		if (g % i == 0) {
			divisors.push_back(i);
			if (i != g / i) {
				divisors.push_back(g / i);
			}
		}
	}

	ll max_sum = -1;
	ll result = 0;

	for (auto d : divisors) {
		ll s = digit_sum(d);
		if (s > max_sum) {
			max_sum = s;
			result = d;
		}
	}

	cout << result << "\n";

	return 0;
}