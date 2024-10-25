//=====================================================================
//   25044번:    에어컨                   
//   @date:   2024-10-24              
//   @link:   https://www.acmicpc.net/problem/25044  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll N, K;
	cin >> N >> K;

	const int MIN_PER_DAY = 1440;
	vector<int> shutdown_times = {15 * 60, 18 * 60, 21 * 60};

	ll total_delay = 0;
	ll shutdown_count = 0;
	ll internal_day = 0;

	vector<int> result_times;

	while (true) {
		for (auto &shutdown_time : shutdown_times) {
			ll internal_shutdown_time = internal_day * MIN_PER_DAY + shutdown_time;
			ll real_shutdown_time = internal_shutdown_time + total_delay;

			if (real_shutdown_time >= (N + 1) * MIN_PER_DAY) {
				goto END_SIMULATION;
			}

			if (real_shutdown_time >= N * MIN_PER_DAY) {
				int time_in_day = real_shutdown_time % MIN_PER_DAY;
				result_times.push_back(time_in_day);
			}
			shutdown_count++;
			if (shutdown_count % 3 == 0) {
				total_delay += K;
			}
		}

		internal_day++;
	}
	END_SIMULATION:
	sort(result_times.begin(), result_times.end());

	cout << result_times.size() << "\n";

	for (auto &t : result_times) {
		int hh = t / 60;
		int mm = t % 60;

		printf("%02d:%02d\n", hh, mm);
	}

	return 0;
}
