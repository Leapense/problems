#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    cin >> N;

    if (N == 0) {
        cout << "NO";
        return 0;
    }

    while (N > 0) {
        ll remainder = N % 3;
        if (remainder >= 2) {
            cout << "NO";
            return 0;
        }

        N /= 3;
    }

    cout << "YES";

    return 0;
}