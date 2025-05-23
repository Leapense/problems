#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> candies(N);
    for (int i = 0; i < N; ++i) {
        cin >> candies[i];
    }

    int sum = 0;
    for (int candy : candies) {
        sum += candy;
    }

    vector<bool> possible_sums(sum + 1, false);
    possible_sums[0] = true;

    for (int candy : candies) {
        for (int j = sum; j >= candy; --j) {
            if (possible_sums[j - candy]) {
                possible_sums[j] = true;
            }
        }
    }

    int max_even_sum = 0;
    for (int j = 0; j <= sum; ++j) {
        if (possible_sums[j] && j % 2 == 0) {
            max_even_sum = max(max_even_sum, j);
        }
    }

    cout << max_even_sum / 2 << endl;
    return 0;
}