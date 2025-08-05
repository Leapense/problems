#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<long long> sectors(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> sectors[i];
	}

	long long a, b, k;
	std::cin >> a >> b >> k;

	long long max_prize = 0;
	if (a <= k) {
		max_prize = sectors[0];
	}

	long long m_min = 0;
	if (a > k) {
		m_min = (a - 1) / k;
	} else {
		m_min = 1;
	}

	long long m_max = 0;
	if (b > k) {
		m_max = (b - 1) / k;
	}

	if (m_max >= m_min) {
		if (m_max - m_min >= n - 1) {
			for (long long prize : sectors) {
				max_prize = std::max(max_prize, prize);
			}
		} else {
			for (long long m = m_min; m <= m_max; ++m) {
				long long cw_idx = m % n;
				max_prize = std::max(max_prize, sectors[cw_idx]);

				long long ccw_idx = (n - (m % n)) % n;
				max_prize = std::max(max_prize, sectors[ccw_idx]);
			}
		}
	}

	if (max_prize == 0) {
		max_prize = sectors[0];
	}

	std::cout << max_prize << std::endl;

	return 0;
}
