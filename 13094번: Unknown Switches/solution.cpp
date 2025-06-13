#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>

char to_base36(int n) {
    if (n < 10) return static_cast<char>('0' + n);
    return static_cast<char>('A' + (n - 10));
}

void solve() {
    int n, m, q;
    while (std::cin >> n >> m >> q && (n != 0 || m != 0 || q != 0)) {
        std::vector<std::string> s(q), b(q);
        for (int i = 0; i < q; ++i) {
            std::cin >> s[i] >> b[i];
        }

        std::vector<std::pair<std::string, int>> switch_info(n);
        for (int k = 0; k < n; ++k) {
            switch_info[k].second = k;
            if (q > 0) switch_info[k].first.reserve(q);
        }

        std::vector<int> cumul_s(n, 0);
        for (int i = 0; i < q; ++i) {
            for (int k = 0; k < n; ++k) {
                cumul_s[k] ^= (s[i][k] - '0');
                switch_info[k].first += static_cast<char>('0' + cumul_s[k]);
            }
        }

        std::vector<std::pair<std::string, int>> bulb_info(m);
        for (int j = 0; j < m; ++j) {
            bulb_info[j].second = j;
            if (q > 0) {
                bulb_info[j].first.reserve(q);
                for (int i = 0; i < q; ++i) {
                    bulb_info[j].first += b[i][j];
                }
            }
        }

        std::sort(switch_info.begin(), switch_info.end());
        std::sort(bulb_info.begin(), bulb_info.end());

        std::string result(m, ' ');
        if (m == 0) {
            std::cout << "\n";
            continue;
        }

        int i = 0;
        int j = 0;
        while (j < m) {
            int j_end = j;
            while (j_end < m && bulb_info[j_end].first == bulb_info[j].first) {
                j_end++;
            }
            const std::string& current_bulb_pattern = bulb_info[j].first;

            while (i < n && switch_info[i].first < current_bulb_pattern) {
                i++;
            }

            int i_start = i;
            while (i < n && switch_info[i].first == current_bulb_pattern) {
                i++;
            }

            int num_matches = i - i_start;
            char res_char;
            if (num_matches == 1) {
                res_char = to_base36(switch_info[i_start].second);
            } else {
                res_char = '?';
            }

            for (int k = j; k < j_end; ++k) {
                result[bulb_info[k].second] = res_char;
            }

            j = j_end;
        }

        std::cout << result << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}