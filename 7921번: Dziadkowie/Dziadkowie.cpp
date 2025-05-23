#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    const int X = 69; // NICE NUMBER

    for (int i = 1; i <= T; i++) {
        long long N;
        cin >> N;

        double G_double = (3.0 / 7.0) * N;
        long long G = round(G_double);

        if (i % X == 0) {
            cout << "AMPPZ 2010\n";
        } else {
            cout << G << '\n';
        }
    }

    return 0;
}