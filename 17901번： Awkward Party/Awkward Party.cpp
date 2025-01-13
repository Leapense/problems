#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<long long> x(n);
    for (auto &num : x) cin >> num;
    
    unordered_map<long long, int> last_pos;
    int awkwardness = n;

    for (int i = 0; i < n; i++) {
        if (last_pos.find(x[i]) != last_pos.end()) {
            awkwardness = min(awkwardness, i - last_pos[x[i]]);
        }

        last_pos[x[i]] = i;
    }

    cout << awkwardness << "\n";
    
    return 0;
}