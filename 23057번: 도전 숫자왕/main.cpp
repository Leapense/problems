#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    vector<ll> subsetSums;
    subsetSums.push_back(0);
    for (int card : cards) {
        int size = subsetSums.size();
        for (int i = 0; i < size; i++) {
            subsetSums.push_back(subsetSums[i] + card);
        }
    }

    sort(subsetSums.begin(), subsetSums.end());
    subsetSums.erase(unique(subsetSums.begin(), subsetSums.end()), subsetSums.end());

    ll M = 0;
    for (int card : cards) {
        M += card;
    }

    ll missingCount = 0;
    ll prev = 0;
    for (ll s : subsetSums) {
        if (s - prev > 1) {
            missingCount += (s - prev - 1);
        }
        prev = s;
    }

    cout << missingCount << "\n";
    return 0;
}
