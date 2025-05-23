#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<long long> x(N);
    long long total = 0;
    long long max_x = 0;

    for (int i = 0; i < N; i++) {
        cin >> x[i];
        total += x[i];
        if (x[i] > max_x) max_x = x[i];
    }
    double final_amount = max_x + (double)(total - max_x) / 2.0;

    cout << fixed << setprecision(10) << final_amount << endl;

    return 0;
}