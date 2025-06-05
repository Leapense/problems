#include <iostream>
#include <cstdint>

using namespace std;

static bool findSmallestBase(int64_t n, int64_t &result)
{
    if (n < 3) {
        return false;
    }

    if (n == 3) {
        result = 4;
        return true;
    }

    int64_t m = n - 3;

    if (m < 4) {
        return false;
    }

    if ((m % 4) == 0) {
        result = 4;
        return true;
    }

    for (int64_t d = 5; d * d <= m; ++d) {
        if ((m % d) == 0) {
            result = d;
            return true;
        }
    }

    int64_t best = m;

    if (((m % 2) == 0) && ((m / 2) >= 4)) {
        if ((m / 2) < best) {
            best = (m / 2);
        }
    }

    if (((m % 3) == 0) && ((m / 3) >= 4)) {
        if ((m / 3) < best) {
            best = (m / 3);
        }
    }

    result = best;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n;

    while (true)
    {
        if (!(cin >> n)) {
            break;
        }

        if (n == 0) {
            break;
        }

        int64_t base = 0;
        bool ok = findSmallestBase(n, base);

        if (ok) {
            cout << base << "\n";
        } else {
            cout << "No such base\n";
        }
    }

    return 0;
}
