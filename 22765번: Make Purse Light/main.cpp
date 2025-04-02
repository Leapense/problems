#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Coins {
    int ten, fifty, hundred, fiveHundred;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int price;
        cin >> price;

        if (price == 0) break;

        Coins wallet;
        cin >> wallet.ten >> wallet.fifty >> wallet.hundred >> wallet.fiveHundred;

        int totalCoins = wallet.ten + wallet.fifty + wallet.hundred + wallet.fiveHundred;
        int bestFinalCoins = numeric_limits<int>::max();
        
        vector<int> bestUsage(4, 0);

        for (int a = 0; a <= wallet.ten; ++a) {
            for (int b = 0; b <= wallet.fifty; ++b) {
                for (int c = 0; c <= wallet.hundred; ++c) {
                    for (int d = 0; d <= wallet.fiveHundred; ++d) {
                        int payment = a * 10 + b * 50 + c * 100 + d * 500;
                        if (payment < price) continue;

                        int changeAmount = payment - price;

                        int change_d = 0, change_c = 0, change_b = 0, change_a = 0;
                        int temp = changeAmount;
                        change_d = temp / 500; temp %= 500;
                        change_c = temp / 100; temp %= 100;
                        change_b = temp / 50; temp %= 50;
                        change_a = temp / 10; temp %= 10;

                        int changeCoins = change_a + change_b + change_c + change_d;

                        bool valid = true;
                        if (a > 0 && change_a > 0) valid = false;
                        if (b > 0 && change_b > 0) valid = false;
                        if (c > 0 && change_c > 0) valid = false;
                        if (d > 0 && change_d > 0) valid = false;
                        if (!valid) continue;

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

        if (bestUsage[0] > 0) cout << "10 " << bestUsage[0] << "\n";
        if (bestUsage[1] > 0) cout << "50 " << bestUsage[1] << "\n";
        if (bestUsage[2] > 0) cout << "100 " << bestUsage[2] << "\n";
        if (bestUsage[3] > 0) cout << "500 " << bestUsage[3] << "\n";
        cout << "\n";
    }

    return 0;
}
