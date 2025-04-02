#include <iostream>
#include <vector>
#include "main.h"

using namespace std;

std::vector<std::pair<int, int>> solveCase(int price, const std::vector<int>& coins) {
    // coins[0]:10원, coins[1]:50원, coins[2]:100원, coins[3]:500원
    int totalCoins = coins[0] + coins[1] + coins[2] + coins[3];
    int bestFinalCoins = 1e9;
    std::vector<int> bestUsage(4, 0);

    // 모든 조합을 브루트포스로 탐색 (각 동전은 0개부터 coins[i]개까지 사용)
    for (int a = 0; a <= coins[0]; ++a) {
        for (int b = 0; b <= coins[1]; ++b) {
            for (int c = 0; c <= coins[2]; ++c) {
                for (int d = 0; d <= coins[3]; ++d) {
                    int payment = a * 10 + b * 50 + c * 100 + d * 500;
                    if (payment < price) continue; // 지불 금액이 부족하면 패스

                    int changeAmount = payment - price;
                    int temp = changeAmount;
                    // 거스름돈을 그리디 방식으로 계산: 500, 100, 50, 10원 순
                    int change_d = temp / 500; temp %= 500;
                    int change_c = temp / 100; temp %= 100;
                    int change_b = temp / 50;  temp %= 50;
                    int change_a = temp / 10;  temp %= 10;
                    int changeCoins = change_a + change_b + change_c + change_d;
                    
                    // 사용한 동전과 거스름돈 동전이 겹치면 안 됨.
                    if ((a > 0 && change_a > 0) ||
                        (b > 0 && change_b > 0) ||
                        (c > 0 && change_c > 0) ||
                        (d > 0 && change_d > 0)) {
                        continue;
                    }
                    
                    int usedCoins = a + b + c + d;
                    int finalCoins = totalCoins - usedCoins + changeCoins;
                    if (finalCoins < bestFinalCoins) {
                        bestFinalCoins = finalCoins;
                        bestUsage = {a, b, c, d};
                    }
                }
            }
        }
    }
    
    std::vector<std::pair<int, int>> result;
    int coinValues[4] = {10, 50, 100, 500};
    for (int i = 0; i < 4; i++) {
        if (bestUsage[i] > 0)
            result.push_back({coinValues[i], bestUsage[i]});
    }
    return result;
}

#ifndef UNIT_TESTS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (true) {
        int price;
        cin >> price;
        if (price == 0) break;
        std::vector<int> coins(4);
        // coins: 10원, 50원, 100원, 500원 순서.
        cin >> coins[0] >> coins[1] >> coins[2] >> coins[3];
        
        auto res = solveCase(price, coins);
        for (const auto &p : res) {
            cout << p.first << " " << p.second << "\n";
        }
        cout << "\n";
    }
    return 0;
}
#endif
