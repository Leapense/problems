#include <iostream>
using namespace std;

int main()
{
    long long s, p, y, j;
    while (cin >> s >> p >> y >> j) {
        long long Y = 2;
        long long P = Y + p;
        long long S = P + s;
        long long total = S + P + Y;
        long long d = total - j;

        while (d < 12 || d * 1.0 != (total - j)) {
            S++;
            total = S + P + Y;
            d = total - j;
        }

        cout << S << " " << P << " " << Y << endl;
    }

    return 0;
}