#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    k = a.size();

    vector<char> a_present(n + 1, 0);
    for (auto num : a) {
        if (num <= n) {
            a_present[num] = 1;
        }
    }

    vector<int> minimal_a;
    for (auto num : a) {
        if (a_present[num]) {
            minimal_a.push_back(num);

            for (long long m = 2LL * num; m <= n; m += num) {
                if (a_present[m]) {
                    a_present[m] = 0;
                }
            }
        }
    }

    vector<char> ballot_processed(n + 1, 0);
    for (auto num : minimal_a) {
        for (int m = num; m <= n; m += num) {
            ballot_processed[m] = 1;
        }
    }

    int unprocessed = 0;
    for (int m = 1; m <= n; ++m) {
        if (!ballot_processed[m]) {
            unprocessed++;
        }
    }

    cout << unprocessed << "\n";

    return 0;
}