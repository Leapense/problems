#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    const int MAX_COORD = 1000000;
    vector<int> ice(MAX_COORD + 1, 0);

    for (int i = 0; i < N; i++) {
        int g, x;
        cin >> g >> x;
        ice[x] += g;
    }

    int window_size = 2 * K + 1;
    long long current_sum = 0;
    long long max_sum = 0;

    for (int i = 0; i <= min(MAX_COORD, window_size - 1); i++) {
        current_sum += ice[i];
    }
    max_sum = current_sum;

    for (int i = 1; i + window_size - 1 <= MAX_COORD; i++) {
        current_sum -= ice[i - 1];
        current_sum += ice[i + window_size - 1];
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";
    return 0;
}