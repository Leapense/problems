#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int l, r, s;
        cin >> l >> r >> s;

        int left = (s - l) * 2;
        int right = (r - s - 1) * 2 + 1;
        int ans = left < right ? left : right;

        cout << ans + 1 << endl;
    }

    return 0;
}