//=====================================================================
//   20507번:    Knjige                   
//   @date:   2024-10-16              
//   @link:   https://www.acmicpc.net/problem/20507  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int n, p[MAXN];

stack<int> l, d;
vector<tuple<string, char, char>> v;

void push_tuple(string a, char b, char c) {
	v.push_back({a, b, c});
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		l.push(p[i]);
	}

	sort(p, p + n);

	for (int i = 0; i < n; i++) {
		int prebacio = 0;
		while (l.top() != p[i]) {
			push_tuple("UZMI", 'L', 'L');
			push_tuple("STAVI", 'L', 'D');
			d.push(l.top());
			l.pop();
			prebacio++;
		}

		push_tuple("UZMI", 'D', 'L');
		l.pop();

		for (int j = 0; j < prebacio; j++) {
			push_tuple("UZMI", 'L', 'D');
			push_tuple("STAVI", 'L', 'L');
			l.push(d.top());
			d.pop();
		}

		push_tuple("STAVI", 'D', 'D');
		d.push(p[i]);
	}

	while (!d.empty()) {
		push_tuple("UZMI", 'L', 'D');
		push_tuple("STAVI", 'L', 'L');
		l.push(d.top());
		d.pop();
	}

	cout << v.size() << endl;
	for (const auto &p : v) {
		cout << get<0>(p) << ' ' << get<1>(p) << ' ' << get<2>(p) << endl;
	}

	return 0;
}
