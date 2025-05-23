#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;

    vector<int> positive, negative;

    int x;

    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x > 0) {
            positive.push_back(x);
        } else if (x < 0) {
            negative.push_back(x);
        }
    }

    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end());

    ll total = 0;
    for (int i = 0; i < positive.size(); i += K) {
        total += 2LL * positive[i];
    }

    for (int i = 0; i < negative.size(); i += K) {
        total += 2LL * abs((ll)negative[i]);
    }

    cout << total;

    return 0;
}