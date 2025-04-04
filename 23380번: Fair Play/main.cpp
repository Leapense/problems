#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()(((long long)p.first) ^ (((long long)p.second) << 32));
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 != 0) {
        cout << "impossible\n";
        return 0;
    }

    vector<pair<int, int>> coworkers(n);
    long long totalB = 0, totalP = 0;
    for (int i = 0; i < n; i++) {
        cin >> coworkers[i].first >> coworkers[i].second;
        totalB += coworkers[i].first;
        totalP += coworkers[i].second;
    }

    int teams = n / 2;

    if (totalB % teams != 0 || totalP % teams != 0) {
        cout << "impossible\n";
        return 0;
    }

    int targetB = totalB / teams;
    int targetP = totalP / teams;

    unordered_map<pair<int, int>, int, PairHash> freq;
    for (auto &p : coworkers) {
        freq[p]++;
    }

    for (auto &p : coworkers) {
        if (freq[{p.first, p.second}] == 0) continue;

        pair<int, int> complement = {targetB - p.first, targetP - p.second};

        int countCurrent = freq[{p.first, p.second}];
        if (freq[complement] != countCurrent) {
            cout << "impossible\n";
            return 0;
        }

        freq[{p.first, p.second}] = 0;
        freq[complement] = 0;
    }

    cout << "possible\n";
    return 0;
}
