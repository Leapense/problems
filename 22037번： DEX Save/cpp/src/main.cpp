#include "main.h"
#include <algorithm>
#include <iomanip>

std::vector<double> compute_d20_distribution(const std::string& mode) {
    std::vector<double> dist(21, 0.0);
    if (mode == "straight") {
        for (int i = 1; i <= 20; i++) {
            dist[i] = 1.0 / 20.0;
        }
    } else if (mode == "advantage") {
        vector<int> freq(21, 0);
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
                int result = std::max(i, j);
                freq[result]++;
            }
        }

        for (int r = 1; r <= 20; r++) {
            dist[r] = freq[r] / 400.0;
        }
    } else if (mode == "disadvantage") {
        std::vector<int> freq(21, 0);
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
                int result = std::min(i, j);
                freq[result]++;
            }
        }
        for (int r = 1; r <= 20; r++) {
            dist[r] = freq[r] / 400.0;
        }
    }

    return dist;
}

std::map<int, double> compute_bonus_distribution(int k, const std::vector<std::string>& dice) {
    std::map<int, double> dp;
    dp[0] = 1.0;

    for (int i = 0; i < k; i++) {
        std::map<int, double> next_dp;
        char sign = dice[i][0];
        int d = std::stoi(dice[i].substr(2));
        for (auto& [curr, prob] : dp) {
            for (int face = 1; face <= d; face++) {
                int add = (sign == '+' ? face : -face);
                next_dp[curr + add] += prob * (1.0 / d);
            }
        }

        dp = next_dp;
    }


    return dp;
}

void solve(std::istream& in, std::ostream& out) {
    int d, m;
    in >> d >> m;
    std::string mode;
    in >> mode;

    int k;
    in >> k;

    std::vector<std::string> bonusDice(k);
    for (int i = 0; i < k; i++) {
        in >> bonusDice[i];
    }

    std::vector<double> d20 = compute_d20_distribution(mode);

    std::map<int, double> bonusDist = compute_bonus_distribution(k, bonusDice);

    double successProb = 0.0;

    for (int r = 1; r <= 20; r++) {
        double pr = d20[r];

        if (r == 20) {
            successProb += pr;
            continue;
        }

        if (r == 1) {
            continue;
        }

        for (auto &[bonus, bonusProb] : bonusDist) {
            int total = r + m + bonus;
            if (total >= d) {
                successProb += pr * bonusProb;
            }
        }
    }

    out << std::fixed << std::setprecision(9) << successProb << "\n";
}

#ifndef UNIT_TESTS
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
    return 0;
}
#endif
