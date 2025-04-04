#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int k;
    cin >> k;

    if (k == 1) {
        cout << 0 << "\n";
    } else {
        long long result = (k % 2 == 0) ? (1LL << k) : -(1LL << k);
        cout << result << "\n";
    }

    return 0;
}
