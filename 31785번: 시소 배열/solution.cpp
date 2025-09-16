#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    if (!(cin >> Q)) return 0;

    vector<int> L;
    deque<int> R;
    long long sumL = 0, sumR = 0;

    auto rebalance = [&]() {
        long long N = (long long)L.size() + (long long)R.size();
        long long wantL = N / 2;
        long long wantR = N - wantL;

        while ((long long)R.size() > wantR) {
            int v = R.front(); R.pop_front();
            sumR -= v;
            L.push_back(v);
            sumL += v;
        }

        while ((long long)R.size() < wantR) {
            int v = L.back(); L.pop_back();
            sumL -= v;
            R.push_front(v);
            sumR += v;
        }
    };
    auto delete_front_half = [&]() {
        cout << sumL << '\n';
        sumL = 0;
        L.clear();
        long long M = (long long)R.size();
        long long needL = M / 2;
        while ((long long)L.size() < needL) {
            int v = R.front(); R.pop_front();
            sumR -= v;
            L.push_back(v);
            sumL += v;
        }
    };

    auto delete_back_half = [&]() {
        cout << sumR << '\n';
        sumR = 0;
        R.clear();
        long long M = (long long)L.size();
        long long needR = M - (M / 2);
        while ((long long)R.size() < needR) {
            int v = L.back(); L.pop_back();
            sumL -= v;
            R.push_front(v);
            sumR += v;
        }
    };

    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            R.push_back(x);
            sumR += x;
            rebalance();
        } else {
            if (sumL <= sumR) delete_front_half();
            else delete_back_half();
        }
    }

    bool first = true;
    for (int v : L) {
        if (!first) cout << ' ';
        cout << v;
        first = false;
    }

    for (int v : R) {
        if (!first) cout << ' ';
        cout << v;
        first = false;
    }

    if (!first) cout << '\n';
    else cout << '\n';
    return 0;
}