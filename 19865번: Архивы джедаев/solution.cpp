#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long x;
    int m;
    if (!(cin >> x >> m)) return 0;
    const unsigned long long N = 1000000000000000000ULL;
    unsigned long long total = N - m;

    cout << "? 1" << endl;
    unsigned long long pivot;
    cin >> pivot;

    unsigned long long v_app;
    if (x >= pivot) {
        v_app = x - pivot + 1;
    } else {
        v_app = (N - pivot + 1) + x;
    }

    unsigned long long L = (v_app > (unsigned long long)m ? v_app - m : 1);
    unsigned long long R = (v_app <= total ? v_app : total);

    while (L <= R) {
        unsigned long long mid = (L + R) >> 1;
        cout << "? " << mid << endl;
        unsigned long long val;
        cin >> val;
        if (val == x) {
            cout << "! " << mid << endl;
            return 0;
        }
        if (val < x) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }

    cout << "! -1" << endl;
    return 0;
}