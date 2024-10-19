//=====================================================================
//   22062번:    Цифровые корни                  
//   @date:   2024-10-19              
//   @link:   https://www.acmicpc.net/problem/22062  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <stdio.h>
#include <stdint.h>

int main() {
	int t;
	if (scanf("%d", &t) != 1) {
		return 1;
	}
	while (t--) {
		unsigned long long a, b;
		if (scanf("%llu %llu", &a, &b) != 2) {
			return 1;
		}

		unsigned long long counts[9] = {0};

		for (int d = 0; d < 9; d++) {
			unsigned long long dr;

			if (d == 0) {
				dr = 9;
			} else {
				dr = d;
			}

			unsigned long long r = a % 9;
			unsigned long long first_d;

			if (r > (unsigned long long) d) {
				first_d = a + (9 - r) + d;
			} else {
				first_d = a + (d - r);
			}

			if (first_d < a) {
				first_d += 9;
			}

			if (first_d > b) {
				
			} else {
				unsigned long long diff = b - first_d;
				unsigned long long cnt = diff / 9 + 1;
				counts[dr - 1] += cnt;
			}
		}

		unsigned long long max_count = 0;
		for (int i = 0; i < 9; i++) {
			if (counts[i] > max_count) {
				max_count = counts[i];
			}
		}

		int dr_list[9];
		int n = 0;
		for (int i = 0; i < 9; i++) {
			if (counts[i] == max_count) {
				dr_list[n++] = i + 1;
			}
		}

		printf("%d", n);
		for (int i = 0; i < n; i++) {
			printf(" %d", dr_list[i]);
		}

		printf("\n");
	}

	return 0;
}