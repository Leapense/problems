//=====================================================================
//   22749번:    First Experience                   
//   @date:   2024-10-19              
//   @link:   https://www.acmicpc.net/problem/22749  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string inputLine;

	while (getline(cin, inputLine)) {
		long long R1 = 0;
		long long R2 = 0;
		char R3 = '\0';
		bool errorState = false;

		for (char key : inputLine) {
			if (errorState) {
				if (key == '=') {
					cout << "E\n"; // EEEEEEEEEEEEEEEEEE
					R1 = 0; R2 = 0; R3 = '\0';
					errorState = false;
				}

				continue;
			}

			if (isdigit(key)) {
				R2 = R2 * 10 + (key - '0');

				if (R2 >= 10000) errorState = true;
			} else {
				if (R3 != '\0') {
					long long tempResult;

					if (R3 == '+') {
						tempResult = R1 + R2;
					} else if (R3 == '-') {
						tempResult = R1 - R2;
					} else if (R3 == '*') {
						tempResult = R1 * R2;
					}

					if (tempResult < 0 || tempResult > 9999) {
						errorState = true;
					} else {
						R1 = tempResult;
					}
				} else {
					R1 = R2;
				}

				if (key == '=') {
					if (errorState) cout << "E\n";
					else cout << R1 << "\n";
					R1 = 0; R2 = 0; R3 = '\0';
					errorState = false;
				} else {
					R3 = key;
					R2 = 0;
				}
			}
		}
	}

	return 0;
}