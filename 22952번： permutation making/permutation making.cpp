#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int mid = (N + 1) / 2;

    vector<int> high, low;

    for (int i = mid; i <= N; i++) high.push_back(i);
    for (int i = 1; i < mid; i++) low.push_back(i);

    sort(high.begin(), high.end(), greater<int>());
    sort(low.begin(), low.end());

    vector<int> A;
    int h = 0, l = 0;

    while (h < high.size() || l < low.size()) {
        if (h < high.size()) A.push_back(high[h++]);
        if (l < low.size()) A.push_back(low[l++]);
    }

    if (A.size() > N) A.resize(N);
    for (int i = 0; i < A.size(); i++) cout << A[i] << (i < A.size() - 1 ? " " : "\n");

    return 0;
}