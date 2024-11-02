#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Wire {
    ll di;
    ll bi;
    ll diff;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Wire> positive_wires;
    vector<Wire> negative_wires;

    ll total_diff = 0;
    for (int i = 0; i < n; ++i) {
        ll di, bi;
        cin >> di >> bi;
        ll diff = di - bi;

        if (diff >= 0) {
            total_diff += diff;
            positive_wires.push_back({di, bi, diff});
        } else {
            negative_wires.push_back({di, bi, diff});
        }
    }

    // 음수 diff를 가진 전선들을 diff가 큰 순서대로 정렬
    sort(negative_wires.begin(), negative_wires.end(), [](const Wire& a, const Wire& b) {
        return a.diff > b.diff; // diff는 음수이므로 큰 것부터 (즉, 덜 음수인 것부터)
    });

    int count = positive_wires.size();

    for (const auto& wire : negative_wires) {
        total_diff += wire.diff; // wire.diff는 음수
        if (total_diff >= 0) {
            ++count;
        } else {
            break;
        }
    }

    cout << count << '\n';

    return 0;
}