#include <iostream>
#include <vector>
#include <algorithm>
#include "main.h"

using namespace std;

vector<unsigned long long> generateFibonacci(unsigned long long S) {
    vector<unsigned long long> fib;

    fib.push_back(0);
    fib.push_back(1);
    fib.push_back(1);
    while (true) {
        unsigned long long next = fib[fib.size() - 1] + fib[fib.size() - 2];

        if (next > S * 2 || next < fib.back()) break;
        fib.push_back(next);
    }

    return fib;
}

int maxPackableItems(int W, int F, unsigned long long S, const vector<unsigned long long>& items, const vector<unsigned long long>& fib) {
    vector<unsigned long long> costs;

    for (auto item : items) {
        auto it = lower_bound(fib.begin(), fib.end(), item);
        if (it == fib.end()) continue;
        unsigned long long boxSize = *it;
        unsigned long long cost = (boxSize == item) ? 0 : (boxSize - item);
        costs.push_back(cost);
    }

    sort(costs.begin(), costs.end());

    int count = 0;
    unsigned long long totalCost = 0;

    for (auto cost : costs) {
        if (totalCost + cost <= static_cast<unsigned long long>(F)) {
            totalCost += cost;
            count++;
        } else {
            break;
        }
    }

    return count;
}

#ifndef UNIT_TESTS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int W, F;
        unsigned long long S;

        cin >> W >> F >> S;
        if (W == 0 && F == 0 && S == 0) break;

        vector<unsigned long long> items(W);
        for (int i = 0; i < W; i++) {
            cin >> items[i];
        }

        vector<unsigned long long> fib = generateFibonacci(S);
        int result = maxPackableItems(W, F, S, items, fib);
        cout << result << "\n";
    }

    return 0;
}
#endif
