#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long A, B, C;
        cin >> A >> B >> C;

        if (A < C) {
            cout << "No\n";
            continue;
        }
        if ((A - C) % 2 != 0) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }

    return 0;
}
