#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> min_mileage;

    for (int i = 0; i < n; ++i) {
        int P, L;
        cin >> P >> L;
        vector<int> mileages(P);
        for (int j = 0; j < P; ++j) {
            cin >> mileages[j];
        }

        sort(mileages.begin(), mileages.end(), greater<int>());
        int required = (P >= L) ? mileages[L - 1] : 1;
        min_mileage.push_back(required);
    }

    sort(min_mileage.begin(), min_mileage.end());

    int count = 0;
    for (int mileage : min_mileage) {
        if (m >= mileage) {
            m -= mileage;
            count++;
        } else {
            break;
        }
    }

    cout << count << "\n";

    return 0;
}