#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> brands(N);

    for (int i = 0; i < N; ++i) {
        cin >> brands[i];
    }

    vector<int> count(51, 0);
    for (int brand : brands) {
        count[brand]++;
    }

    int maxK = *max_element(brands.begin(), brands.end());

    int total = 0;
    for (int K = 1; K <= maxK; ++K) {
        int ways = 1;
        for (int i = 1; i <= K; ++i) {
            if (count[i] == 0) {
                ways = 0;
                break;
            }
            ways *= count[i];
        }
        total += ways;
    }

    cout << total << "\n";

    return 0;
}