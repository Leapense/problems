//=====================================================================
//   17661번:    Mangling Names                   
//   @date:   2024-10-13              
//   @link:   https://www.acmicpc.net/problem/17661  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		cout << "Data Set " << i + 1 << ":" << "\n";
		unsigned long long l, n;

		cin >> l >> n;

		vector<vector<int>> tt(l + 1, vector<int>(l + 1));

		for (int a = 0; a < l + 1; a++) {
			for (int b = 0; b < l + 1; b++) {
				cin >> tt[a][b];
			}
		}

		cin.ignore();

		unsigned long long total = 0;

		for (int j = 0; j < n; j++) {
			string temp;
			getline(cin, temp);

			unsigned long long con = 0, vow = 0;

			for (int p = 0; p < temp.size(); p++) {
				if (temp[p] == 'a' or temp[p] == 'e' or temp[p] == 'i' or temp[p] == 'o' or temp[p] == 'u' or temp[p] == 'y') {
					vow++;
				} else {
					con++;
				}
			}

			total += tt[vow][con];
		}

		cout << total << "\n\n";
	}

	return 0;
}