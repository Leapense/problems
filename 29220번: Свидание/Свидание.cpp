#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    long long k;
    int n;
    cin >> k >> n;

    vector<int> bills(n);

    for (int i = 0; i < n; ++i) {
        cin >> bills[i];
    }

    long long total_sum = accumulate(bills.begin(), bills.end(), 0LL);

    bool pays_for_bella = false;

    for (int i = 0; i < n; ++i) {
        if (total_sum - bills[i] >= k) {
            pays_for_bella = true;
            break;
        }
    }

    if (pays_for_bella) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}