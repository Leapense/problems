//=====================================================================
//   27376번:    참살이길                   
//   @date:   2024-10-30              
//   @link:   https://www.acmicpc.net/problem/27376  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

struct TrafficLight {
	long long x;
	long long t;
	long long s;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, k;
	cin >> n >> k;
	
	vector<TrafficLight> lights(k);

	for (int i = 0; i < k; i++) cin >> lights[i].x >> lights[i].t >> lights[i].s;

	sort(lights.begin(), lights.end(), [&](const TrafficLight &a, const TrafficLight &b) -> bool {
		return a.x < b.x;
	});

	long long current_time = 0;
	long long prev_x = 0;

	for (auto &light: lights) {
		long long travel = light.x - prev_x;
		current_time += travel;
		long long arrival_time = current_time;

		if (arrival_time < light.s) {
			current_time = light.s;
		} else {
			long long t_prime = arrival_time - light.s;
			long long cycle = 2 * light.t;
			long long t_double_prime = t_prime % cycle;

			if (t_double_prime < light.t) {

			} else {
				long long wait = cycle - t_double_prime;
				current_time += wait;
			}
		}

		prev_x = light.x;
	}

	current_time += (n - prev_x);
	cout << current_time << "\n";

	return 0;
}