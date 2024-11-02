//=====================================================================
//   21437번:    Перевод времени                   
//   @date:   2024-10-18              
//   @link:   https://www.acmicpc.net/problem/21437  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long m;
	cin >> m;
	int d1, d2;
	cin >> d1 >> d2;

	int k;
	cin >> k;

	auto get_day_shift = [&](int day) -> int {
		if (day == 1) return d1;
		if (day == 2) return d2;
		return 0;
	};

	auto get_day_total_minutes = [&](int d) -> int {
		if (d == 1) return 1380;
		if (d == -1) return 1500;
		return 1440;
	};

	auto get_time = [&](int d, int m) -> string {
		int hh, mm;
		if (d == 0) {
			hh = m / 60;
			mm = m % 60;
		} else if (d == 1) {
			if (m < 120) {
				hh = m / 60;
				mm = m % 60;
			} else {
				m += 60;
				hh = m / 60;
				mm = m % 60;
			}
		} else if (d == -1) {
			if (m < 120) {
				hh = m / 60;
				mm = m % 60;
			} else if (m < 180) {
				hh = 2;
				mm = m - 120;
			} else if (m < 240) {
				hh = 2;
				mm = m - 180;
			} else {
				m -= 60;
				hh = m / 60;
				mm = m % 60;
			}
		}

		char buffer[6];
		sprintf(buffer, "%02d:%02d", hh, mm);
		return string(buffer);
	};

	int current_day = 1;
	int current_shift = get_day_shift(current_day);
	int current_day_total_minutes = get_day_total_minutes(current_shift);
	long long current_minute_in_day = m;

	while(current_minute_in_day >= current_day_total_minutes){
        current_minute_in_day -= current_day_total_minutes;
        current_day +=1;
        current_shift = get_day_shift(current_day);
        current_day_total_minutes = get_day_total_minutes(current_shift);
    }
	for (int i = 0; i < k; i++) {
		while (current_minute_in_day >= current_day_total_minutes) {
			current_minute_in_day -= current_day_total_minutes;
			current_day += 1;
			current_shift = get_day_shift(current_day);
			current_day_total_minutes = get_day_total_minutes(current_shift);
		}
		cout << get_time(current_shift, current_minute_in_day) << "\n";
		current_minute_in_day += 1;
	}

	return 0;
}