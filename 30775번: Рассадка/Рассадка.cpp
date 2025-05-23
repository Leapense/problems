#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int M, K;
    cin >> M >> K;

    vector<long long> ni(K);
    for (int i = 0; i < K; ++i) {
        cin >> ni[i];
    }

    long long total = accumulate(ni.begin(), ni.end(), 0LL);

    // To calculate the maximum number of participants in one room
    long long max_in_one_room = (total + M - 1) / M;  // equivalent to ceil(total / M)

    cout << max_in_one_room << endl;
    return 0;
}