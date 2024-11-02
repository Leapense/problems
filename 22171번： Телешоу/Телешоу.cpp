#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;

        double E = ((n - 1.0) * (n + 4.0)) / 4.0;
        cout << fixed << setprecision(7) << E << endl;
    }

    return 0;
}