//=====================================================================
//   17847번:    Diamonds Are for Evers                   
//   @date:   2024-10-13              
//   @link:   https://www.acmicpc.net/problem/17847  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	char grid[31][31];
	int icase = 0;
	string s;

	cin >> s;
	int n = (int)sqrt(s.length());
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			grid[i][j] = s[k++];
		}
	}

	int r = n / 2;
	int c = 0;
	int len = n / 2;

	string decoded = "";

	while (len != 0) {
		for (int i = 0; i < len; i++) {
			decoded += grid[r][c];
			r--;
			c++;
		}
		for (int i = 0; i < len; i++) {
			decoded += grid[r][c];
			r++;
			c++;
		}
		for (int i = 0; i < len; i++) {
			decoded += grid[r][c];
			r++;
			c--;
		}
		for (int i = 0; i < len; i++) {
			decoded += grid[r][c];
			r--;
			c--;
		}
		c++;
		len--;
	}

	decoded += grid[r][c];

	cout << decoded << "\n";

	return 0;
}