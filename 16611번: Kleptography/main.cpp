//=====================================================================
//   16611번:    Kleptography                   
//   @date:   2024-10-13              
//   @link:   https://www.acmicpc.net/problem/16611  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	string last_n, ciphertext;
	cin >> last_n >> ciphertext;

	vector<int> a(m, -1);

	for (int i = 0; i < n; i++) {
		a[m - n + i] = last_n[i] - 'a';
	}

	vector<int> b(m, 0);
	for (int i = 0; i < m; i++) {
		b[i] = ciphertext[i] - 'a';
	}

	for (int i = m - 1; i >= n; i--) {
		a[i - n] = (b[i] - a[i] + 26) % 26;
	}

	string plaintext = "";
	for (int i = 0; i < m; i++) {
		plaintext += char(a[i] + 'a');
	}

	cout << plaintext;
	return 0;
}