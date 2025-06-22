#include <iostream>
#include <iomanip>
#include <vector>

constexpr int MATCH_COUNT = 20;
constexpr int STEP = 50;
constexpr int MAX_DELTA = MATCH_COUNT * STEP;
constexpr int STATE_SIZE = MAX_DELTA * 2 / STEP + 1;
enum Tier { BRONZE, SILVER, GOLD, PLATINUM, DIAMOND, TIER_COUNT };

auto simulate(long double wProb, long double lProb, long double dProb) -> std::vector<long double> {
    std::vector<long double> dp(STATE_SIZE), nextDp(STATE_SIZE);
    dp[STATE_SIZE / 2] = 1.0L;

    for (int i = 0; i < MATCH_COUNT; ++i) {
        std::fill(nextDp.begin(), nextDp.end(), 0.0L);

        for (int j = 0; j < STATE_SIZE; ++j) {
            auto prob = dp[j];
            if (prob == 0.0L) {
                continue;
            }

            nextDp[j + 1] += prob * wProb;
            nextDp[j] += prob * dProb;
            nextDp[j - 1] += prob * lProb;
        }
        dp.swap(nextDp);
    }

    std::vector<long double> tierProb(TIER_COUNT, 0.0L);
    for (int j = 0; j < STATE_SIZE; ++j) {
        auto prob = dp[j];
        if (prob == 0.0L) {
            continue;
        }

        int delta = (j - STATE_SIZE / 2) * STEP;
        int finalScore = 2000 + delta;

        Tier tier = DIAMOND;
        if (finalScore < 1500) {
            tier = BRONZE;
        } else if (finalScore < 2000) {
            tier = SILVER;
        } else if (finalScore < 2500) {
            tier = GOLD;
        } else if (finalScore < 3000) {
            tier = PLATINUM;
        }

        tierProb[tier] += prob;
    }

    return tierProb;
}

int main()
{
    long double w, l, d;
    std::cin >> w >> l >> d;

    auto result = simulate(w, l, d);
    std::cout << std::fixed << std::setprecision(8);
    for (auto p : result) {
        std::cout << p << "\n";
    }

    return 0;
}